# Software PWM fade

## Description

Gradually brighten and dim an LED on P3.0 using software PWM.

## Schematic

![Fade circuit](/assets/src/fade/schematic.png)

## Features

- Timer0 interrupt generates the PWM signal.
- 64 brightness levels.
- Timer1 provides blocking delays.

## Additional information

The code assumes an LED connected from VCC through a resistor to P3.0. See [hardware PWM](/src/pwm) for an example using the PWM1 peripheral.
