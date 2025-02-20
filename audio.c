#include <avr/io.h>
#include <util/delay.h>

/*
This program plays a german nursery rhyme called "Alle meine Entchen" on Pin 8.
It is reccomended to controll the speaker with a transistor, so the Arduino isn't damaged by the current draw, which is likly to be higher than what the Arduino can provide.

It should be said that I can't read notes and know basically nothing about making music. This is why all the durations of the notes are wrong and since I am too lazy to corect them all individually, I multiply them by 4 before I call the play_sound function. For me, writinge the right notes and durations was actually more difficult and confusing than writing the play_sound function.
*/

int main() {

  void play_sound(float frequency, float duration) {
    for (int i = 0; i < (int)(duration * frequency); i++) {
      PORTB ^= 1;
    
      for (int j = 0; j < (int)(10000 / frequency); j++){
      _delay_ms(0.1);
      }
    }
  }

  // Pin 8 for audio output
  DDRB |= 1;

  // turn on LED on pin 13
  DDRB |= 1 << 5;
  PORTB |= 1 << 5;
  
  // frequencies for the notes
  int c = 523;
  int d = 587;
  int e = 659;
  int f = 698;
  int g = 783;
  int a = 880;
  int b = 987;
  int n = 0; // brake (n for nothoing/none)

  int note_num = 29;
  
  // Alle meine Entchen
  // This are pointers purly for better readability
  int *frequencies[29] = {
    &d, &e, &f, &g, &a, &a,
    &b, &b, &b, &b, &a, &n,
    &b, &b, &b, &b, &a, &n,
    &g, &g, &g, &g, &f, &n,
    &a, &a, &a, &a, &d
  };
  // durations of the notes
  float times[29] = {
    0.125,0.125,0.125,0.125,0.25,0.25,
    0.125,0.125,0.125,0.125,0.25,0.25,
    0.125,0.125,0.125,0.125,0.25,0.25,
    0.125,0.125,0.125,0.125,0.25,0.25,
    0.125,0.125,0.125,0.125,0.25
  };

  while (1) {
    for (int i = 0; i < note_num; i++) {
      if (*frequencies[i] == 0) {
        for (int j = 0; j < times[i]; j++){
          _delay_ms(1);
        }
      }
      else {
        play_sound(*frequencies[i], times[i] * 4); // * 4 becaus all times are wrong in the times array
      }
      _delay_ms(0.1); // needed, otherwise audio is broken (no difference between notes)
    }
    _delay_ms(20000);
  }
  return 0;
}

