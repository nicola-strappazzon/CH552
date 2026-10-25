# Blink

## Description

Turn an LED on and off on P3.0.

## Schematic

![Blink circuit](/assets/src/blink/schematic.png)

## Features

- One LED output.
- Uses a blocking delay between changes.

## Additional information

The loop toggles the LED:

```c
LED = !LED;
delay_ms(1000);
```

You can also set `LED` to `0` and `1` with a delay between each change.
