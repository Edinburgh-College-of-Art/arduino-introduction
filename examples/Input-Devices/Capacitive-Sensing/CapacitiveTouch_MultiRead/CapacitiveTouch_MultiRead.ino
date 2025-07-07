//===================================================================
// File: CapacitiveTouch_BasicRead.ino
//
// Description:
// - Sketch for using the CapacitiveSensor.h library to read the 
//   input value of 3 capacitive touch sensors.
// - Sensor values are then sent to serial monitor.
// 
// Pinout:
// 
// Conductive Material ---> D2
//            |
//            ---> 1MΩ ---> D5
//
// Conductive Material ---> D3
//            |
//            ---> 1MΩ ---> D5
//
// Conductive Material ---> D4
//            |
//            ---> 1MΩ ---> D5
//
// This code is in the public domain.
//===================================================================

#include <CapacitiveSensor.h>

#define SENSOR_PIN_1 2     // Pin connected to sensor 1
#define SENSOR_PIN_2 3     // Pin connected to sensor 2
#define SENSOR_PIN_3 4     // Pin connected to sensor 3

#define REFERENCE_PIN 5  // Reference pin connected via 1MΩ resistor

// Create CapacitiveSensor objects
CapacitiveSensor capSensor1 = CapacitiveSensor(REFERENCE_PIN, SENSOR_PIN_1);
CapacitiveSensor capSensor2 = CapacitiveSensor(REFERENCE_PIN, SENSOR_PIN_2);
CapacitiveSensor capSensor3 = CapacitiveSensor(REFERENCE_PIN, SENSOR_PIN_3);

void setup() {
  // Start serial connection
  Serial.begin(9600);
}

void loop() {
  // Get sensor value, store as integer variable
  unsigned int capSensorValue1 = capSensor1.capacitiveSensor(30);
  unsigned int capSensorValue2 = capSensor2.capacitiveSensor(30);
  unsigned int capSensorValue3 = capSensor3.capacitiveSensor(30);

  // Send output to Serial Monitor
  Serial.print(capSensorValue1);
  Serial.print("\t");
  Serial.print(capSensorValue2);
  Serial.print("\t");
  Serial.println(capSensorValue3);

  // Short delay so we aren't sending too many serial messages
  delay(10);
}