//================================================
// LDR.ino
//
// Reads from LDR and prints data to serial monitor
//
// Circuit:
// 5V -> LDR -> 100kOhm Resistor -> GND
//          |
//          V
//     Arduino Pin A0
//================================================

// Set pin
int sensorPin = A0;

void setup() {
  // Start serial comms
  Serial.begin(9600); 
}

void loop() {
  // read data from analog pin
  int sensorValue = analogRead(sensorPin);

  // print to serial monitor
  Serial.println(sensorValue);
  
  // small delay
  delay(100);
}