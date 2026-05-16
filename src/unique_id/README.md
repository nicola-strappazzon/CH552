# Chip Unique ID over USB CDC

Reads the per-chip serial that WCH burns into the **Configuration Information area** (`0x3FF8`–`0x3FFF` in code flash, see Memory Structure in the datasheet) and streams it to the host over the native USB port as a virtual serial (CDC). The area is 8 bytes wide and is accessed with a normal `__code` pointer in SDCC.

Unlike the UART-based examples, this one needs **no extra hardware**: just plug the CH552 into your computer's USB port and the MCU enumerates as a serial port.

## How to read the output

After flashing and re-plugging, the device appears as a CDC ACM serial. Open it with any terminal — the line coding is ignored by the firmware so the baud rate does not matter:

- Linux: `screen /dev/ttyACM0` (or `minicom`, `picocom`, etc.)
- macOS: `screen /dev/tty.usbmodem*`
- Windows: any COM terminal pointing at the new COM port.

Expected output, one line per second, with a monotonically increasing counter:

```
0 - CH552G Unique ID: 1A2B3C4D5E6F7080
1 - CH552G Unique ID: 1A2B3C4D5E6F7080
2 - CH552G Unique ID: 1A2B3C4D5E6F7080
...
```

The eight hex bytes will differ from chip to chip — run it on two MCUs side-by-side to confirm.

## Notes

- The USB stack (`usb.c`, `usb.h`, `config.h`) is the same as in [`../usb/cdc/tx`](../usb/cdc/tx), copied here so the example is self-contained. Strings in `config.h` were tweaked (Product `CH552 UID`, Serial `UNIQUEID`) so the device shows up under a recognizable name.
- **Treat the Configuration Information area as read-only.** It sits in Code Flash, which is an iFlash™ process rated for only ~200 program cycles at 5 V (see section 6.2 of the datasheet) and lives right next to the USB bootloader at `0x3800`–`0x3FF7`. A bad write would burn endurance, can overwrite the factory unique serial, and risks bricking the USB ISP. If you need writable per-device data, use the DataFlash (`0xC000`–`0xC07F`) — see the [`data_flash`](../data_flash) example.
