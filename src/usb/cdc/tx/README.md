# USB CDC transmit

## Description

Send a counter and greeting through the native USB serial port.

## Schematic

No example schematic is included. See the [minimum circuit](/README.md#minimum-circuit).

## Features

- USB CDC virtual serial port.
- Repeated text output.
- No USB-to-UART adapter needed.

## Additional information

Open the serial port in a terminal after flashing. The firmware ignores the selected baud rate.

![CoolTerm output](/assets/src/usb/cdc/tx/CoolTerm.png)

See [USB in a NutShell](https://www.beyondlogic.org/usbnutshell/usb1.shtml) for an introduction to USB.
