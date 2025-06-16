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