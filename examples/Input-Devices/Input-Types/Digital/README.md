# Digital Inputs

<img src="images/Digital.png" width="800">

## Contents

- [Introduction](#introduction)
- [Usage](#usage)
    - [Configuring Input Pins](#configuring-input-pins)
    - [Reading a Digital Input](#reading-a-digital-input)

## Introduction

Digital inputs are one of the most commonly used types of inputs in Arduino projects. Digital inputs are inputs that send discrete signals, representing binary states such as on/off, true/false, open/closed etc to the Arduino. This is in contrast to [analog inputs](/examples/Input-Devices/Analog/) that send continuous signals - e.g. a voltage anywhere between 0V-5V. A common example of a digital input is a [button](/examples/Input-Devices/Digital/Buttons/) as it can only exist in two discrete states - on/pressed/closed and off/released/open.

When an Arduino reads a digital signal, it uses its I/O (Input/Output) pins, which can be configured to receive digital data. These pins can detect two distinct states: a <code>HIGH</code> (1) state, representing 5V (or 3.3V depending on the Arduino board), and a <code>LOW</code> (0) state, representing 0V (no signal). This data can then be used by the Arduino to trigger predetermined events in its code.

On an Arduino board, digital pins are typically the pins numbered sequentially, starting from 0 and going up to 13 or higher, although this can vary depending on the board you are using. Larger boards - like the UNO - label the digital pins on the PCBs' silkscreen. For smaller boards - like the Nano - you may need to find a pinout diagram from the [Arduino Docs](https://docs.arduino.cc/hardware/) to tell you which pins are digital I/O pins.

## Usage
### Configuring Input Pins

Before using a pin as a digital input, you need to configure it using the <code>pinMode()</code> function. The <code>pinMode()</code> function defines the behavior of a pin: either as an input or output.

```cpp
pinMode(2, INPUT); // Set pin 2 as a digital input
```

### Reading a Digital Input

To read a digital input on Arduino, we use the <code>digitalRead()</code> function. This function reads the state of a pin that has been set as an input, and returns either <code>1</code> or <code>0</code> (representing <code>HIGH</code> and <code>LOW</code> respectively) based on the voltage applied to the pin.

```cpp
int buttonPin = 2;   // Pin connected to the button
int buttonState = 0; // Variable to store the button state

void setup() {
  Serial.begin(9600);        // Start serial communication
  pinMode(buttonPin, INPUT); // Set the button pin as an input
}

void loop() {
  buttonState = digitalRead(buttonPin); // Read the button state
  Serial.println(buttonState);          // Print the state to the serial monitor
}
```