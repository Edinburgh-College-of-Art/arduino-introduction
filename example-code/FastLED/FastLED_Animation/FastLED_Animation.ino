//================================================
// FastLED_Animation.ino
//
// Display a simple animation
// LED will travel along strip
//
// Pinout:
// Arduino      WS2812b Strip
// GND     ->   GND
// 5V      ->   PWR
// 6       ->   IN
//================================================

#include <FastLED.h>

// Length of LED strip
#define NUM_LEDS 10

// Setup object to handle LED  states
CRGB leds[NUM_LEDS];

void setup() { 
    // Set GRB LED mode
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    // clear previous frame
    FastLED.clear();

    // set next pixel
    leds[i] = CRGB::White;

    // display changes
    FastLED.show();

    // short delay
    delay(200);
  }    
}
