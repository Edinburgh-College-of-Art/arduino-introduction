//================================================
// HelloWorld.ino
//
// Print "Hello World" to serial monitor
//================================================

void setup() {
  // Initialize serial monitor with baud of 9600
  // Make sure serial console uses same baud rate
  Serial.begin(9600);
}

void loop() {
  // Print "Hello World" with delay of 1 second
  Serial.print("Hello World");
  delay(1000);

  // Print empty new line
  Serial.println();
}