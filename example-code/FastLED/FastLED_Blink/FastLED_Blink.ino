//================================================
// FastLED_Blink.ino
//
// Blink WS2812b LED strip on and off periodically
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
  // Turn the LEDs red, then pause
  for (int i = 0; i < NUM_LEDS; i++)
    leds[i] = CRGB::Red;
  
  FastLED.show();
  delay(500);

  // Turn the LEDs off, then pause
  for (int i = 0; i < NUM_LEDS; i++)
    leds[i] = CRGB::Black;
  
  FastLED.show();
  delay(500);
}
