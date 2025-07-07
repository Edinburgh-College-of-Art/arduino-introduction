//===================================================================
// File: LED_Blink.ino
//
// Description:
// - Basic blink sketch.
// - Essentially the same sketch as found in:
//              File > Examples > 01.Basics > Blink
//
// Pinout:
//
// GND <--- LED <--- 220Ω <--- D2
//
// This code is in the public domain.
//===================================================================

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