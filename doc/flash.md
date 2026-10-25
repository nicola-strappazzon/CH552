# Flash firmware

The examples use [wchisp](https://github.com/ch32-rs/wchisp). Binaries are included in `tools/macos` and `tools/linux`. The Makefiles use the macOS binary by default.

Enter [bootloader mode](bootloader.md), then run from an example directory:

```bash
make flash
```

On Linux, from the repository root:

```bash
make -C src/blink flash WCHISP="$PWD/tools/linux/wchisp flash"
```

If Linux denies USB access, add this rule to `/etc/udev/rules.d/99-ch55x.rules`:

```udev
SUBSYSTEM=="usb", ATTR{idVendor}=="4348", ATTR{idProduct}=="55e0", MODE="0666"
```

Reload the rules and reconnect the device:

```bash
sudo udevadm control --reload-rules
```

WCH also provides a [command-line ISP tool](https://www.wch-ic.com/downloads/WCHISPTool_CMD_ZIP.html).
