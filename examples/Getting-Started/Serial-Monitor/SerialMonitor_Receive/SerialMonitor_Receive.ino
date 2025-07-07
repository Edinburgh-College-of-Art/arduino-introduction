//======================================================================
// File: SerialMonitor_Receive.ino
//
// Description:
// - Run this code, open the serial monitor and send an integer message.
// - Arduino will listen for incoming messages from the serial monitor.
// - Incoming messages will be converted to an integer and printed to 
//   serial monitor.
//
// This code is in the public domain.
//======================================================================

void setup() {
  // Start serial monitor
  Serial.begin(9600);
}

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