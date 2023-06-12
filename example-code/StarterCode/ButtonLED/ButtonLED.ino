//================================================
// ButtonLED.ino
//
// Example of how to control an LED using
// an Arduino and a push button
//
// Circuit:
// Arduino Pin 2 -> 200Ohm Resistor -> LED -> GND
// Arduino Pin 3 -> Button -> GND
//================================================

// Declare pin numbers
int ledPin = 2;
int buttonPin = 3;

void setup() {
  // Initialize ledPin as output
  pinMode(ledPin, OUTPUT);

  // Initialize buttonPin as input
  // Make use of onboard pullup resistor
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // check if button is pressed
  // if pressed, turn on LED
  // otherwise, turn off LED
  if (digitalRead(buttonPin) == LOW) 
    digitalWrite(ledPin, HIGH); //ON
  else 
    digitalWrite(ledPin, LOW);  // OFF 
}