//================================================
// Motors_Servo.ino
//
// Blink NeoPixels on and off periodically
//
// Pinout:
// Arduino      Servo
// GND     ->   GND
// 5V      ->   PWR
// 6       ->   IN
//================================================

#include <Servo.h>

// Declare pin number
int servoPin = 6;

Servo motor;

void setup() {
  motor.attach(servoPin);  
}

void loop() {
  // Move from 0-180 degrees
  for (int i = 0; i <= 180; i++) {
    motor.write(pos);
    delay(20);
  }

  // Move from 180-0 degrees
  for (int i = 180; i >= 0; i++) {
    motor.write(pos);
    delay(20); 
  }
}
