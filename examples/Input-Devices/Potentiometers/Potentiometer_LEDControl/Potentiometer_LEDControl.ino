//=============================================================
// Potentiometer_LEDControl.ino
//
// - Use analogRead() to get potentiometer value.
// - Send data to Serial Monitor.
// - Use potentiometer value to adjust LED brightness.
//=============================================================

// Pins
int potPin = A0;
int ledPin = 6;  // must be PWM (~) pin

void setup() {
  // Start serial monitor
  Serial.begin(9600);

  // Initialize LED pin as OUTPUT
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Store potentiometer value
  int potValue = analogRead(potPin);
  Serial.println(potValue);  // Send to Serial Monitor

  // analogRead() returns value between 0-1023
  // We need a value of 0-255 for analogWrite()
  // This function scales the potValue to the correct range
  int brightness = map(potValue, 0, 1023, 0, 255);

  // Adjust LED brightness using analogWrite()
  analogWrite(ledPin, brightness);
}