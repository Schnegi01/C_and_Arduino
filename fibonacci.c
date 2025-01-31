#include <stdio.h>

int main() {
  long int number_1 = 0;
  long int number_2 = 1;

  printf("0: %d\n1: %d\n", number_1, number_2);

  for (int i = 0; i < 50; i++) {
    long int number_3 = number_1 + number_2;
    printf("%d: %ld\n", i + 2, number_3);
    number_1 = number_2;
    number_2 = number_3;
  }
  return 0;
}

