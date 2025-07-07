//======================================================================
// File: Stepper_SparkfunEasyDriver.ino.ino
//
// Description:
// - This sketch demonstrates how to use the Sparkfun EasyDriver to
//   controll a 4-wire stepper motor.
// - Stepper motor will move 1000 steps forwards, pause for 1 second,
//   move 1000 steps backwards and pause for 1 second.
//
// Pinout:
//
// | Arduino	 | Sparkfun EasyDriver |
// | --------- | --------------------|
// | GND   	   | GND                 |
// | D2        | STEP	               |
// | D3        | DIR	               |
// | D4        | MS1	               |
// | D5        | MS2	               |
// | D6        | ENABLE	             |
//
// | Sparkfun EasyDriver | Stepper Motor |
// | ------------------- | ------------- |
// | A+	                 | Green Wire	   |
// | A-	                 | Red Wire	     |
// | B+	                 | Blue Wire	   |
// | B-                  | Yellow Wire	 |
//
// This code is in the public domain.
//=======================================================================

// Declare pin locations
#define STEP 2
#define DIR 3
#define MS1 4
#define MS2 5
#define EN 6

#define NUM_STEPS 1000  // number of steps you want motor to move

void setup() {
  // Initialise pins as OUTPUT
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(EN, OUTPUT);

  // Set pins to default states before starting
  resetEDPins();
}

void loop() {
  // MOVE FORWARDS
  digitalWrite(EN, LOW);   // EN=LOW to allow motor control
  digitalWrite(DIR, LOW);  // DIR=LOW to move "forwards"
  move();                  // Move motor
  resetEDPins();
  delay(1000);  // wait for 1 second

  // MOVE BACKWARDS
  digitalWrite(EN, LOW);
  digitalWrite(DIR, HIGH);  // DIR=HIGH to move "backwards"
  move();                   // Move motor
  resetEDPins();
  delay(1000);  // wait for 1 second
}

//=======================================================================

/// Reset pins
void resetEDPins() {
  digitalWrite(STEP, LOW);
  digitalWrite(DIR, LOW);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  digitalWrite(EN, HIGH);
}

/// Move Stepper forwards
void move() {
  for (int i = 0; i < NUM_STEPS; i++) {
    digitalWrite(STEP, HIGH);  //Trigger one step forward
    delay(1);
    digitalWrite(STEP, LOW);  // Pull step pin low so it can be triggered again
    delay(1);
  }
}