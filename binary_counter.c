#include <avr/io.h>
#include <util/delay.h>
#include <math.h>

int main() {
  DDRB = 255;
  PORTB |= (1 << PORTB5);

  int led_count = 4;

  while (1) {
    for (int i = 0; i < pow(2, led_count); i++) {
      PORTB = (PORTB & (255 << led_count)) | i;

      _delay_ms(1000);
    }
  } 
  return 0;
}

