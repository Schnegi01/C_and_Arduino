#include <avr/io.h>
#include <util/delay.h>

int main() {
  
  PORTB |= (1 << PORTB5);

  // seven segment display numbers as ints to set register
  int seven_segment_numbers[10] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246};
  
  DDRD = 255;
  DDRB |= 3;

  while (1) {
    for (int i = 0; i < 10; i++) {
      PORTD = seven_segment_numbers[i] << 2;
      PORTB = (PORTB & ~3) | seven_segment_numbers[i] >> 6;

      _delay_ms(1000);
    }
  }
  return 0;
}

