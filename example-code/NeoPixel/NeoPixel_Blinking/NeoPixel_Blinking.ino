//================================================
// NeoPixel_Blinking.ino
//
// Blink NeoPixels on and off periodically
//
// Pinout:
// Arduino      NeoPixel
// GND     ->   GND
// 5V      ->   PWR
// 6       ->   IN
//================================================

#include <Adafruit_NeoPixel.h>

#define PIXEL_PIN 6     // Digital IO pin connected to the NeoPixels.
#define PIXEL_COUNT 12  // Number of pixels on NeoPixel

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

// Set colour of pixel
uint32_t pixelColor = pixels.Color(50, 0, 200);

// Set delay time
int delayInMilliseconds = 500;

void setup() {
  // Init pixels
  pixels.begin();
}

void loop() {
  // Turn on and wait
  pixels.fill(pixelColor, 0, PIXEL_COUNT);
  pixels.show();
  delay(delayInMilliseconds);

  // Turn off and wait
  pixels.clear();
  pixels.show();
  delay(delayInMilliseconds);
}
