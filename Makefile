default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega8 -c -o seven_segment.o seven_segment.c
	avr-gcc -o seven_segment.bin seven_segment.o
	avr-objcopy -O ihex -R .eeprom seven_segment.bin seven_segment.hex
	sudo avrdude -v -v -v -F -V -c avrisp -p m8 -P /dev/ttyUSB0 -b 19200 -U flash:w:seven_segment.hex

