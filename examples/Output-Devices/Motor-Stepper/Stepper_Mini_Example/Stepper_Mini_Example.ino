//===================================================================
// File: Stepper_Mini_Example.ino
//
// Description:
//    - Sketch for controlling a 28BYJ-48 stepper motor with ULN2003
//      motor driver.
//    - Turn full rotation clockwise then counter-clockwise.
//
// Pinout:
//      ULN2003     Arduino
//      IN1     ->  2
//      IN2     ->  4
//      IN3     ->  3
//      IN4     ->  5
//===================================================================

#include <Stepper.h>

// Define pin numbers
#define IN1 2
#define IN2 4
#define IN3 3
#define IN4 5

#define STEPS_PER_REV = 2048;  // number of steps per full revolution

// Create stepper object
Stepper stepper(STEPS_PER_REV, IN1, IN2, IN3, IN4);

void setup() {}

void loop() {
  // Rotate clockwise one full revolution
  stepper.setSpeed(5);          // 5RPM
  stepper.step(STEPS_PER_REV);  // positive number of steps = clockwise
  delay(1000);

  // Rotate counter-clockwise one full revolution
  stepper.setSpeed(10);          // 10RPM
  stepper.step(-STEPS_PER_REV);  // negative  number of steps = counter-clockwise
  delay(1000);
}