//================================================
// PassiveBuzzer.ino
//
// Arduino code for passive buzzer
//
// Circuit:
// Arduino pin 8 -> buzzer -> GND
//================================================

// set pin
int buzzerPin = 8;

void setup() {
  // set up buzzer pin as output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // output 440Hz tone and wait
  tone(buzzerPin, 440);
  delay(1000);
  
  // turn off and wait
  noTone(buzzerPin);
  delay(1000);
}