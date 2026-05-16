# USB CDC Echo (RX + TX)

This example enumerates the CH552G as a USB CDC serial device and echoes back any byte the host writes to the virtual COM port.

It exercises both directions of the bulk endpoint:

- `USBReadAvailable()` reports how many bytes are pending from the last OUT packet.
- `USBRead()` returns the next byte and re-arms the OUT endpoint with `ACK` once the packet is drained.
- `USBWrite()` appends to the IN buffer and `USBFlush()` hands the packet to the host.

## Test it

1. Flash the firmware (`make flash`).
2. Open the virtual COM port at any baud rate (the CDC line coding is informational; the device ignores it):
   - macOS / Linux: `screen /dev/tty.usbmodem* 115200` (or `picocom`, `minicom`).
   - Windows: any serial terminal pointed at the new COM port.
3. Type characters — each byte you send should come straight back.
