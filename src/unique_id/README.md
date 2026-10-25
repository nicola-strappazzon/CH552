# Chip ID over USB CDC

## Description

Read eight bytes from the factory configuration area and send them over USB serial.

## Schematic

No example schematic is included. See the [minimum circuit](/README.md#minimum-circuit).

## Features

- Reads code addresses `0x3FF8`–`0x3FFF`.
- Sends a counter and hexadecimal bytes once per loop.
- Uses native USB with no UART adapter.

## Additional information

Open the device in a serial terminal after flashing and reconnecting. The firmware ignores the selected baud rate. Port names usually start with `/dev/ttyACM` on Linux or `/dev/tty.usbmodem` on macOS; Windows uses a COM port.

Example output:

```text
0 - CH552G Unique ID: 1A2B3C4D5E6F7080
1 - CH552G Unique ID: 1A2B3C4D5E6F7080
```

The bytes shown are placeholders. Keep the configuration area read-only. The example uses the shared USB stack in `inc` and local USB strings in `config.h`. Use [data flash](/src/data_flash) for writable settings.
