//===================================================================
// File: SR04_ReadDistance.ino
//
// Description:
// - Basic SR04 read sketch.
// - Calculate distance in front of sensor and print to serial monitor.
// 
// Pinout:
// 
// | SR04 | Arduino |
// |------|---------|
// | GND  | GND     |
// | VCC  | 5V      |
// | TRIG | D3      |
// | ECHO | D2      |
//
// This code is in the public domain.
//===================================================================

// Define pin numbers
int trigPin = 3;
int echoPin = 2;
  
void setup() {
  // Start serial monitor
  Serial.begin(9600);
    
  // Define pin modes
  pinMode(trigPin, OUTPUT); // trig = OUTPUT
  pinMode(echoPin, INPUT);  // echo = INPUT
}
  
void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Set the trigPin on HIGH state for 10 micro seconds
  // This outputs the ultrasonic pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin
  // Returns the sound wave travel time in microseconds
  float duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  float cm = (duration * 0.034) / 2.0;
  float inches = (duration * 0.0135) / 2.0;
     
  // Print results
  Serial.print("Distance in cm = ");
  Serial.print(cm);
  Serial.print(", inches = ");
  Serial.println(inches);
}