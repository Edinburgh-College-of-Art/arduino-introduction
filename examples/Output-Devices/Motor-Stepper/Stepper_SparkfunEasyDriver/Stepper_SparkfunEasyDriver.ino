// Declare pin locations
#define STEP 2
#define DIR 3
#define MS1 4
#define MS2 5
#define EN 6
  
void setup() {
  // Initialise pins as OUTPUT
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(EN, OUTPUT);
    
  // Set pins to default states before starting
  digitalWrite(STEP, LOW);
  digitalWrite(DIR, LOW);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  digitalWrite(EN, HIGH);
    
  // Set DIR pin to change direction:
  // LOW = "Forwards"
  // HIGH = "Backwards"
  digitalWrite(DIR, LOW);
}
  
void loop() {
  //Trigger one step forward
  digitalWrite(STEP, HIGH);  
  delay(1);
    
  // Pull step pin low so it can be triggered again
  digitalWrite(STEP, LOW);  
  delay(1);
}