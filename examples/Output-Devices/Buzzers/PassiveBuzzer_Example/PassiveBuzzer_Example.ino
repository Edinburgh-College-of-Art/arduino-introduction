int buzzerPin = 3;  // Connect buzzer to pin 3 (~)

void setup() {
  pinMode(buzzerPin, OUTPUT);  // initialise buzzer as an output
}

void loop() {
  tone(buzzerPin, 1000);  // Play 1000 Hz tone
  delay(1000);            // Wait for 1 second
  noTone(buzzerPin);      // Stop the tone
  delay(1000);            // Wait for 1 second
}