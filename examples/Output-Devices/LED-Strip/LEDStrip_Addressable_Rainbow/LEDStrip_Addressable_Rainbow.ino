#include <Adafruit_NeoPixel.h>

// Store pin number and no. pixels as variables
int dataPin = 6;
int numberOfPixels = 20;  // no. pixels on your LED strip

// Create Adafruit_NeoPixels object
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numberOfPixels, dataPin, NEO_GRB + NEO_KHZ800);

long hue = 0;          // Starting hue value
int brightness = 100;  // Brightness value (0-255)

void setup() {
  // Init LED Strip
  strip.begin();
}

void loop() {
  // This function sets the colors of all the LEDs on the strip to a rainbow pattern.
  // The rainbow starts at the colour defined by hue and smoothly transitions across
  // the rest of the strip.
  strip.rainbow(hue);
  strip.setBrightness(brightness);  // adjust brightness so it isn't blinding

  // Increment hue value
  hue += 256;
  hue = hue > (5 * 65536) ? 0 : hue;

  // Display changes
  strip.show();
  delay(20); // short delay (20ms)
}