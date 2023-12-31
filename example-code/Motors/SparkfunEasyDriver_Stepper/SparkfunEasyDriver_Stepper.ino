//=================================================
// Motors_Stepper_SparkfunEasy.ino
//
// Code for the Sparkfun Easy Driver to control a
// NEMA 16 stepper motor or similar.
//
// This code has been adapted from the example code
// found here:
// https://learn.sparkfun.com/tutorials/easy-driver-hook-up-guide/all
// 
// Pinout:
// Arduino   |   EasyDriver
// 2   --------> STEP
// 3   --------> DIR
// 4   --------> MS1
// 5   --------> MS2
// 6   --------> ENABLE
// GND --------> GND
//
// MOTOR      |   EasyDriver
// GRN ---------> A+
// RED ---------> A-
// BLU ---------> B+
// YEL ---------> B-
//=================================================

//Declare pin functions on RedBoard
#define stp 2
#define dir 3
#define MS1 4
#define MS2 5
#define EN 6

//Declare variables for functions
char user_input;
int x;
int y;
int state;

//=================================================
// SETUP
void setup() {
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(EN, OUTPUT);
  resetEDPins();       //Set step, direction, microstep and enable pins to default states
  Serial.begin(9600);  //Open Serial connection for debugging
  Serial.println("Begin motor control");
  Serial.println();
  //Print function list for user selection
  Serial.println("Enter number for control option:");
  Serial.println("1. Turn at default microstep mode.");
  Serial.println("2. Reverse direction at default microstep mode.");
  Serial.println("3. Turn at 1/8th microstep mode.");
  Serial.println("4. Step forward and reverse directions.");
  Serial.println();
}

//=================================================
// LOOP
void loop() {
  while (Serial.available()) {
    user_input = Serial.read();  //Read user input and trigger appropriate function
    digitalWrite(EN, LOW);       //Pull enable pin low to allow motor control
    if (user_input == '1') {
      StepForwardDefault();
    } else if (user_input == '2') {
      ReverseStepDefault();
    } else if (user_input == '3') {
      SmallStepMode();
    } else if (user_input == '4') {
      ForwardBackwardStep();
    } else {
      Serial.println("Invalid option entered.");
    }
    resetEDPins();
  }
}

//=================================================
// RESET
void resetEDPins()
{
  digitalWrite(stp, LOW);
  digitalWrite(dir, LOW);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  digitalWrite(EN, HIGH);
}

//=================================================
// STEP FORWARD
void StepForwardDefault()
{
  Serial.println("Moving forward at default step mode.");
  digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
  for(x= 0; x<1600; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);
  }
  Serial.println("Enter new option");
  Serial.println();
}

//=================================================
// REVERSE STEP
void ReverseStepDefault()
{
  Serial.println("Moving in reverse at default step mode.");
  digitalWrite(dir, HIGH); //Pull direction pin high to move in "reverse"
  for(x= 0; x<1000; x++)  //Loop the stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);
  }
  Serial.println("Enter new option");
  Serial.println();
}

//=================================================
// SMALL STEP
void SmallStepMode()
{
  Serial.println("Stepping at 1/8th microstep mode.");
  digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
  digitalWrite(MS1, HIGH); //Pull MS1, and MS2 high to set logic to 1/8th microstep resolution
  digitalWrite(MS2, HIGH);
  for(x= 0; x<1000; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);
  }
  Serial.println("Enter new option");
  Serial.println();
}

//=================================================
// FORWARD/BACKWARD STEP
void ForwardBackwardStep()
{
  Serial.println("Alternate between stepping forward and reverse.");
  for(x= 1; x<5; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    //Read direction pin state and change it
    state=digitalRead(dir);
    if(state == HIGH)
    {
      digitalWrite(dir, LOW);
    }
    else if(state ==LOW)
    {
      digitalWrite(dir,HIGH);
    }

    for(y=0; y<1000; y++)
    {
      digitalWrite(stp,HIGH); //Trigger one step
      delay(1);
      digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
      delay(1);
    }
  }
  Serial.println("Enter new option:");
  Serial.println();
}