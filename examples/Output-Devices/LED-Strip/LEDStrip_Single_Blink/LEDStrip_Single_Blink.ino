// Define LED pin number
int ledPin = 2;

void setup() {
    // Init pin as OUTPUT
    pinMode(ledPin, OUTPUT);
}

void loop() {
    // Turn on LED
    digitalWrite(ledPin, HIGH);
    delay(1000); // Wait for 1 second
    
    // Turn off LED
    digitalWrite(ledPin, LOW);
    delay(1000); // Wait for 1 second 
}