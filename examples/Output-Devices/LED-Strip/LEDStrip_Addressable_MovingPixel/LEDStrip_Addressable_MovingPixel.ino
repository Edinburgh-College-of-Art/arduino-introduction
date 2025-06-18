#include <Adafruit_NeoPixel.h>

// Store pin number and no. pixels as variables
int dataPin = 6;
int numberOfPixels = 20;  // no. pixels on your LED strip

// Create Adafruit_NeoPixels object
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numberOfPixels, dataPin, NEO_GRB + NEO_KHZ800);

// Create and store colour
const uint32_t BLUE = strip.Color(0, 0, 255);
int brightness = 100;  // Brightness value (0-255)

void setup() {
  // Init LED Strip
  strip.begin();
}

void loop() {
  for (int i = 0; i < numberOfPixels; i++) {
    // Clear all previous changes
    strip.clear();

    // Set next pixel colour
    // R=0 G=0 B=255 (Blue Light)
    strip.setPixelColor(i, BLUE);
    strip.setBrightness(brightness);  // Set brightness so it isn't blinding

    // Display and wait
    strip.show();
    delay(1000);  // 1 second delay
  }
}