#include <stdio.h>

int main() {
  unsigned long long int number_1 = 0;
  unsigned long long int number_2 = 1;
  for (int i = 0; i < 100; i++) {
    unsigned long long int number_3 = number_1 + number_2;
    printf("%d: %llu\n", i + 2, number_3);
    number_1 = number_2;
    number_2 = number_3;
  }
  return 0;
}

