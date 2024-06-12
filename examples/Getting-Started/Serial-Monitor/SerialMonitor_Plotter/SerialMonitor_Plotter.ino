// Create some variables to print
int value1 = 0;
int value2 = 10;

void setup() {
  // Start serial monitor
  Serial.begin(9600);
}

void loop() {
  // Print first variable
  Serial.print(value1);
  
  // Seperate with a comma and a space
  Serial.print(",");
  
  // Println second variable
  Serial.print(value2);
  Serial.println();
}