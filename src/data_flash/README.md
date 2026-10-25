# Data flash

## Description

Save the RGB LED color and restore it after a reset or power loss.

## Schematic

Use the [button and RGB LED schematic](/src/button_led_rgb#schematic).

## Features

- Uses the CH552G's 128-byte data flash.
- Saves the color when the button is pressed.

## Additional information

The code uses `DATA_FLASH_ADDR` (`0xC000`) and accesses data bytes at even addresses. Data flash is separate from program flash. Avoid unnecessary writes to reduce wear.
