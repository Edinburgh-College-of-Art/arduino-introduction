//===================================================================
// File: ActiveBuzzer_Example.ino
//
// Description:
// - Sketch for using an active buzzer.
// - 1 second on, 1 second off.
//
// Pinout:
//
// GND <--- Buzzer <--- D3
//
// This code is in the public domain.
//===================================================================

int buzzerPin = 3;  // Connect buzzer to pin 3

void setup() {
  pinMode(buzzerPin, OUTPUT);  // initialize buzzer as output
}

void loop() {
  digitalWrite(buzzerPin, HIGH);  // Turn on the buzzer
  delay(1000);                    // Wait for 1 second
  digitalWrite(buzzerPin, LOW);   // Turn off the buzzer
  delay(1000);                    // Wait for 1 second
}