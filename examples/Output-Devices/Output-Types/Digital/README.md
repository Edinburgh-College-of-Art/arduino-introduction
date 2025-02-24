# Digital Output

<img src="images/Digital.png" width="800">

## Contents
- [Introduction](#introduction)
- [Usage](#usage)
    - [Configuring Output Pins](#configuring-output-pins)
    - [Writing a Digital Output](#writing-a-digital-output)

## Introduction
Digital outputs are used to send binary signals (on/off) from the Arduino to external devices, such as LEDs, relays, or motors. Unlike digital inputs that read states (on/off), digital outputs control the state of a device by sending a <code>HIGH</code> (1) or <code>LOW</code> (0) signal to a connected component. The <code>HIGH</code> state is typically 5V (or 3.3V depending on the Arduino board), while <code>LOW</code> is 0V.

For example, you could use a digital output to turn an [LED](/examples/Output-Devices/LED-DIP/) on or off, or to activate a relay. These outputs allow you to control various devices in your Arduino projects.

## Usage
### Configuring Output Pins
To configure a pin as a digital output, use the <code>pinMode()</code> function. This function defines the behavior of a pin: either as an input or output.

``` cpp
pinMode(13, OUTPUT); // Set pin 13 as a digital output
```

### Writing a Digital Output
To write a digital output, use the <code>digitalWrite()</code> function. This function sets the state of a pin to either <code>HIGH</code> (on) or <code>LOW</code> (off).

``` cpp
int ledPin = 13;   // Pin connected to the LED

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
}

void loop() {
  digitalWrite(ledPin, HIGH); // Turn the LED on
  delay(1000);                // Wait for 1 second
  
  digitalWrite(ledPin, LOW);  // Turn the LED off
  delay(1000);                // Wait for 1 second
}
```