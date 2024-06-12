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