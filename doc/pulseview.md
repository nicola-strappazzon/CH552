# PulseView

[PulseView](https://sigrok.org/wiki/PulseView) is open-source software for capturing and decoding logic signals. These examples use a [nanoDLA](https://github.com/wuxx/nanoDLA). Complete the [driver setup](logic_analyze.md) first if needed.

## Windows

Run in PowerShell:

```powershell
winget install pulseview
winget install --id=Microsoft.VCRedist.2010.x64 -e
```

Open PulseView and select `sigrok FX2 LA (8ch)`:

![Select the logic analyzer](/assets/doc/pulseview/pulseview01.png)

## Arch Linux

```bash
sudo pacman -Syu pulseview
```
