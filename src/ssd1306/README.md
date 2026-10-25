# SSD1306 OLED

## Description

Write text to a 128 × 64 monochrome I2C OLED. The tested 0.96-inch module uses an SSD1315 controller.

## Schematic

![OLED circuit](/assets/src/ssd1306/schematic.png)

![OLED breadboard](/assets/src/ssd1306/protoboard.jpeg)

## Features

- Software I2C through the shared driver.
- Text output without a full-screen buffer.
- Driver intended for SSD1306, SSD1309, and SSD1315 modules.

## Additional information

The schematic shows the OLED connection; add the [minimum MCU circuit](/README.md#minimum-circuit). Check your module's supply voltage before connecting it.

A full 128 × 64 monochrome buffer needs 1024 bytes, which uses all of the CH552's XRAM. This driver writes directly to the display instead.
