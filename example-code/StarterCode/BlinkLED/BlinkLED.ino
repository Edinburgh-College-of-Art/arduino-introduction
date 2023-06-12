//================================================
// BlinkLED.ino
//
// Example of how to blink an LED on/off using
// an Arduino
//
// Circuit:
// Arduino Pin 2 -> 200Ohm Resistor -> LED -> GND
//================================================

// Declare pin number
int ledPin = 2;

// Set delay time
int delayInMilliseconds = 500;

void setup() {
  // Initialize pin 2 as output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Turn on LED and wait
  digitalWrite(ledPin, HIGH);
  delay(delayInMilliseconds);

  // Turn off LED and wait
  digitalWrite(ledPin, LOW);
  delay(delayInMilliseconds);
}