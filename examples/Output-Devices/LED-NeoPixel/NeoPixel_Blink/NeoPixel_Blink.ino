//===================================================================
// File: NeoPixel_Blink.ino
//
// Description:
// - Sketch for blinking a NeoPixel ring on and off every second.
//
// Pinout:
//
// | NeoPixel | Arduino |
// |--------- |---------|
// | GND	    | GND     |   
// | VCC 	    | 5V      |      
// | IN	      | D6      |
//
// This code is in the public domain.
//===================================================================

#include <Adafruit_NeoPixel.h>
  
// Store pin number and no. pixels as variables
int pixelPin = 6;
int numberOfPixels = 12; // no. pixels on your NeoPixel
  
// Create Adafruit_NeoPixels object
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numberOfPixels, pixelPin, NEO_GRB + NEO_KHZ800);
  
// Create and store colour
uint32_t red = pixels.Color(255, 0, 0);
  
void setup() {
  // Init NeoPixels
  pixels.begin(); 
}
  
void loop() {
  // Turn red for one second
  pixels.fill(red, 0, numberOfPixels);
  pixels.show(); // display changes
  delay(1000);
    
  // Turn off for one second
  pixels.clear();
  pixels.show(); // display changes
  delay(1000);
}