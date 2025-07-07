//======================================================================
// File: NeoPixel_Moving.ino
//
// Description:
// - This sketch will make the NeoPixel look like it has a moving pixel.
// - It does this by incrementing the pixel that is on while turning 
//   all other pixels off.
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
//=======================================================================

#include <Adafruit_NeoPixel.h>
  
// Store pin number and no. pixels as variables
int pixelPin = 6;
int numberOfPixels = 12; // no. pixels on your NeoPixel
  
// Create Adafruit_NeoPixels object
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numberOfPixels, pixelPin, NEO_GRB + NEO_KHZ800);
  
void setup() {
  // Init NeoPixels
  pixels.begin(); 
}
  
void loop() {
  for (int i = 0; i < numberOfPixels; i++) {
    // Clear all previous changes
    pixels.clear();
      
    // Set next pixel colour
    pixels.setPixelColor(i, 0, 0, 255);
      
    // Display and wait for 1s
    pixels.show();
    delay(1000);
  }
}