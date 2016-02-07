# About:

An example of simple GPIO control of pin 57 of NVidia Jetson TK1 development board based on sysfs mechanism.

# Installation:

	git clone https://github.com/dkoguciuk/jetson_i2c.git
	cd jetson_i2c
	mkdir build && cd build
	cmake ../ && make
	sudo ./jetson_i2c
