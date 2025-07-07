//===========================================================================
// File: L289N_DriverDC_Example.ino
//
// Description:
// - This sketch demonstrates how to use a L298N DC motor driver to control
//   two DC motors.
//
// Pinout:
//
// | L298N | Arduino |
// |------ |---------|
// | GND   | GND     |  
// | 5V    | 5V      |      
// | ENA   | D10     |
// | IN1   | D9      |
// | IN2   | D8      |
// | ENB   | D7      |
// | IN3   | D6      |
// | IN4   | D5      |
//
// This code is in the public domain.
//===========================================================================


// Motor 1 Pins
int enA = 10;  // PWM pin for speed control
int in1 = 9;
int in2 = 8;

// Motor 2 Pins
int enB = 7;  // PWM pin for speed control
int in3 = 6;
int in4 = 5;

void setup() {
    // Set the motor control pins as outputs
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    
    pinMode(enB, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
}

void loop() {
    //================================================================
    // 1. ROTATE BOTH MOTORS FORWARD
  
    // Setting in1 to HIGH and in2 to LOW will put Motor 1 into forward position
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

    // Setting in2 to HIGH and in3 to LOW will put Motor 2 into forward position
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

    // Set the speed of both motors 
    // 0 = off, 255 = full speed
    analogWrite(enA, 255);
    analogWrite(enB, 255);
    delay(2000);

    // Stop both motors
    analogWrite(enA, 0);
    analogWrite(enB, 0);
    delay(2000);
    
    //================================================================
    // 2. ROTATE BOTH MOTORS BACKWARDS
  
    // Setting in1 to LOW and in2 to HIGH will put Motor 1 into backward position
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    // Setting in2 to LOW and in3 to HIGH will put Motor 2 into backward position
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    // Set the speed of both motors 
    // 0 = off, 255 = full speed
    analogWrite(enA, 128);
    analogWrite(enB, 128);
    delay(2000);

    // Stop both motors
    analogWrite(enA, 0);
    analogWrite(enB, 0);
    delay(2000);
    
    //================================================================
    // 4. ROTATE MOTORS IN OPPOSITE DIRECTIONS
  
    // Setting in1 to HIGH and in2 to LOW will put Motor 1 into forward position
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

    // Setting in2 to LOW and in3 to HIGH will put Motor 2 into backward position
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    // Set the speed of both motors 
    // 0 = off, 255 = full speed
    analogWrite(enA, 255);
    analogWrite(enB, 255); 
    delay(2000);

    // Stop both motors
    analogWrite(enA, 0);
    analogWrite(enB, 0);
    delay(2000);
}