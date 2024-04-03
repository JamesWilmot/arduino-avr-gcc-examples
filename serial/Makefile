all: serial.hex

serial.o: serial.c
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o serial.o serial.c
# Use GCC to link main function into a complete binary
serial.elf: serial.o
	avr-gcc -mmcu=atmega328p $< -o $@

# Convert binary to an Intel HEX file for upload
serial.hex: serial.elf
	avr-objcopy -O ihex -R .eeprom $< $@

# Download the HEX to the board
.PHONY: program
program: serial.hex
	avrdude -p atmega328p -c arduino -P ${ARDUINO_PORT} -U flash:w:$<:i
