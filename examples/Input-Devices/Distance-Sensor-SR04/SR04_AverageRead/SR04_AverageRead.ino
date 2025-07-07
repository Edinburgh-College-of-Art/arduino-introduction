//===================================================================
// File: SR04_AverageRead_Async.ino
//
// Description:
// - Calculate average distance from an array of SR04 readings.
// - Averaging readings should make reading more "accurate".
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
int numberOfValues = 10;

void setup() {
  // Start serial monitor
  Serial.begin(9600);

  // Define pin modes
  pinMode(trigPin, OUTPUT);  // trig = OUTPUT
  pinMode(echoPin, INPUT);   // echo = INPUT
}

void loop() {
  // Variable to sum distance values
  float sum = 0;

  for (int i = 0; i < numberOfValues; i++) {
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

    sum += cm;
  }

  // Calculate average distance
  float average = sum / float(numberOfValues);

  // Print results
  Serial.print("Average of ");
  Serial.print(numberOfValues);
  Serial.print(" distance readings is ");
  Serial.println(average);
}