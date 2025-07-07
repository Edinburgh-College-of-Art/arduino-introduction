//======================================================================
// File: NeoPixel_Rainbow.ino
//
// Description:
// - This sketch will make the NeoPixels display a rainbow pattern.
// - The Adafruit_NeoPixel library shows us how to do this this in its 
//   strandtest example.
//
// Pinout:
//
// | NeoPixel | Arduino |
// |--------- |---------|
// | GND	  | GND     |   
// | 5V 	  | 5V      |      
// | IN	      | D6      |
//
// This code is in the public domain.
//=======================================================================

#include <Adafruit_NeoPixel.h>

// Store pin number and no. pixels as variables
int dataPin = 6;
int numberOfPixels = 12;  // no. pixels on your NeoPixel

// Create Adafruit_NeoPixels object
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numberOfPixels, dataPin, NEO_GRB + NEO_KHZ800);

long hue = 0;          // Starting hue value
int brightness = 100;  // Brightness value (0-255)

void setup() {
  // Initialize NeoPixels
  pixels.begin();
}

void loop() {
  // This function sets the colors of all the LEDs on the NeoPixel to a rainbow pattern.
  // The rainbow starts at the colour defined by hue and smoothly transitions across
  // the rest of the pixels.
  pixels.rainbow(hue);
  pixels.setBrightness(brightness);  // adjust brightness so it isn't blinding

  // Increment hue value
  hue += 256;
  hue = hue > (5 * 65536) ? 0 : hue;

  // Display changes
  pixels.show();
  delay(20); // short delay (20ms)
}