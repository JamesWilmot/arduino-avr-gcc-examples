all: lcd-hello-world.hex

lcd-hello-world.o: lcd-hello-world.c
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o lcd-hello-world.o lcd-hello-world.c

lcd.o: lcd.c
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o lcd.o lcd.c

# Use GCC to link main function into a complete binary
lcd-hello-world.elf: lcd-hello-world.o
	avr-gcc -mmcu=atmega328p $< lcd.o -o $@

# Convert binary to an Intel HEX file for upload
lcd-hello-world.hex: lcd-hello-world.elf
	avr-objcopy -O ihex -R .eeprom $< $@

# Download the HEX to the board
.PHONY: program
program: lcd-hello-world.hex
	avrdude -p atmega328p -c arduino -P ${ARDUINO_PORT} -U flash:w:$<:i
