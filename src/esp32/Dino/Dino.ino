#include <BleKeyboard.h>
#include <ArduinoQueue.h>

#define MAIN_PHOTORESISTOR_PIN 15
#define LAGGED_PHOTORESISTOR_PIN 4
#define THEME_DETECOR_PIN 2

#define DINO_IN_THE_AIR_TIME_MS 400
#define DINO_MOVING_AVG_THRESHOLD 30

#define EXTRA_JUMP_TIME_MS 160

#define PHOTORESISTORS_DISTANCE_TO_DINO_DISTANCE_RATIO 0.5

#define DAY_THEME_THRESHOLD 400

struct Jump
{
  unsigned long takeoff_time;
  unsigned long landing_time;
};

class LiveFastChangeDetector;

class SignalFiltration;

class ThemeDetector;

// dino.h
BleKeyboard bleKeyboard;
LiveFastChangeDetector *cactus_start_detector_light_theme;
LiveFastChangeDetector *cactus_start_detector_dark_theme;

LiveFastChangeDetector *cactus_lagged_start_detector_light_theme;
LiveFastChangeDetector *cactus_lagged_start_detector_dark_theme;

LiveFastChangeDetector *cactus_end_detector_light_theme;
LiveFastChangeDetector *cactus_end_detector_dark_theme;

ThemeDetector *theme_detector;


ArduinoQueue<Jump> future_jumps(20);

void UpdateMovingAveragesTask(void *pvParameters);
void DinoCactiTrackerTask(void *pvParameters);
void SetupMovingAverages();

// dino.signal

class SignalFiltration
{
public:
  SignalFiltration() = default;
  virtual double GetValue() = 0;
  virtual void SupplyValue(double value) = 0;
};

class Debouncer
{
private:
  unsigned int min_gap_ms_;
  unsigned long last_time_was_true_;
  bool last_debounced_value_;

public:
  Debouncer(unsigned int min_gap_ms) : min_gap_ms_{min_gap_ms}, last_time_was_true_{0}, last_debounced_value_{false} {}
  Debouncer &SupplyValue(bool value)
  {
    if (last_debounced_value_ != value)
    {
      if (value)
      {
        last_debounced_value_ = last_time_was_true_ + min_gap_ms_ < millis() ? value : last_debounced_value_;
      }
      else
      {
        last_debounced_value_ = value;
      }
    }
    return *this;
  }

  bool GetValue()
  {
    return last_debounced_value_;
  }
};

class ExpMovingAverage : public SignalFiltration
{
private:
  double speed_;
  double average_;

protected:
  void SetSpeed(double speed)
  {
    speed_ = speed;
  }

  void SetAverage(double new_avg)
  {
    average_ = new_avg;
  }

public:
  ExpMovingAverage(double average, double speed) : SignalFiltration(), average_{average}, speed_{speed} {}

  void SupplyValue(double value) override
  {
    average_ = value * speed_ + average_ * (1 - speed_);
  }

  double &GetSpeed()
  {
    return speed_;
  }

  double GetValue() override
  {
    return average_;
  }
};

class LiveFastChangeDetector
{
private:
  double change_detection_threshold_;
  bool detect_rising_change_;
  bool detect_falling_change_;

  Debouncer output_debouncer_;

public:
  ExpMovingAverage fast_moving_avg_;
  ExpMovingAverage slow_moving_avg_;
  LiveFastChangeDetector(double fast_moving_avg_speed, double slow_moving_avg_speed, double change_detection_threshold, bool detect_rising_change, bool detect_falling_change, double initial_value = 0, unsigned int debouncer_min_gap = 300)
      : fast_moving_avg_(ExpMovingAverage(initial_value, fast_moving_avg_speed)),
        slow_moving_avg_(ExpMovingAverage(initial_value, slow_moving_avg_speed)),
        change_detection_threshold_{change_detection_threshold},
        detect_rising_change_{detect_rising_change},
        detect_falling_change_{detect_falling_change},
        output_debouncer_{{debouncer_min_gap}}
  {
  }

  void SupplyValue(double new_value)
  {
    fast_moving_avg_.SupplyValue(new_value);
    slow_moving_avg_.SupplyValue(new_value);
  }

