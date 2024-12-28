#include <stdio.h>


// CONSTANT = fixed value that cannot be altered by the program during its execution
// You should always try to write Constants in UPPER CASE

int main () {
  // Daca as scrie: float pi = 3.14159;
  // As putea dupa sa il schimb asa: pi = 5;
  // Acum are Wertul de 5.
  // Ca sa nu il mai pot schimba, il fac constanta asa:
  const float PI = 3.14159;

  printf("%f\n", PI);

  return 0;
};
