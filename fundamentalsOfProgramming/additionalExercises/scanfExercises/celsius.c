#include <stdio.h>

int main() {

  // Declarăm variabilele
  float f, c;

  // Tipărim un mesaj pentru input
  printf("Introduceti temperatura in Fahrenheit: ");
  scanf("%f", &f); // Citim temperatura in Fahrenheit

  // Formula de conversie
  c = (f - 32) * 5 / 9;

  // Afișarea rezultatului
  printf("%.2f grade Fahrenheit sunt %.2f grade Celsius\n", f, c);
  return 0;
}
