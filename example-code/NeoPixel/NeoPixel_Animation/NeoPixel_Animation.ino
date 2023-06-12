//================================================
// NeoPixel_Animation.ino
//
// Display a simple animation
// LED will travel along surface of NeoPixel
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
uint32_t pixelColor = pixels.Color(255, 255, 255);

void setup() {
  // Init NeoPixel
  pixels.begin();
}

void loop() {
  for (int i = 0; i < PIXEL_COUNT; i++) {
    // clear previous frame
    pixels.clear();

    // set next pixel
    pixels.setPixelColor(i, pixelColor);

    // display changes
    pixels.show();

    // short delay
    delay(200);
  }
}
