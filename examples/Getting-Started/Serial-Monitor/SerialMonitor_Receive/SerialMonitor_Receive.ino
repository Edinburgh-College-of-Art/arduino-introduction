void setup() {
  // Start serial monitor
  Serial.begin(9600);
}
​
void loop() {
  // Are there any new messages in the buffer?
  if (Serial.available() > 0) {
    // Read incoming message
    int msg = Serial.parseInt();
    
    // Print incoming message
    Serial.print("Message Received: ");
    Serial.println(msg);
  }
}