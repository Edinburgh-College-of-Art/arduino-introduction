//=============================================================
// Potentiometer_BasicRead.ino
//
// - Use analogRead() to get potentiometer value.
// - Send data to Serial Monitor.
//=============================================================

// Store pin number
int potPin = A0;
  
void setup() {
  // Start serial monitor
  Serial.begin(9600);

  // We dont need to use pinMode()!
  // Arduino assumes that we are using analog inputs as INPUT by default
}
  
void loop() {
  // Store potentiometer value
  int potValue = analogRead(potPin);

  Serial.println(potValue);
}