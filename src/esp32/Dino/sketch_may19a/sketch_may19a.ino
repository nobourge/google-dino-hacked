void setup() {
  Serial.begin(19200);
  // put your setup code here, to run once:

}

void loop() {
  Serial.println(millis() % 100);
  // put your main code here, to run repeatedly:
  delay(1);
}
