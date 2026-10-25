# Hardware PWM fade

## Description

Gradually brighten and dim an LED on P3.0 using PWM1.

## Schematic

Use the [fade schematic](/src/fade#schematic). Connect the LED from VCC through a 220–470 Ω resistor to P3.0.

## Features

- 8-bit duty value from 0 to 255.
- PWM1 remapped from P1.5 to P3.0.
- Hardware generates the waveform without a timer interrupt.

## Additional information

`PWM_DATA1` sets the duty value, `PWM_CK_SE` sets the clock divider, and `PWM_CTRL` enables the output and selects polarity.

The example uses active-low output for an LED connected to VCC. For an LED connected to GND, clear `PWM1_POLAR` in the `PWM_CTRL` assignment. The main loop updates brightness every delay step.
