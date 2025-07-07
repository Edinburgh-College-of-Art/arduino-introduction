//===================================================================
// File: Potentiometer_BasicRead.ino
//
// Description:
// - Use analogRead() to get potentiometer value.
//
// Pinout:
//
// GND <--- Potentiometer <--- 5V
//                |
//                |
//               A0
//
// This code is in the public domain.
//===================================================================

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