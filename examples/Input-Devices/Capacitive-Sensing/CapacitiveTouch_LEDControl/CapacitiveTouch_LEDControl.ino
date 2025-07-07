//===================================================================
// File: CapacitiveTouch_BasicRead.ino
//
// Description:
// - Sketch for using the CapacitiveSensor.h library to read the 
//   input value of a capacitive touch sensor.
// - This sketch uses the input value to control an LED.
// - Sensitivity can be adjusted by varying the THRESHOLD value.
// 
// Pinout:
// 
// Conductive Material ---> D2
//            |
//            ---> 1MΩ ---> D3
//
// LED <--- 220Ω <--- D13*
//
// *LED is optional as D13 also controls the built-in LED
//
// This code is in the public domain.
//===================================================================

#include <CapacitiveSensor.h>

#define LED_PIN 13       // Pin connected to LED
#define SENSOR_PIN 2     // Pin connected to sensor (conductive material)
#define REFERENCE_PIN 3  // Reference pin connected via 1MΩ resistor

#define THRESHOLD 500  // <-- Adjust this threshold value for sensitivity

// Create CapacitiveSensor object
CapacitiveSensor capSensor = CapacitiveSensor(REFERENCE_PIN, SENSOR_PIN);

void setup() {
  // Start serial connection
  Serial.begin(9600);

  // Initialize LED pin as OUTPUT
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Get sensor value, store as integer variable
  unsigned int capSensorValue = capSensor.capacitiveSensor(30);

  // Send output to Serial Monitor
  Serial.println(capSensorValue);

  // If capSensorValue is above threshold...
  if (capSensorValue > THRESHOLD)
    digitalWrite(LED_PIN, HIGH);  // ...turn on LED...
  else
    digitalWrite(LED_PIN, LOW);  // ...otherwise, turn off LED.

  // Short delay so we aren't sending too many serial messages
  delay(10);
}