#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#ifndef BAUD
#define BAUD 9600
#endif

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <util/setbaud.h>

void uart_init() {
    // Upper and lower bytes of the calculated prescaler value for baud.
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

    // Configure data frame size to 8-bits.
    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);

    // Configure to enable transmitter.
    UCSR0B = _BV(TXEN0);
}

void uart_putchar(char c) {
    // Wait until the register to write to is free.
    loop_until_bit_is_set(UCSR0A, UDRE0);

    // Write the byte to the register.
    UDR0 = c;
}

void uart_putstr(char *data) {
    // Loop until end of string writing char by char.
    while(*data){
      uart_putchar(*data++);
    }
}

int main() {
    uart_init();

    while(1) {
        uart_putstr("hello, world\n");
        _delay_ms(5000);
    }

    return 0;
}
