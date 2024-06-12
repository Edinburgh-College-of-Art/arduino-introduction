// Save LED pin number as variable
int ledPin = 3;
  
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