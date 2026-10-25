# DHT20 temperature and humidity sensor

## Description

Wiring notes for a DHT20 I2C sensor. The sensor code is not implemented yet.

## Schematic

![DHT20 circuit](/assets/src/dht20/schematic.png)

## Features

- I2C interface.
- A newer alternative to the [DHT11](/src/dht11).

## Additional information

See the [DHT20 datasheet](/doc/datasheets/DHT20.pdf) and the related [AHT20 datasheet](/doc/datasheets/AHT20.pdf). The current `main.c` only initializes the MCU.
