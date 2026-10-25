# CH552G examples

C examples, hardware designs, and notes for the WCH CH552G, an 8-bit microcontroller based on the 8051 architecture. It has native USB and a built-in bootloader, so firmware can be uploaded without a separate programmer.

See the [datasheet](/doc/datasheets/CH552.pdf) and [WCH examples](https://www.wch.cn/downloads/CH552EVT_ZIP.html).

<p align="center">
	<img src="/assets/system_block_diagram.png">
</p>

## Specifications

- 3.3 V or 5 V operation.
- 16 KB code flash, 1 KB XRAM, 256 bytes internal RAM, and 128 bytes data flash.
- USB, UART, and SPI.
- Three timers, two PWM channels, and four ADC inputs.
- Built-in bootloader and 24 MHz internal oscillator.
- Factory chip identifier.

<p align="center">
	<img src="/assets/pinout2.png">
</p>

See the datasheet for all pin functions and package options. Check the clock timing for applications that need accurate delays.

Code flash is rated for about 200 programming cycles at 5 V. Data flash is rated for about 10,000 erase/write cycles; spread writes across it to reduce wear.

## Minimum circuit

- One CH552G.
- Two 100 nF capacitors.
- Two 10 kΩ resistors.
- Two 1 kΩ resistors.
- Two buttons: boot and reset.

![Minimum circuit](/assets/minimal_schematic.jpg)

![Breadboard circuit](/assets/minimal_protoboard.jpg)

## Examples

- [ADC](/src/adc): read a potentiometer and send values over UART.
- [Blink](/src/blink): blink an LED.
- [Bootloader](/src/bootloader): enter the bootloader at startup.
- [Button](/src/button): control an LED with a button.
- [Button and RGB LED](/src/button_led_rgb): change color with a button.
- [UART](/src/cdc): send and receive text through a CH340 adapter.
- [Data flash](/src/data_flash): save the last LED color.
- [DHT11](/src/dht11): show temperature and humidity on an OLED.
- [DHT20](/src/dht20): wiring notes; sensor code is not implemented yet.
- [DS1307](/src/ds1307): show the date and time on an OLED.
- [Fade](/src/fade): fade an LED with software PWM.
- [Hardware PWM](/src/pwm): fade an LED with PWM1.
- [SSD1306](/src/ssd1306): write text to an I2C OLED.
- [Unique ID](/src/unique_id): send chip configuration bytes over USB CDC.
- [USB CDC TX](/src/usb/cdc/tx): send text over USB.
- [USB CDC RX](/src/usb/cdc/rx): echo bytes received over USB.
- [Watchdog](/src/watchdog): reset after a simulated hang.

## Documentation

- [SDCC](/doc/sdcc.md): install the compiler and build examples.
- [Bootloader](/doc/bootloader.md): enter upload mode.
- [Flash](/doc/flash.md): upload firmware with wchisp.
- [Hardware](/hdw): KiCad designs.
- [Links](/doc/links.md): related resources.

## Related projects

- [CH334 - USB 2.0 hub](https://github.com/nicola-strappazzon/CH334)
- [CH340 - USB to serial](https://github.com/nicola-strappazzon/CH340)
- [CH9141 - Bluetooth serial](https://github.com/nicola-strappazzon/CH9141)

## Third-party projects

- [Adafruit CH552 QT Py](https://learn.adafruit.com/adafruit-ch552-qt-py/overview)
- [CH559 documentation in English](https://kprasadvnsi.github.io/CH559_Doc_English)
- [ch55xduino](https://github.com/DeqingSun/ch55xduino)
- [CH552 debugger for Arduino Uno](https://github.com/DeqingSun/unoDebugTestPackage)
