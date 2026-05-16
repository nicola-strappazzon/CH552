# DHT11 - Temperature and humidity sensor

[Datasheet](/doc/datasheets/DHT11.pdf)

This sensor operates between 3.3V and 5.5V, uses a proprietary "single wire" communication protocol, and its accuracy is around +/- 5 % for humidity and +/- 2C for temperature.

![](/assets/src/dht11/protoboard.jpeg)

The connection between the sensor and the MCU is very simple — you can pick any available pin; here we use P3.2:

![](/assets/src/dht11/schematic.png)

## Single wire protocol

The DHT11 uses a single wire for communication, starting with a start signal from the microcontroller: the pin is pulled low for at least 18 ms and then released (high). The sensor replies with an 80 µs low pulse followed by an 80 µs high pulse to indicate it is ready. After that, the DHT11 sends 40 bits of data (5 bytes): the first two bytes are the integer and decimal parts of the humidity, the next two are the integer and decimal parts of the temperature, and the last byte is a checksum to validate the data.

![](/assets/doc/pulseview/dht11_02.png)

**NOTE:** For communication with the sensor to work, the clock must be properly configured. Make sure to validate it with an oscilloscope or a [logic analyzer](/doc/logic_analyze.md).
