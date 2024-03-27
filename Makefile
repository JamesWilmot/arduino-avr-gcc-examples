all: blink.hex

blink.o: blink.c
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o blink.o blink.c
# Use GCC to link main function into a complete binary
blink.elf: blink.o
	avr-gcc -mmcu=atmega328p $< -o $@

# Convert binary to an Intel HEX file for upload
blink.hex: blink.elf
	avr-objcopy -O ihex -R .eeprom $< $@

# Download the HEX to the board
.PHONY: program
program: blink.hex
	avrdude -p atmega328p -c arduino -P ${ARDUINO_PORT} -U flash:w:$<:i
