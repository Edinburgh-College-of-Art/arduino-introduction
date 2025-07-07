//===========================================================================
// File: LEDStrip_RGB_Blink.ino
//
// Description:
// - This sketch will blink an RGB LED strip on and off every second.
// - By changing the R, G and B brightness values, you mix and create colours.
//
// Pinout:
//
// | LED Strip | Arduino   |
// |---------- |-----------|
// | GND or 5V | GND or 5V |  * This depends on the type of LED strip.  
// | R 	       | D3        |      
// | G	       | D5        |
// | B	       | D6        |
//
// This code is in the public domain.
//===========================================================================

// Define pin numbers for LED pins
// Should be PWM pins (~)
int pinR = 3;
int pinG = 5;
int pinB = 6;

// Set brightness value for each colour
// This will mix the RGB values into a new colour
// i.e red + blue = purple (although it will look more like pink so worth testing)
//
// Mixing full brightness red, green and blue together will make white light
// Although in practice, again, this usually looks like a blue/white light.
//
// Remember that for each individual colour that is full brightness, it will draw about 20mA of current
// Multiplied across several pixels, this may be more than the Arduino can safely handle
// You may need to use a power supply + some MOSFETs to power larger LED strips this way
int red = 100;   // 0-255
int green = 50;  // 0-255
int blue = 195;  // 0-255

void setup() {
  // Init pins as OUTPUT
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
}

void loop() {
  // Turn on LEDs
  analogWrite(pinR, red);
  analogWrite(pinG, green);
  analogWrite(pinB, blue);
  delay(1000);  // Wait for 1 second

  // Turn off LEDs
  analogWrite(pinR, 0);
  analogWrite(pinG, 0);
  analogWrite(pinB, 0);
  delay(1000);  // Wait for 1 second
}