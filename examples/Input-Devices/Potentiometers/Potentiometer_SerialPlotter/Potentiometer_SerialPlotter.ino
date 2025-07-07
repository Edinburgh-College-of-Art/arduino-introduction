//===================================================================
// File: Potentiometer_SerialPlotter.ino
//
// Description:
// - Use analogRead() to get potentiometer value.
// - Format output for serial plotter.
// - Upload sketch and open serial plotter.
//
// Pinout:
//
// GND <--- Potentiometer <--- 5V
//                |
//                |
//               A0
//
// This code is in the public domain.
//===================================================================

// Store pin number
int potPin = A0;

// Set lower and upper limits
int minVal = 0;
int maxVal = 1023;
  
void setup() {
  // Start serial monitor
  Serial.begin(9600);

  // We dont need to use pinMode()!
  // Arduino assumes that we are using analog inputs as INPUT by default
}
  
void loop() {
  // Store potentiometer value
  int potValue = analogRead(potPin);

  // Seperating each value with a comma
  // will plot it as a different data 
  // point on the Serial Plotter
  Serial.print(potValue);
  Serial.print(",");
  Serial.print(minVal);
  Serial.print(",");
  Serial.println(maxVal);
}