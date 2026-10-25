# USB CDC echo

## Description

Echo each byte received through the native USB serial port.

## Schematic

No example schematic is included. See the [minimum circuit](/README.md#minimum-circuit).

## Features

- USB CDC virtual serial port.
- Receives with `USBReadAvailable()` and `USBRead()`.
- Sends replies with `USBWrite()` and `USBFlush()`.

## Additional information

Flash the firmware, open the serial port, and type characters. Each byte sent should come back. The firmware ignores the selected baud rate.

Use `/dev/ttyACM0` on Linux, the matching `/dev/tty.usbmodem*` device on macOS, or the assigned COM port on Windows. The actual port name may differ.
