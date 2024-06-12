#include <HX711.h>
  
// Define the pin locations
int dtPin = 2;
int sckPin = 3;
  
// Create instance of HX711 class
HX711 hx;
  
// **This is the calibration factor you calculated previously**
float calibrationFactor = -159.76;  // <-- Change this value
  
void setup() {
  // Start serial communication
  Serial.begin(9600);
  Serial.println("Calibrating... remove weight");
  
  // Tell HX711 object where pins are
  hx.begin(dtPin, sckPin);
  while (!hx.is_ready()) {}
  
  // Calibrate scale
  hx.set_scale(calibrationFactor);
  
  // Set scale to 0
  hx.tare();
  
  Serial.println("Ready!");
}
  
void loop() {
  // Get average of 5 readings
  float weightReading = hx.get_units(5);
  
  // Print to serial monitor
  Serial.println(weightReading);
  delay(1000);
}