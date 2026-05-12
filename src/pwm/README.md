# Hardware PWM

Fades an LED on **P3.0** using the CH552's built-in PWM1 peripheral. Functionally identical to the [`fade`](../fade) example, but here the waveform is produced by hardware — no Timer0 ISR, the main loop just writes the duty value.

## How it works

The CH552 has two 8-bit PWM channels (PWM1, PWM2). For PWM1 the relevant registers are:

| Register | Role |
|---|---|
| `PWM_CTRL` (0x9D) | enable, polarity, IRQ |
| `PWM_DATA1` (0x9C) | duty value (0–255) |
| `PWM_CK_SE` (0x9E) | clock pre-divider |
| `PIN_FUNC.bPWM1_PIN_X` | output pin remap |

By default PWM1 comes out on **P1.5**; setting `bPWM1_PIN_X` in `PIN_FUNC` remaps it to **P3.0**. This example uses the remap so the same LED used by the [`fade`](../fade) example can be reused without any wiring change.

PWM frequency is:

```
F_pwm = F_sys / (256 * (PWM_CK_SE + 1))
```

At `F_sys = 12 MHz` and `PWM_CK_SE = 0`, that's ~46.8 kHz — well above audible range and visually smooth on an LED.

## Why use hardware PWM instead of the software version

| | `fade` (software) | this example (hardware) |
|---|---|---|
| Timer / ISR | Timer0 ISR at ~20 kHz | none |
| Resolution | 6-bit (0–63) | 8-bit (0–255) |
| Frequency | ~312 Hz | ~46.8 kHz |
| CPU usage during fade | ISR fires constantly | zero — peripheral autonomous |
| Code size | ~1 ISR + counters | a few register writes |

The hardware version frees the CPU and Timer0 for other work, and gives you 4× the duty resolution.

## Polarity

The current `fade` schematic wires the LED from VCC through a resistor to P3.0 (current sinking). To match that polarity, this example sets `bPWM1_POLAR = 1`: idle high, active low. If you wire the LED from P3.0 through a resistor to GND (current sourcing), clear that bit so it's active high.

## Hardware

Same wiring as [`fade`](../fade):

- LED + 220–470 Ω resistor between **VCC** and **P3.0**.

That's it — no extra components.
