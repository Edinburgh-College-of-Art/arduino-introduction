//===================================================================
// File: LEDStrip_Addresable_Blink.ino
//
// Description:
// - Sketch for blinking an addressable LED strip ring on and off 
//   every second.
//
// Pinout:
//
// | LED Strip | Arduino |
// |---------- |---------|
// | GND	     | GND     |   
// | 5V 	     | 5V      |      
// | IN	       | D6      |
//
// This code is in the public domain.
//===================================================================

#include <Adafruit_NeoPixel.h>
  
// Store pin number and no. pixels as variables
int dataPin = 6;
int numberOfPixels = 20; // no. pixels on your LED strip
  
// Create Adafruit_NeoPixels object
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numberOfPixels, dataPin, NEO_GRB + NEO_KHZ800);
  
// Create and store colour
uint32_t red = strip.Color(255, 0, 0);
  
void setup() {
  // Init LED Strip
  strip.begin(); 
}
  
void loop() {
  // Turn red for one second
  strip.fill(red, 0, numberOfPixels);
  strip.show(); // display changes
  delay(1000);
    
  // Turn off for one second
  strip.clear();
  strip.show(); // display changes
  delay(1000);
}