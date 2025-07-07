//===================================================================
// File: CapacitiveTouch_BasicRead.ino
//
// Description:
// - Sketch for using the CapacitiveSensor.h library to read the 
//   input value of a capacitive touch sensor.
// 
// Pinout:
// 
// Conductive Material ---> D2
//            |
//            ---> 1MΩ ---> D3
//
// This code is in the public domain.
//===================================================================

#include <CapacitiveSensor.h>

#define SENSOR_PIN 2     // Pin connected to sensor (conductive material)
#define REFERENCE_PIN 3  // Reference pin connected via 1MΩ resistor

// Create CapacitiveSensor object
CapacitiveSensor capSensor = CapacitiveSensor(REFERENCE_PIN, SENSOR_PIN);

void setup() {
  // Start serial connection
  Serial.begin(9600);
}

void loop() {
  // Get sensor value, store as integer variable
  unsigned int capSensorValue = capSensor.capacitiveSensor(30);

  // Send output to Serial Monitor
  Serial.println(capSensorValue);

  // Short delay so we aren't sending too many serial messages
  delay(10);
}