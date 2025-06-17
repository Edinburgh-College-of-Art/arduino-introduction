//===========================================================================
// Potentiometer_SerialPlotter.ino
//
// - Use analogRead() to get potentiometer value.
// - Format output for Serial Plotter.
//
// **To use this sketch, upload to your Arduino and open the Serial Plotter**
//============================================================================

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