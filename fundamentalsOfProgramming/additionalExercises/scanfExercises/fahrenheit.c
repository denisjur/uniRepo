#include <stdio.h>

int main() {

  // Declarăm variabilele
  float f, c;

  // Tipărim un mesaj pentru input
  printf("Introduceti temperatura in Celsius: ");
  scanf("%f", &c); // Citim temperatura in Celsius

  // Formula de conversie
  f = (c * 9 / 5) + 32;

  // Afișarea rezultatului
  printf("%.2f grade Celsius sunt %.2f grade Fahrenheit\n", c, f);
  return 0;
}

