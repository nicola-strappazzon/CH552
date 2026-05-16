# Microcontroller CH552G by a hobbyist

This is a fascinating, enhanced, and well-equipped 8-bit microcontroller, available at an incredibly low cost (around $1), designed and manufactured in China by [Jiangsu Heng Qin Ltd. (WCH)](http://www.wch-ic.com). For now, we will focus on the [CH552G](https://www.wch-ic.com/products/CH552.html), which is based on the E8051 architecture. One of the most appealing features of this MCU is its USB port and a 24MHz internal oscillator, among other functionalities. Programming it requires a strong foundation in [MCS-51/80C51](https://en.wikipedia.org/wiki/MCS-51). The manufacturer provides a [package with a wide variety of source codes](https://www.wch.cn/downloads/CH552EVT_ZIP.html). There are different package options and versions of the MCU, such as the CH551, CH552, CH554, and CH559. The USB port, with its multiple functions, allows for easy program uploads, posing no risk as it is a native feature. In my personal opinion, this microcontroller is ideal for hobbyists working on simple projects or for those with a curious mindset.

A major difference of this microcontroller compared to other microcontrollers is that it does not require an additional device for programming; the USB port is sufficient. I believe that using a push button to access the bootloader for programming adds an extra level of security.

You can purchase the MCUs from the official store on [AliExpress](https://wchofficialstore.es.aliexpress.com/store/1100367542) or at [LCSC](https://www.lcsc.com).

<p align="center">
	<img src="/assets/system_block_diagram.png">
</p>

For example, an MCU from the AT89LP51 family offers fewer features and costs three times more compared to the CH55X family. Of course, the support community for Microchip is much larger and more established compared to WCH’s, which is just starting to grow. However, the key is having good official documentation and a solid architecture. With patience and perseverance, great things can be achieved.

## Specifications

Here are the most relevant specifications of the MCU. For more details, refer to the [official documentation](https://www.wch-ic.com/products/CH552.html).

- Operates between: 5V and 3.3V.
- Includes this memories types: 16KB Code Flash, 1KB XRAM, 256B iRAM, and 128B DataFlash.
- Supports this communication protocols: USB 2.0, UART, SPI, and ISP.
- Other features: 3 timers, 2 PWM, 4 ADC, and more.
- Equipped with a Bootloader.
- Includes a 24MHz internal clock.
- Comes with a unique numeric identifier.
- Available packages: TSSOP-20, SOP-16, MSOP-10.

<p align="center">
	<img src="/assets/pinout2.png">
</p>

The pinout we are showing is basic, just to give you an idea. There are more functionalities available on the ports. Please refer to the [datasheet](/doc/datasheets/CH552.pdf) for more detailed information.

> [!IMPORTANT]
> 1. The internal 24MHz clock is not precise but in the most cases is good, you can adjust it by software using a logic analyze, otherwise you will have to use an external one.
> 2. It’s worth noting that there is a limitation with the ROM or Code Flash, as it uses an iFlash™ process, which can be programmed approximately 10,000 times before the Flash memory may begin to degrade or fail. However, this value can vary > slightly depending on factors such as operating temperature and proper handling of write cycles. In any case, it is enough.

## Minimum Schematic

Use the following components to build the minimum circuit:

- One CH552G microcontroller.
- Two 100nF capacitors.
- Two 10K resistors.
- Two 1K resistors.
- Two push buttons: one for boot and one for reset.

![](/assets/minimal_schematic.jpg)

On the breadboard, it should look like this:

![](/assets/minimal_protoboard.jpg)

## Source Code

This repository contains a collection of example source codes written in C to get started. All the listed examples have been thoroughly tested to ensure they function correctly.

- [adc](/src/adc) Captures voltage variations through an input port.
- [blink](/src/blink) Uses an output port to turn an LED on and off.
- [bootloader](/src/bootloader) Forces the MCU to enter bootloader mode by default.
- [button & led rgb](/src/button_led_rgb) Interacts with a button and an RGB LED to change its color.
- [button](/src/button) Uses one input port for a button and another output port for the LED.
- [cdc](/src/cdc) Sends and receives messages via the UART protocol.
- [data flash](/src/data_flash) Saves the last state in persistent memory.
- [DHT11](/src/dht11) Read DHT11 sensor and print to OLED module.
- [fade](/src/fade) Uses PWM to fade a LED on and off.
- [oled module](/src/ssd1306) Simple usage of an OLED module with I2C.
- [pwm](/src/pwm) Hardware PWM fade on P3.0 using the PWM1 peripheral.
- [unique id](/src/unique_id) Reads the chip unique serial, print it over USB-CDC.
- [USB/cdc tx](/src/usb/cdc/tx) Sends messages via the USB port.
- [USB/cdc echo](/src/usb/cdc/rx) Echoes back bytes received over USB-CDC.

## Documentation

This is basic documentation to help you compile and upload firmware to the MCU, including the datasheet, relevant links, and much more.

- [SDCC (Small Devices C Compiler)](/doc/sdcc.md) Explains how to install and use the compiler.
- [Bootloader](/doc/flash.md) The MCU has a bootloader, and you need to know how to enter it to upload the firmware.
- [Datasheet](/doc/datasheets/CH552.pdf) Technical documentation from the manufacturer.

## Related Projects

- [CH334 - HUB USB 2.0](https://github.com/nicola-strappazzon/CH334)
- [CH340 - USB 2.0 to Serial](https://github.com/nicola-strappazzon/CH340)
- [CH9141 - Bluetooth Serial Transparent](https://github.com/nicola-strappazzon/CH9141)

## Third-Party Projects

- [Adafruit CH552 QT Py](https://learn.adafruit.com/adafruit-ch552-qt-py/overview)
- [English Docs for CH559 Microcontroller](https://kprasadvnsi.github.io/CH559_Doc_English)
- [Small Devices Arduino for ch55x devices](https://github.com/DeqingSun/ch55xduino)
- [Arduino Board Package to Debug Uno/ATmega328P with CH552 debugger in Arduino IDE 2.0.0](https://github.com/DeqingSun/unoDebugTestPackage)