  bool IsDetectingFastChange()
  {
    double change = fast_moving_avg_.GetValue() - slow_moving_avg_.GetValue();
    double absolute_change = -1;
    if ((detect_rising_change_ && change > 0) || (detect_falling_change_ && change < 0))
    {
      absolute_change = abs(change);
    }

    return output_debouncer_
        .SupplyValue(absolute_change > 0 && absolute_change > change_detection_threshold_)
        .GetValue();
  }
};

class ThemeDetector
{
private:
  ExpMovingAverage bg_moving_avg_;
  LiveFastChangeDetector theme_change_detector_;
  bool last_theme_was_day_ = true;

  void UpdateLastTheme()
  {
    if (!IsCurrentThemeSwitching())
    {
      last_theme_was_day_ = IsCurrentThemeDay();
    }
  }

public:
  ThemeDetector(double current_bg_value) : bg_moving_avg_(ExpMovingAverage(current_bg_value, 0.2)), theme_change_detector_(0.2, 0.1, DINO_MOVING_AVG_THRESHOLD, true, true, current_bg_value)
  {
    UpdateLastTheme();
  }

  void SupplyBgValue(unsigned int value)
  {
    UpdateLastTheme();
    bg_moving_avg_.SupplyValue(value);
    theme_change_detector_.SupplyValue(value);
  }

  bool IsCurrentThemeSwitching()
  {
    theme_change_detector_.IsDetectingFastChange();
  }

  bool IsCurrentThemeDay()
  {
    return !IsCurrentThemeSwitching() && bg_moving_avg_.GetValue() > DAY_THEME_THRESHOLD;
  }

  bool IsCurrentThemeNight()
  {
    return !IsCurrentThemeDay();
  }

  bool WasPrevThemeDay()
  {
    return last_theme_was_day_;
  }
};

void setup()
{
  Serial.begin(115200);
  bleKeyboard.begin();

  SetupMovingAverages();

  xTaskCreate(DinoCactiTrackerTask, "Dino cacti tracker task", 3000, NULL, 1, NULL);
  xTaskCreate(UpdateMovingAveragesTask, "Moving averages", 3000, NULL, 1, NULL);
  xTaskCreate(DinoControllerTask, "Dino controller", 3000, NULL, 1, NULL);
}

void SetupMovingAverages()
{
  cactus_start_detector_light_theme = new LiveFastChangeDetector(0.3, 0.1, DINO_MOVING_AVG_THRESHOLD, false, true, analogRead(MAIN_PHOTORESISTOR_PIN));
  cactus_start_detector_dark_theme = new LiveFastChangeDetector(0.3, 0.1, DINO_MOVING_AVG_THRESHOLD, true, false, analogRead(MAIN_PHOTORESISTOR_PIN));

  cactus_lagged_start_detector_light_theme = new LiveFastChangeDetector(0.3, 0.1, DINO_MOVING_AVG_THRESHOLD, false, true, analogRead(LAGGED_PHOTORESISTOR_PIN));
  cactus_lagged_start_detector_dark_theme = new LiveFastChangeDetector(0.3, 0.1, DINO_MOVING_AVG_THRESHOLD, true, false, analogRead(LAGGED_PHOTORESISTOR_PIN));

  cactus_end_detector_light_theme = new LiveFastChangeDetector(0.3, 0.1, DINO_MOVING_AVG_THRESHOLD, true, false, analogRead(MAIN_PHOTORESISTOR_PIN));
  cactus_end_detector_dark_theme = new LiveFastChangeDetector(0.3, 0.1, DINO_MOVING_AVG_THRESHOLD, false, true, analogRead(MAIN_PHOTORESISTOR_PIN));

  theme_detector = new ThemeDetector(analogRead(THEME_DETECOR_PIN));

}

void UpdateMovingAveragesTask(void *pvParameters)
{
  for (;;)
  {
    int analog_read_val = analogRead(MAIN_PHOTORESISTOR_PIN);
    int lagged_analog_read_val = analogRead(LAGGED_PHOTORESISTOR_PIN);

    cactus_start_detector_light_theme->SupplyValue(analog_read_val);
    cactus_start_detector_dark_theme->SupplyValue(analog_read_val);

    cactus_end_detector_light_theme->SupplyValue(analog_read_val);
    cactus_lagged_start_detector_light_theme->SupplyValue(lagged_analog_read_val);

    cactus_end_detector_dark_theme->SupplyValue(analog_read_val);
    cactus_lagged_start_detector_dark_theme->SupplyValue(lagged_analog_read_val);

    theme_detector->SupplyBgValue(analogRead(THEME_DETECOR_PIN));

    vTaskDelay(10);
  }
}

