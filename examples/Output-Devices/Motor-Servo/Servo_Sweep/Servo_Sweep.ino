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