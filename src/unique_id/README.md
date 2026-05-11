# Chip Unique ID over USB CDC

Reads the factory-programmed identifiers of the CH552 and streams them to the host over the native USB port as a virtual serial (CDC).

Two pieces of identification are exposed by the chip:

1. **CHIP_ID register** (SFR `0xA1`, read-only outside safe mode): a 1-byte model code. On the CH552 it always returns `0x52`.
2. **Configuration Information area** (`0x3FF8`–`0x3FFFh` in program flash, see Memory Structure in the datasheet): 8 bytes of factory data that contain the per-chip unique serial. Read with normal code-memory accesses (`__code` pointer in SDCC).

Unlike the UART-based examples, this one needs **no extra hardware**: just plug the CH552 into your computer's USB port and the MCU enumerates as a serial port.

## How to read the output

After flashing and re-plugging, the device appears as a CDC ACM serial. Open it with any terminal at any baud (line coding is ignored by the firmware):

- Linux: `screen /dev/ttyACM0 9600` (or `minicom`, `picocom`, etc.)
- macOS: `screen /dev/tty.usbmodem* 9600`
- Windows: any COM terminal pointing at the new COM port.

Expected output, repeated every ~2 s:

```
CH552 Unique ID
---------------
Model (CHIP_ID): 0x52
Config info @0x3FF8: XX-XX-XX-XX-XX-XX-XX-XX
```

The eight `XX` bytes will differ from chip to chip — run it on two MCUs side-by-side to confirm.

## Notes

- The USB stack (`usb.c`, `usb.h`, `config.h`) is the same as in [`../usb/cdc/tx`](../usb/cdc/tx), copied here so the example is self-contained. Strings in `config.h` were tweaked (Product / Serial) so the device shows up under a recognizable name.
- The first print is delayed ~1.5 s after `USBInit()` to give the host time to enumerate before any data is sent.
- **Treat the Configuration Information area as read-only.** It sits in Code Flash, which is an iFlash™ process rated for only ~200 program cycles at 5 V (see section 6.2 of the datasheet) and lives right next to the USB bootloader at `0x3800`–`0x3FF7`. A bad write would burn endurance, can overwrite the factory unique serial, and risks bricking the USB ISP. If you need writable per-device data, use the DataFlash (`0xC000`–`0xC07F`) — see the [`data_flash`](../data_flash) example.
