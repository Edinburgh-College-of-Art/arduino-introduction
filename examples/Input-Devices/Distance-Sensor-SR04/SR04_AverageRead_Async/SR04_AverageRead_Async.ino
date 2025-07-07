//===================================================================
// File: SR04_AverageRead_Async.ino
//
// Description:
// - Calculate average distance from an array of SR04 readings.
// - Averaging readings should smooth input data stream.
//
// - This sketch is (sort of) asynchronous as the loop() function only
//   gathers one distance reading per loop iteration.
// - This means we don't have to wait for the loop to fill the array
//   with readings before calculating the average distance.
//
// - Results are printed to the serial monitor
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

// How many values do you want to take the average of?
#define NUM_READINGS 50

float readings[NUM_READINGS];
int index = 0;

void setup() {
  // Start serial monitor
  Serial.begin(9600);

  // Define pin modes
  pinMode(trigPin, OUTPUT);  // trig = OUTPUT
  pinMode(echoPin, INPUT);   // echo = INPUT

  // Fill array with starting values
  for (int i = 0; i < NUM_READINGS; i++)
    addReading();
}

void loop() {
  // Get current and average readings
  float currentReading = addReading();   // add new distance to array
  float averageDistance = getAverage();  // calculate average distance

  // Print results to serial monitor
  Serial.print("Current reading: ");
  Serial.print(currentReading);
  Serial.print("cm, ");
  Serial.print("Average distance: ");
  Serial.print(averageDistance);
  Serial.println("cm");
}

//===================================================================

/// Get new distance reading and add to readings array
/// @return currentReading (float)
float addReading() {
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

  // Calculate the distance in cm
  float distanceInCentimeters = (duration * 0.034) / 2.0;

  // Add to readings array
  readings[index] = distanceInCentimeters;
  index++;  // increment write index
  if (index > NUM_READINGS) index = 0;

  return distanceInCentimeters;
}

/// Calculate average distance
/// @return average (float)
float getAverage() {
  // Add all distance readings together
  float total = 0;
  for (float reading : readings)
    total = total + reading;

  return total / NUM_READINGS;  // average = total / number of readings
}