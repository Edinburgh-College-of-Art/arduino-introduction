# Analog Inputs

<img src="images/Analog.png" width="800">

## Contents

- [Introduction](#introduction)
- [Usage](#usage)
    - [Configuring Input Pins](#configuring-input-pins)
    - [Reading a Analog Input](#reading-a-analog-input)

## Introduction

Analog inputs are essential in many Arduino projects that require the reading of continuous data. Unlike [digital inputs](/examples/Input-Devices/Digital/), which provide discrete signals (<code>HIGH</code>/<code>LOW</code>), analog inputs can send a signal made of a range of voltages, typically from 0V-5V on most Arduino boards. Being able to read analog signals is ideal for devices like [potentiometers](/examples/Input-Devices/Analog/Potentiometers/) and [light sensors](/examples/Input-Devices/Analog/LDRs/), where the input value can vary smoothly and doesn't just exist as on or off.

When an Arduino reads an analog signal, it must use one of its analog input pins, which are designed to measure voltages in the range of 0V to 5V (or 0V to 3.3V on some boards). The Arduino converts this voltage into a digital value through a analog-to-digital converter (ADC). This value is typically a number between 0 and 1023 (on most boards) corresponding to the input voltage, allowing for more granular control and measurement in your projects.

On larger Arduino boards - like the UNO - analog pins are usually labeled as A0, A1, A2, etc on the PCBs' silkscreen. For smaller boards - like the Nano - you may need to find a pinout diagram from the [Arduino Docs](https://docs.arduino.cc/hardware/) to tell you which pins are analog input pins.

## Usage
### Configuring Input Pins

Unlike when using the Arduinos' digital pins, we do not need to use <code>pinMode()</code> function to set the analog pins to work as inputs. They are set to <code>INPUT</code> by default.

### Reading a Analog Input

To read an analog input on Arduino, we use the <code>analogRead()</code> function. This function reads the voltage of the signal coming in and outputs a value between 0-1023 based on the voltage being applied to the pin. A voltage of 5V will return a value of <code>1023</code> and 0V will return <code>0</code>. Any voltage in between 0V-5V will return a scaled value (i.e. 2.5V will return approx. <code>512</code>).

```cpp
int potentiometerPin = A0; // Pin connected to the potentiometer
int buttonState = 0;       // Variable to store the potentiometer state

void setup() {
  Serial.begin(9600);               // Start serial communication
}

void loop() {
  buttonState = analogRead(potentiometerPin); // Read the potentiometer state
  Serial.println(buttonState);                // Print the state to the serial monitor
}
```