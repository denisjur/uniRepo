#include <stdio.h>

int main () {
  
  // Arithmetic Operators
 
  // Addition: +
  // Subtraktion: -
  // Multiplication: *
  // Division: /
  // Modulus: % (This gives you the remainder of any devision)
  // Increment: ++
  // Decrement: ++

  int x = 5;
  int y = 2;
  x++;

  int result = x+y;
  printf("%d + %d = %d\n", x, y, result);
  
  // La impartire trebuie sa ai grija cand imparti cu integers. Trebuie cand imparti cu integers sa faci rezultatul un float si impartitorul un float!

  int a = 5;
  float b = 2;

  float res2 = a / b;
  printf("%d / %.2f = %.2f\n", a, b, res2);
  return 0;
};
