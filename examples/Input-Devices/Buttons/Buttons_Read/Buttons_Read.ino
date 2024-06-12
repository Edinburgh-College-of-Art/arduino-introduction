//===================================================================
// File:   Buttons_Read.ino
//
// Author: J.Hathway 2024
//
// Description: 
//          - Read the button value from pin 3 and print data to 
//            serial monitor.
//===================================================================       

// Store button pin number in variable
int buttonPin = 2;
  
void setup() {
  // Start serial monitor
  Serial.begin(9600);
    
  // Initialise button pin as INPUT_PULLUP
  // This uses the on-board pullup resistor
  pinMode(buttonPin, INPUT_PULLUP);
}
  
void loop() {
  // Print button reading to serial monitor
  Serial.println(digitalRead(buttonPin));
}