# Bootloader

The CH552 has a factory bootloader for uploading firmware over USB.

1. Disconnect USB.
2. Hold the boot button and reconnect USB.
3. Release the button and upload the firmware from an example directory:

```bash
make flash
```

Upload soon after connecting. The bootloader may time out and start the existing program.

To check the USB device on Linux:

```bash
lsusb
```

On macOS:

```bash
system_profiler SPUSBDataType
```

Look for USB ID `4348:55e0`. The device name may vary.
