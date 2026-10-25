# DHT11 temperature and humidity sensor

## Description

Read a DHT11 sensor and show temperature and humidity on an OLED.

## Schematic

![DHT11 circuit](/assets/src/dht11/schematic.png)

![DHT11 breadboard](/assets/src/dht11/protoboard.jpeg)

## Features

- Sensor data pin on P3.2.
- Single-wire protocol with a 40-bit response.
- Checks the response checksum.

## Additional information

The MCU starts a reading with a low pulse of at least 18 ms. The sensor replies with low and high pulses of about 80 µs each, then sends humidity, temperature, and checksum bytes.

![DHT11 signal capture](/assets/doc/pulseview/dht11_02.png)

Check the clock and delays with a [logic analyzer](/doc/logic_analyze.md). See the [datasheet](/doc/datasheets/DHT11.pdf) for voltage and accuracy limits.
