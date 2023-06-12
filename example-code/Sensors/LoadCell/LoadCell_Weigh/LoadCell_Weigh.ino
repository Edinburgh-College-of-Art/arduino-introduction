//================================================
// LoadCell_Weigh.ino
//
// Code for load cell with HX711 amplifier
//
// Requires HX711 library
//
// Pinout:
// LoadCell     HX711
// Black   ->   E-
// Red     ->   E+
// White   ->   A-
// Green   ->   A+
//
// Arduino      HX711
// GND     ->   GND
// 5V      ->   VCC
// 3       ->   SCK
// 2       ->   DT
//================================================

#include "HX711.h"

// Define pins
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

// Set calibration value found in previous sketch
float calibrationValue = 450;

HX711 scale;

void setup() {
  // Start serial comms
  Serial.begin(57600);
  Serial.println("HX711 Demo");
  Serial.println("Initializing the scale");
  
  // Init loadcell object
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  // Print a raw reading from the ADC
  Serial.println("Before setting up the scale:");
  Serial.print("read: \t\t");
  Serial.println(scale.read());

  // Calibrate   
  scale.set_scale(calibrationValue);
  scale.tare();

  Serial.println("Readings:");
}

void loop() {
  Serial.print("one reading:\t");
  Serial.print(scale.get_units(), 1);
  Serial.print("\t| average:\t");
  Serial.println(scale.get_units(10), 5);

  delay(5000);
}