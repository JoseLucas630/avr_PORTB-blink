default: 
	avr-gcc -Os -mmcu=atmega328p -c -o main.o main.c
	avr-gcc -o main.bin main.o
	avr-objcopy -O ihex -R .eeprom main.bin main.hex
	avrdude -F -V -c arduino -p ATMEGA328P -P COM3 -b 115200 -U flash:w:main.hex