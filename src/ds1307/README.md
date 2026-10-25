# DS1307 real-time clock

## Description

Read the date and time from a DS1307 and show them on an OLED.

## Schematic

No example schematic is included. See the [minimum circuit](/README.md#minimum-circuit).

## Features

- Uses the shared RTC and OLED drivers.
- Displays the date and time once per loop.

## Additional information

Set the initial values in `main.c` and enable `rtc_set(&rtc)` to set the clock. Disable that call afterward to keep the time across MCU resets. See the [datasheet](/doc/datasheets/DS1307.pdf).
