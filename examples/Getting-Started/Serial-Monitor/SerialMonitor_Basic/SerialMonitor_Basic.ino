void setup() {
  // Start serial monitor
  Serial.begin(9600);
}  
  
void loop() {
  // Print some data
  Serial.print(3.14);
  Serial.println(159);
  
  // Text must be wrapped in quotation marks
  Serial.println("Hello world");
  
  // Wait for 1000ms (1 sec)
  delay(1000);
}