# Windows 11 and WSL

Build the examples in WSL. To upload firmware, share the USB device with WSL using `usbipd`.

List devices in PowerShell:

```powershell
usbipd list
```

Find the bootloader device with USB ID `4348:55e0`. Replace `3-7` below with its bus ID.

Share it from an administrator PowerShell:

```powershell
usbipd bind --busid 3-7
```

Attach it to WSL:

```powershell
usbipd attach --wsl --busid 3-7 --auto-attach
```

Use the Linux flashing command in [Flash firmware](flash.md) from WSL.
