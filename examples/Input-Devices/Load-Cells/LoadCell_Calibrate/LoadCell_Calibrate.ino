//===================================================================
// File: LoadCell_Calibrate.ino
//
// Description:
// - Run this sketch and follow instructions on serial monitor to 
//   calibrate your HX711.
//
// Pinout:
//
// | HX711 | Arduino |
// |-------|---------|
// | GND	 | GND     |   
// | VCC 	 | 5V      |      
// | DT	   | D2      |
// | SCK 	 | D3      |
//
// This code is in the public domain.
//===================================================================

#include <HX711.h>
  
// Define the pin locations
int dtPin = 2;
int sckPin = 3;
  
// Create instance of HX711 class
HX711 hx;
  
void setup() {
  // Start serial communication
  Serial.begin(9600);
    
  // Tell HX711 object where pins are
  hx.begin(dtPin, sckPin);
    
  // Wait until HX711 has been initialised
  while (!hx.is_ready()) {}
    
  Serial.println("Ready");
}
  
void loop() {
    
  // Get ready for tare
  hx.set_scale();    
  Serial.println("1. Remove weight from the load cell");
  delay(3000);
    
  // Set scale to 0
  Serial.print("Zeroing... ");
  hx.tare();
  Serial.println("done.");
  Serial.print("2. Place weight on the load cell");
  delay(3000);
    
  // Get reading
  Serial.println("Reading... ");
  long reading = hx.get_units(10);
  Serial.print("Result: ");
  Serial.println(reading);
    
  // Calculate calibration factor
  Serial.println("3. Calculate calibration factor:");
  Serial.print(reading);
  Serial.println(" divided by the weight you used in grams.");
  Serial.println("**Save this for later**");
    
  delay(5000);
}