//===================================================================
// File: LED_Dim.ino
//
// Description:
// - Sketch for controlling LED brightness using PWM.
//
// Pinout:
//
// GND <--- LED <--- 220Ω <--- D3
//
// This code is in the public domain.
//===================================================================

// Save LED pin number as variable
int ledPin = 3; // must be PWM (~) pin
  
void setup() {
  // Initialise LED pin as OUTPUT
  pinMode(ledPin, OUTPUT);
}
  
void loop() {
  // Use for loop to increase brightness
  for (int i = 0; i < 256; i++) {
    analogWrite(ledPin, i);
    delay(10);
  }
}