// Define pin numbers for LED pins
// Should be PWM pins (~)
int redPin = 3;
int grnPin = 5;
int bluPin = 6;

// Set colour amount for each colour
// Should be value between 0 and 255
int redAmount = 100;
int grnAmount = 50;
int bluAmount = 195;

void setup() {
    // Init pins as OUTPUT
    pinMode(redPin, OUTPUT);
    pinMode(grnPin, OUTPUT);
    pinMode(bluPin, OUTPUT);
}

void loop() {
    // Turn on LEDs
    analogWrite(redPin, redAmount);
    analogWrite(grnPin, grnAmount);
    analogWrite(bluPin, bluAmount);
    delay(1000); // Wait for 1 second
    
    // Turn off LEDs
    analogWrite(redPin, 0);
    analogWrite(grnPin, 0);
    analogWrite(bluPin, 0);
    delay(1000); // Wait for 1 second
}