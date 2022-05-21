#include <BleKeyboard.h>

#define LED_BUILTIN      2
#define AUDIO_IN_PIN      35
int db_val = 0;
BleKeyboard bleKeyboard;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(AUDIO_IN_PIN, INPUT);
  Serial.begin(115200);

  // initialize control over the keyboard:
  bleKeyboard.begin();
}

// the loop function runs over and over again forever
void loop() {
  static bool last_was_high = false;
  db_val    =  digitalRead(AUDIO_IN_PIN);  // Analog Digital converter value

  if (db_val && !last_was_high){
    bleKeyboard.press(KEY_DOWN_ARROW);
    delay(100);
  } else if (db_val != last_was_high) {
    bleKeyboard.releaseAll();
  }

  last_was_high = db_val;

//  delay(10);
////  if (db_val == HIGH)
////  {
////      digitalWrite(LED_BUILTIN, HIGH);
////      Serial.write("Switching ON");
////      bleKeyboard.press(KEY_DOWN_ARROW);
////      delay(100);
////      bleKeyboard.release(KEY_DOWN_ARROW);
////      
////  } 
////  else
////  {
////  
////    digitalWrite(LED_BUILTIN, LOW);
////      Serial.write("Switching OFF");
////    while (db_val != HIGH)
////    {
////      //Serial.write(" OFF");
////
////      db_val    =  digitalRead(AUDIO_IN_PIN);  // Analog Digital converter value
////    }
////
////  }
////      //delay(100);

 }
