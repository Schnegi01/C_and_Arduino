#include <avr/io.h>
#include <util/delay.h>

int main() {
  // set PB5 to output
  DDRB = DDRB | (1 << DDB5);

  while (1) {
    // turn on led on pin 13 / PORTB5
    PORTB = PORTB | (1 << PORTB5);

    _delay_ms(1000);

    // turn of led on pin 13 / PORTB5

    PORTB = PORTB & ~(1 << PORTB5);
    
  } 

  return 0;
}
