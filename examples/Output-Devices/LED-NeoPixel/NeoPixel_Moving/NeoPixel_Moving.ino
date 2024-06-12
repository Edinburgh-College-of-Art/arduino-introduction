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
      
    // Set pixel colour
    pixels.setPixelColor(i, 0, 0, 255);
      
    // Display and wait
    pixels.show();
    delay(1000);
  }
}