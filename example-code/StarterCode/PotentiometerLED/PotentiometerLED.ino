//================================================
// PotentiometerLED.ino
//
// Example of how to control an LED using
// an Arduino and a potentiometer
//
// Circuit:
// Arduino Pin 2 -> 200Ohm Resistor -> LED -> GND
// 
// 5V -> Potentiometer -> GND
//            |
//            V
//      Arduino Pin A0
//================================================

// Declare pin numbers
int ledPin = 2;
int potPin = A0;

void setup() {
  // Initialize ledPin as output
  pinMode(ledPin, OUTPUT);

  // Initialize potPin as input
  pinMode(potPin, INPUT);
}

void loop() {
  // Get potentiometer value
  // returns value between 0-1023
  int readValue = analogRead(potPin);

  // Scale value to be between 0-255
  int scaledValue = readValue * (255. / 1023.);

  // Set LED brightness
  analogWrite(ledPin, scaledValue);
}