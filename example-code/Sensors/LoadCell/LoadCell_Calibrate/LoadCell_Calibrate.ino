//================================================
// LoadCell_Calibrate.ino
//
// Code for calibrating load cell with 
// HX711 amplifier
// 
// Requires HX711 library
//
// Instructions:
// 1. Run code and open serial monitor
// 2. Wait for instruction to place a weight on loadcell
// 3. Calibration factor will be the result divided by 
//    the weight of the object placed on loadcell
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

// Calibrating the load cell
#include "HX711.h"

// Define pins
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

HX711 scale;

void setup() {
  // Start serial comms
  Serial.begin(57600);

  // Init loadcell object  
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}

void loop() {
  // Open Serial Monitor and follow instructions
  if (scale.is_ready()) {
    scale.set_scale();    
    Serial.println("Tare... remove any weights from the scale.");
    delay(5000);

    scale.tare();
    Serial.println("Tare done...");
    Serial.print("Place a known weight on the scale...");
    delay(5000);

    long reading = scale.get_units(10);
    Serial.print("Result: ");
    Serial.println(reading);
  } 
  else {
    Serial.println("HX711 not found.");
  }

  delay(1000);
}