#include <avr/io.h>
#include <util/delay.h>
#include <math.h>

int main() {
  
  PORTB |= (1 << PORTB5);

  int led_count = 4;
  
  // seven segment display numbers as ints to set register
  int seven_segment_numbers[10] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246};
  
  DDRD = 255;

  while (1) {
    for (int i = 0; i < pow(2, led_count); i++) {
      for (int led = 0; led < led_count; led++) {
        if (i & (1 << led)) {
          PORTB |= (1 << PORTB0 + led);
        }
        else {
          PORTB &= ~(1 << PORTB0 + led);
        }
      }
      if (i < 10) {
        PORTD = seven_segment_numbers[i];
      }
      _delay_ms(1000);
    }

  } 

  return 0;
}

