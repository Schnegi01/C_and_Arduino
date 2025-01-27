default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega8 -c -o hello_arduino.o hello_arduino.c
	avr-gcc -o hello_arduino.bin hello_arduino.o
	avr-objcopy -O ihex -R .eeprom hello_arduino.bin hello_arduino.hex
	sudo avrdude -F -V -c arduino -p ATMEGA8 -P /dev/ttyUSB0 -b 115200 -U flash:w:hello_arduino.hex
