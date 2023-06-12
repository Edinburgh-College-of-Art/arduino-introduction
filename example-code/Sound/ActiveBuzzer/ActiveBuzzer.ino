//================================================
// ActiveBuzzer.ino
//
// Arduino code for active buzzer
//
// Circuit:
// Arduino pin 8 -> buzzer -> GND
//================================================

// set pin number
int buzzer = 2;

void setup() {
  //init the buzzer pin as an output
  pinMode(buzzer, OUTPUT);  
}

void loop() {
  // turn on and wait
  digitalWrite(buzzer, HIGH);
  delay(500);
  
  // turn off and wait
  digitalWrite(buzzer, LOW);
  delay(500);
}