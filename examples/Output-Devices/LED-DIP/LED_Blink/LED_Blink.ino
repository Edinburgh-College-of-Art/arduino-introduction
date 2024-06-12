// Change this to the pin your LED is connected to
int ledPin = 2; 

void setup() {
    // Initialise LED pin
    pinMode(ledPin, OUTPUT);
}

void loop() {
    // LED on
    digitalWrite(ledPin, HIGH);
    delay(1000); // wait for 1 second
    
    // LED off
    digitalWrite(ledPin, LOW);
    delay(1000); // wait for 1 second
}