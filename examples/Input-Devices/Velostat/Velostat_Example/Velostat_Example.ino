//===================================================================
// File: Velostat_Example.ino
//
// Description:
// - Read voltage level from a Velostat sensor.
// - Results are printed to the serial monitor
//
// Pinout:
//
// Sensor <--- 5V
//  |
//  |-----> A0
//  |    
//   -----> 10kΩ ---> GND
//
// This code is in the public domain.
//===================================================================

int sensorPin = A0;  // connect sensor to pin A0

void setup() {
  Serial.begin(9600);  // start serial comms
}

void loop() {
  int sensorValue = analogRead(sensorPin);  // read analog input pin
  Serial.println(sensorValue);              // print result to serial monitor

  delay(100);  // short delay
}
