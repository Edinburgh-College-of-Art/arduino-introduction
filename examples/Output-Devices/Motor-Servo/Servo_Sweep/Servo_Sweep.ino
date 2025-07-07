//======================================================================
// File: Servo_Sweep.ino
//
// Description:
// - This sketch demonstrates how to usea Servo motor.
// - It will sweep the arm from 0° to 90° to 180°.
//
// Pinout:
//
// | Servo          | Arduino |
// |--------------- |---------|
// | Black/Brown    | GND     |   
// | Red            | 5V      |      
// | Orange/White   | D6      |
//
// This code is in the public domain.
//=======================================================================

#include <Servo.h> 
  
// Declare the servo pin location
int servoPin = 3; 
  
// Create a servo class instance
// This will have all of the functions 
// for controlling the servo
Servo myServo;
  
void setup() {
    // Tell servo object what pin we are using
    myServo.attach(servoPin); 
}
  
void loop() { 
    // 0 degrees 
    myServo.write(0); 
    delay(1000); // wait 1 second
    
    // 90 degrees 
    myServo.write(90); 
    delay(1000); // wait 1 second
    
    // 180 degrees 
    myServo.write(180); 
    delay(1000); // wait 1 second
}