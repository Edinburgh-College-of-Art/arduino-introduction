//===================================================================
// File: LDR_Example.ino
//
// Description:
// - Read voltage level from LDR circuit.
// - Results are printed to the serial monitor
//
// Pinout:
//
// LDR <--- 5V
//  |
//  |-----> A0
//  |    
//   -----> 10kΩ ---> GND

// This code is in the public domain.
//===================================================================

// Store pin number as a variable
int ldrPin = A0;
  
void setup() {
  // Start serial monitor
  Serial.begin(9600);
    
  // Initialise potentiometer pin as INPUT
  pinMode(ldrPin, INPUT);
}
  
void loop() {
  // Print the anaolog read value at potPin
  Serial.println(analogRead(ldrPin));
}