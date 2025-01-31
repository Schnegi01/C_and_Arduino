default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega8 -c -o $(file).o $(file).c
	avr-gcc -o $(file).bin $(file).o
	avr-objcopy -O ihex -R .eeprom $(file).bin $(file).hex
	sudo avrdude -v -v -v -F -V -c avrisp -p m8 -P /dev/ttyUSB0 -b 19200 -U flash:w:$(file).hex

