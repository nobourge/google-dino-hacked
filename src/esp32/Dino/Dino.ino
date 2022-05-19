#include <BleKeyboard.h>

#define DEBUG 0

#define LEADING_PHOTORESISTOR_PIN       15
#define TRAILING_PHOTORESISTOR_PIN      4
#define BG_PHOTORESISTOR_PIN            2

#define MOVING_AVG_SPEED                0.3
#define SLOW_MOVING_AVG_SPEED           0.3
#define INIT_M_AVG_FOR_PIN(pin)         ExpMovingAverage(analogRead(pin), MOVING_AVG_SPEED)
#define INIT_SLOW_M_AVG_FOR_PIN(pin)    ExpMovingAverage(analogRead(pin), SLOW_MOVING_AVG_SPEED)

#define CACTUS_DEBOUNCING_GAP_MS        100
#define BRIGHTNESS_DELTA_THRESHOLD      25


bool isInJumpState = false;
BleKeyboard bleKeyboard;

class ExpMovingAverage {  // exponential more reactive
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
  ExpMovingAverage(double average, double speed) : average_{average}, speed_{speed} {}

  void AddValue(double value) { // to curve
    average_ = value * speed_ + average_ * (1 - speed_);
  }

  double &GetSpeed() {  
    return speed_;
  }

  double GetValue() {
    return average_;
  }
};


class Timer {
  // should've used the ESP32 timer api, but this does the job :-)
private:
  unsigned long times_out_at_ = 0;
  unsigned long delay_ms_;
  bool stopped_ = false;
  

  static unsigned long GetTimeIn(unsigned long ms_interval) {
    return millis() + ms_interval;  // millis() = ms time from start
  }
  
public:
  Timer(unsigned long delay_ms) : delay_ms_{delay_ms} {
    Start();
  }

  void SetTimeout(unsigned long ms) {
    delay_ms_ = ms;
    times_out_at_ = GetTimeIn(ms);
  }
  
  bool IsOver() {
    return times_out_at_ <= millis();
  }

  

  void Stop() {
    delay_ms_ = times_out_at_ - millis();
    stopped_ = true;
  }

  void Start() {
    times_out_at_ = GetTimeIn(delay_ms_);
    stopped_ = false;
  }
};

/*
void DinoCactiTrackerTask(void * pvParameters) {
  bool last_was_key_up = false;
  unsigned int last_detected_cactus_time = 0;
  for (;;){
    obsticle_lagged_start_detector_light_theme.
    cactus_lagged_start_detector_light_theme.IsDetectingFastChange()
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
*/
void setup() {
  Serial.begin(115200); // Arduino - computer communication
  bleKeyboard.begin();
  #if DEBUG == 1
    Serial.println("Sending Ctrl+Maj+L...");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_MAJ);
    bleKeyboard.press(KEY_L);
    delay(100);
    bleKeyboard.releaseAll();

    Serial.print(v1); Serial.print(",");
    Serial.println(v2);
  #endif
}

void loop() {
  static ExpMovingAverage leading_sensor_brightness_avg         =       INIT_M_AVG_FOR_PIN(LEADING_PHOTORESISTOR_PIN);
  static ExpMovingAverage trailing_sensor_brightness_avg        =       INIT_M_AVG_FOR_PIN(TRAILING_PHOTORESISTOR_PIN);
  static ExpMovingAverage bg_sensor_brightness_avg              =       INIT_M_AVG_FOR_PIN(BG_PHOTORESISTOR_PIN);

  static ExpMovingAverage slow_leading_sensor_brightness_avg    =       INIT_SLOW_M_AVG_FOR_PIN(LEADING_PHOTORESISTOR_PIN);
  static ExpMovingAverage slow_trailing_sensor_brightness_avg   =       INIT_SLOW_M_AVG_FOR_PIN(TRAILING_PHOTORESISTOR_PIN);
  static ExpMovingAverage slow_bg_sensor_brightness_avg         =       INIT_SLOW_M_AVG_FOR_PIN(BG_PHOTORESISTOR_PIN);

  static bool prev_leading_sensor_cactus_detected                            =       false;
  static bool prev_trailing_sensor_cactus_detected                           =       false;

  static unsigned long leading_sensor_first_detected_cactus_at_ms     =     0;
  static unsigned long leading_sensor_stopped_detecting_cactus_at_ms  =     0;

  static unsigned long trailing_sensor_first_detected_cactus_at_ms    =     0;
  static unsigned long trailing_sensor_stopped_detecting_cactus_at_ms =     0;
  

  if (millis() % 3) {

    auto leading_read    =  analogRead(LEADING_PHOTORESISTOR_PIN);  // Analog Digital converter value
    auto trailing_read  =  analogRead(TRAILING_PHOTORESISTOR_PIN);
    auto bg_read      =  analogRead(BG_PHOTORESISTOR_PIN);
    
    leading_sensor_brightness_avg.AddValue(leading_read);
    trailing_sensor_brightness_avg.AddValue(trailing_read);
    bg_sensor_brightness_avg.AddValue(bg_read);

    slow_leading_sensor_brightness_avg.AddValue(leading_read);
    slow_trailing_sensor_brightness_avg.AddValue(trailing_read);
    slow_bg_sensor_brightness_avg.AddValue(bg_read);
  }

  bool leading_sensor_detects_cactus = (
    millis() - leading_sensor_stopped_detecting_cactus_at_ms > CACTUS_DEBOUNCING_GAP_MS
    &&
    abs(leading_sensor_brightness_avg.GetValue() - slow_leading_sensor_brightness_avg.GetValue()) > BRIGHTNESS_DELTA_THRESHOLD
  );

  bool trailing_sensor_detects_cactus = (
    millis() - trailing_sensor_stopped_detecting_cactus_at_ms > CACTUS_DEBOUNCING_GAP_MS
    &&
    abs(trailing_sensor_brightness_avg.GetValue() - slow_trailing_sensor_brightness_avg.GetValue()) > BRIGHTNESS_DELTA_THRESHOLD
  );

  if (leading_sensor_detects_cactus != prev_leading_sensor_cactus_detected) {
    if (leading_sensor_detects_cactus) {
      leading_sensor_first_detected_cactus_at_ms = millis();
    } else {
      
    }
  }

  Serial.print(analogRead(LEADING_PHOTORESISTOR_PIN) / 50);
    // Serial.print(",");
    // Serial.print(fast_moving_avg->GetValue() / 50);
    // Serial.print(",");
    // Serial.print(slow_moving_avg->GetValue() / 50);
    // Serial.print(",");
    // Serial.println(cactus_approaching);

  
}
