/*
Documentation:
##############

LED:
----
    ___
 _ |_A_| _
| |     | |
|F|     |B|
|_| ___ |_|
 _ |_A_| _
| |     | |
|E|     |C|
|_| ___ |_| _
   |_D_|   |P|

Encoded numbers
---------------
              ABCDEFGP
0  = ABCDEF  = 11111100 = 252
1  =  BC     = 01100000 = 96
2  = AB DE G = 11011010 = 218
3  = ABCD  G = 11110010 = 242
4  =  BC  FG = 01100110 = 102
5  = A CD FG = 10110110 = 182
6  = A CDEFG = 10111110 = 190
7  = ABC     = 11100000 = 224
8  = ABCDEFG = 11111110 = 254
9  = ABCD FG = 11110110 = 246

              ABCDEFGP
0. = ABCDEF  = 11111101 = 253
1. =  BC     = 01100001 = 97
2. = AB DE G = 11011011 = 219
3. = ABCD  G = 11110011 = 243
4. =  BC  FG = 01100111 = 103
5. = A CD FG = 10110111 = 183
6. = A CDEFG = 10111111 = 191
7. = ABC     = 11100001 = 225
8. = ABCDEFG = 11111111 = 255
9. = ABCD FG = 11110111 = 247

Pin layout
----------
Pin Segment
2   P
3   G
4   F
5   E
6   D
7   C
8   B
9   A

*/

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

