#include <BleKeyboard.h>

#define MAIN_PHOTORESISTOR_PIN 15

#define DINO_IN_THE_AIR_TIME_MS 500
#define DINO_MOVING_AVG_THRESHOLD 30

struct Jump {
  unsigned long takeoff_time;
  unsigned long landing_time;
};

class LiveFastChangeDetector;


// signal_filtration.h
class SignalFiltration;

// dino.h
BleKeyboard bleKeyboard;
LiveFastChangeDetector *obsticle_start_detector_light_theme;
LiveFastChangeDetector *obsticle_end_detector_light_theme;
LiveFastChangeDetector *obsticle_lagged_start_detector_light_theme;

ArduinoQueue<Jump> future_jumps(20);

void UpdateMovingAveragesTask(void * pvParameters);
void DinoCactiTrackerTask(void * pvParameters);
void SetupMovingAverages();

//dino.signal

class SignalFiltration {
public:
  SignalFiltration() = default;
  virtual double GetValue() = 0;
  virtual void AddValue(double value) = 0;
};


class ExpMovingAverage: public SignalFiltration {
private:
  double speed_;
  double average_;

protected:
  void SetSpeed(double speed) {
    speed_ = speed;
  }

  void SetAverage(double new_avg) {
    average_ = new_avg;
  }

public:
  ExpMovingAverage(double average, double speed) : SignalFiltration(), average_{average}, speed_{speed} {}

  void AddValue(double value) override {
    average_ = value * speed_ + average_ * (1 - speed_);
  }

  double &GetSpeed() {
    return speed_;
  }

  double GetValue() override {
    return average_;
  }
};
 
class LiveFastChangeDetector {
private:
  ExpMovingAverage fast_moving_avg_;
  ExpMovingAverage slow_moving_avg_;

  double change_detection_threshold_;
  bool detect_rising_change_;
  bool detect_falling_change_;
  
public:
  LiveFastChangeDetector(double fast_moving_avg_speed, double slow_moving_avg_speed, double change_detection_threshold, bool detect_rising_change, bool detect_falling_change, double initial_value = 0) 
    : fast_moving_avg_(ExpMovingAverage(initial_value, fast_moving_avg_speed)), 
      slow_moving_avg_(ExpMovingAverage(initial_value, slow_moving_avg_speed)), 
      change_detection_threshold_{change_detection_threshold}, 
      detect_rising_change_{detect_rising_change},
      detect_falling_change_{detect_falling_change}
  {}

  void AddValue(double new_value) {
    fast_moving_avg_.AddValue(new_value);
    slow_moving_avg_.AddValue(new_value);
  }

  bool IsDetectingFastChange() {
    double change = fast_moving_avg->GetValue() - slow_moving_avg->GetValue();
    double absolute_change = -1
    if ((detect_rising_change_ && change > 0) || (detect_falling_change_ && change < 0)) {
      absolute_change = abs(change);
    }

    
    return change > 0 && change > change_detection_threshold_;
  }
}

void setup() {
  Serial.begin(115200);
  bleKeyboard.begin();

  SetupMovingAverages();
  
  xTaskCreate(DinoCactiTrackerTask, "Dino cacti tracker task", 3000, NULL, 1, NULL);
  xTaskCreate(UpdateMovingAveragesTask, "Moving averages", 3000, NULL, 1, NULL);
  xTaskCreate(DinoControllerTask, "Dino controller", 3000, NULL, 1, NULL);
}

void SetupMovingAverages() {
  obsticle_start_detector_light_theme = new LiveFastChangeDetector(0.4, 0.1, DINO_MOVING_AVG_THRESHOLD, true, false, analogRead(MAIN_PHOTORESISTOR_PIN));
  obsticle_lagged_start_detector_light_theme = new LiveFastChangeDetector(0.4, 0.1, DINO_MOVING_AVG_THRESHOLD, true, false, analogRead(MAIN_PHOTORESISTOR_PIN));
//  obsticle_end_detector_light_theme = new LiveFastChangeDetector(0.4, 0.1, DINO_MOVING_AVG_THRESHOLD, false, true, analogRead(MAIN_PHOTORESISTOR_PIN));
}

void UpdateMovingAveragesTask(void * pvParameters) {
  for (;;){
    int analog_read_val = analogRead(MAIN_PHOTORESISTOR_PIN);
    slow_moving_avg->AddValue(analog_read_val);
    fast_moving_avg->AddValue(analog_read_val);
    vTaskDelay(10);
  }
}

void DinoControllerTask(void * pvParameters) {
  bool last_was_key_up = false;
  bleKeyboard.press(KEY_DOWN_ARROW);
  for (;;) {
  
    while (!bleKeyboard.isConnected()) {
      vTaskDelay(5000 / portTICK_PERIOD_MS);
      Serial.println("Waiting for bluetooth connection...");
    }


    
    if (!future_jumps.isEmpty() && !last_was_key_up) {
      Serial.print(millis()); Serial.print(": ");
      Serial.println("Jumping");
      bleKeyboard.releaseAll();
      bleKeyboard.write(KEY_UP_ARROW);
      vTaskDelay(DINO_IN_THE_AIR_TIME_MS / portTICK_PERIOD_MS);
      bleKeyboard.press(KEY_DOWN_ARROW);
    }

    vTaskDelay(10);
  }
}

void DinoCactiTrackerTask(void * pvParameters) {
  bool last_was_key_up = false;
  unsigned int last_detected_cactus_time = 0;
  for (;;){
    obsticle_lagged_start_detector_light_theme.
    cactus_approaching = fast_moving_avg->GetValue() - slow_moving_avg->GetValue() < DINO_MOVING_AVG_THRESHOLD;
    Serial.print(analogRead(MAIN_PHOTORESISTOR_PIN) / 50);
    Serial.print(",");
    Serial.print(fast_moving_avg->GetValue() / 50);
    Serial.print(",");
    Serial.print(slow_moving_avg->GetValue() / 50);
    Serial.print(",");
    Serial.println(cactus_approaching);
    vTaskDelay(10);
  }
}

void loop() {
}
