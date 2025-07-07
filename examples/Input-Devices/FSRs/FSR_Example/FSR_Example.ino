//===================================================================
// File: FSR_Example.ino
//
// Description:
// - Read voltage level from FSR circuit.
// - Results are printed to the serial monitor
//
// Pinout:
//
// FSR <--- 5V
//  |
//  |-----> A0
//  |    
//   -----> 10kΩ ---> GND

// This code is in the public domain.
//===================================================================

int fsrPin = A0;  // connect FSR to pin A0

void setup() {
  Serial.begin(9600);  // start serial comms
}

void loop() {
  int fsrValue = analogRead(fsrPin);  // read FSR pin
  Serial.println(fsrValue);           // print result to serial monitor

  delay(100);  // short delay
}
