//================================================
// SR04_UltraSonic.ino
//
// Reads from SR04 UltraSonic sensor and prints
// data to serial monitor
//
// Pinout:
// Vcc ----> 5V
// GND ----> GND
// Trig ---> 10
// Echo ---> 9
//================================================

// defines pins numbers                
const int trigPin = 10;
const int echoPin = 9;

// defines variables
long duration;
int distance;

void setup() {
  // start serial comms
  Serial.begin(9600);

  // set up pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin to HIGH for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin
  // return the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;

  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
}