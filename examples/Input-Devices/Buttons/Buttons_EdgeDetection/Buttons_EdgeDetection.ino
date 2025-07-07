//===================================================================
// File: Buttons_EdgeDetection.ino
//
// Description: 
// - Read the button value from pin 3.
// - Use edge detection to print when the button is:
//         - pressed (falling edge).
//         - released (rising edge).
//  - Also flip state of switchState boolean and print data at end 
//    of loop().
//
// This code is in the public domain
//=================================================================== 

// Store pin numbers in variable
int buttonPin = 3;
  
// Variable to save the last change in button value
bool lastValue;
  
// Variable to save the state of the switch boolean
bool switchState = 0;
  
void setup() {
  // Start serial monitor
  Serial.begin(9600);
    
  // Initialise pin
  pinMode(buttonPin, INPUT_PULLUP);
    
  // Save current button state
  lastValue = digitalRead(buttonPin);
}  
  
void loop() {
  // Get current button state
  bool currentValue = digitalRead(buttonPin);
    
  // If value has changed
  if (currentValue != lastValue) {
    // Update last changed button value
    lastValue = currentValue;
      
    // If value is 0 (button pressed)
    if (currentValue == 0) {
        // reverse state (true -> false/false -> true)
        switchState = !switchState;    

        Serial.println("Button pressed (falling edge)");
    }
    else {
        Serial.println("Button release (rising edge)");
    }

    delay(500); // short delay to see data
  }

  // Print switch data
  if (switchState) {
    // Do something if switch state is true
    Serial.println("Switch: ON");
  }
  else {
    // Do something if switch state is false
    Serial.println("Switch: OFF");
  }
}