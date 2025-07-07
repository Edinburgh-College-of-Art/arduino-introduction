//===================================================================
// File: Potentiometer_AveragedRead.ino
//
// Description:
// - Calculate Average of 50 potentiometer readings.
// - Averaging readings should give more stable stream of data.
// - Averaging will also slow down any quick changes to input.
// - Results printed to serial monitor.
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

// Define pin number
#define POT_PIN A0

// Array parameters
#define ARRAY_SIZE 50       // Number of sample points
int potValues[ARRAY_SIZE];  // Array to store samples
int readIndex = 0;          // Keeps track of which sample we are reading

//=============================================================
// SETUP
void setup() {
  // Start serial connection
  Serial.begin(9600);

  // Fill array with initial potentiometer values
  for (int i = 0; i < ARRAY_SIZE; i++)
    potValues[i] = analogRead(POT_PIN);
}

//=============================================================
// LOOP
void loop() {
  // 1.  Read current potentiometer value
  int currentValue = analogRead(POT_PIN);
  potValues[readIndex] = currentValue;

  // 2. Increment read index
  readIndex++;
  if (readIndex > ARRAY_SIZE - 1) readIndex = 0;  // Set to 0 if exceeds array size

  // 3. Add all array values together
  unsigned long summedValues = 0;
  for (int i = 0; i < ARRAY_SIZE; i++) {
    summedValues += potValues[i];
  }

  // 4. Calculate Average Value
  int averageValue = summedValues / ARRAY_SIZE;

  // 5. (Optional) Send data to Serial Monitor

  Serial.print("Current Value: " + String(currentValue) + "\t");
  Serial.print("Average Value: " + String(averageValue));
  Serial.println();
}
