# UART serial

## Description

Send and receive text through a [CH340](https://github.com/nicola-strappazzon/CH340) USB-to-UART adapter.

## Schematic

No example schematic is included. See the [minimum circuit](/README.md#minimum-circuit).

## Features

- UART0 at 9600 baud.
- Sends a greeting at startup.
- Echoes received characters.

## Additional information

The directory is named `cdc`, but this example uses UART. For native USB serial, see [USB CDC TX](/src/usb/cdc/tx) and [USB CDC RX](/src/usb/cdc/rx).