void DinoControllerTask(void *pvParameters)
{
  bool last_was_key_up = false;
  bleKeyboard.press(KEY_DOWN_ARROW);
  for (;;)
  {

    // while (!bleKeyboard.isConnected())
    // {
    //   vTaskDelay(5000 / portTICK_PERIOD_MS);
    //   Serial.println("Waiting for bluetooth connection...");
    // }

    Serial.println(future_jumps.isEmpty() ? 0 : future_jumps.getHead().takeoff_time);

    if (!future_jumps.isEmpty() && future_jumps.getHead().takeoff_time <= millis())
    {
      bleKeyboard.releaseAll();
      bleKeyboard.write(KEY_UP_ARROW);
      auto current_jump = future_jumps.dequeue();
      unsigned int jump_time = constrain(current_jump.landing_time - current_jump.takeoff_time, 100, 200) + EXTRA_JUMP_TIME_MS;
      vTaskDelay(jump_time);
      bleKeyboard.press(KEY_DOWN_ARROW);
    }

    vTaskDelay(10);
  }
}

void DinoCactiTrackerTask(void *pvParameters)
{
  bool last_was_key_up = false;
  unsigned int last_cactus_start_time = 0;
  unsigned int last_cactus_end_time = 0;
  unsigned int last_lagged_cactus_start_time = 0;
  ExpMovingAverage *game_speed = nullptr;
  for (;;)
  {
    if (last_cactus_start_time == 0 && (
      (theme_detector->IsCurrentThemeDay() && cactus_start_detector_light_theme->IsDetectingFastChange()) 
      || 
      (theme_detector->IsCurrentThemeNight() && cactus_start_detector_dark_theme->IsDetectingFastChange()) 
      )
    )
    {
      last_cactus_start_time = millis();
    }

    if (last_cactus_end_time == 0 && (
      (theme_detector->IsCurrentThemeDay() && cactus_end_detector_light_theme->IsDetectingFastChange()) 
      || 
      (theme_detector->IsCurrentThemeNight() && cactus_end_detector_dark_theme->IsDetectingFastChange()) 
      )
    )
    {
      last_cactus_end_time = millis();
    }

    if (
        last_cactus_start_time != 0 &&
        last_lagged_cactus_start_time == 0 && 
        (
          (theme_detector->IsCurrentThemeDay() && cactus_lagged_start_detector_light_theme->IsDetectingFastChange()) 
          || 
          (theme_detector->IsCurrentThemeNight() && cactus_lagged_start_detector_dark_theme->IsDetectingFastChange())
        )
      )
    {
      last_lagged_cactus_start_time = millis();
    }

    if (
      last_cactus_end_time != 0 && 
      last_cactus_start_time != 0 && 
      last_lagged_cactus_start_time != 0)
    {
      int diff = last_lagged_cactus_start_time - last_cactus_start_time;
      int time_from_first_photoresistor_to_dino = constrain(diff * PHOTORESISTORS_DISTANCE_TO_DINO_DISTANCE_RATIO, 50, 1000);

      if (game_speed == nullptr)
      {
        game_speed = new ExpMovingAverage{time_from_first_photoresistor_to_dino, 0.1};
      }
      game_speed->SupplyValue((double)time_from_first_photoresistor_to_dino);

      Serial.println(game_speed->GetSpeed());

      future_jumps.enqueue(Jump{last_cactus_start_time + game_speed->GetSpeed() * PHOTORESISTORS_DISTANCE_TO_DINO_DISTANCE_RATIO, last_cactus_end_time + game_speed->GetSpeed() * PHOTORESISTORS_DISTANCE_TO_DINO_DISTANCE_RATIO});
      last_cactus_start_time = 0;
      last_cactus_end_time = 0;
      last_lagged_cactus_start_time = 0;
    }

    vTaskDelay(10);
  }
}

void loop()
{
}
