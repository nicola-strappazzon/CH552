# Logic analyzer

These notes cover the [nanoDLA](https://github.com/wuxx/nanoDLA) on Windows 11. This driver setup is not needed on macOS or Linux. Use [PulseView](pulseview.md) to capture signals.

Connect the analyzer and open Device Manager. It may appear as `fx2lafw` under `Other devices`.

![Device Manager before driver installation](/assets/doc/logic_analyze/windows01.png)

Open Zadig, select the analyzer, and install the driver:

![Select the device in Zadig](/assets/doc/logic_analyze/windows02.png)

![Driver selection](/assets/doc/logic_analyze/windows03.png)

![Driver installation](/assets/doc/logic_analyze/windows04.png)

No restart is needed. The analyzer should now appear under `Universal Serial Bus devices` in Device Manager.
