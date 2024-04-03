#include <avr/io.h>
#include <util/delay.h>

#include "lcd.h"

#define BLINK_DELAY_MS 200

int main (void)
{
 /* set pin 5 of PORTB for output*/
 // DDRB |= _BV(DDB5);
 lcd_init();
 lcd_clear();
 lcd_return_home();
 _delay_ms(BLINK_DELAY_MS);
 lcd_puts("Hi world");
 lcd_enable_blinking();

 while(1) {
  /* set pin 5 high to turn led on */
  /*
  PORTB |= _BV(PORTB5);
  _delay_ms(BLINK_DELAY_MS);
  */
  _delay_ms(BLINK_DELAY_MS);

  /* set pin 5 low to turn led off */
   /*
  PORTB &= ~_BV(PORTB5);
  _delay_ms(BLINK_DELAY_MS);
  */
 }
}
