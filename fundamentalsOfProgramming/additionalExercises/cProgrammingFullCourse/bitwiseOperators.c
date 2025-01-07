#include <stdio.h>

int main()
{
    // BITWISE OPERATORS = special operators used in bit level programming
    //                      (knowing binary is important for this topic)

    // & = AND
    // | = OR
    // ^ = XOR
    // << = left shift
    // >> = right shift

  // Sehen wir ein paar Beispiele:
  int x = 6;   // 6  = 00000110
  int y = 12;  // 12 = 00001100
  int z = 0;   // 4  = 00000100

  z = x & y;
  printf("AND = %d\n", z);

  z = x | y;
  printf("OR = %d\n", z);

  z = x ^ y;
  printf("XOR = %d\n", z);

  z = x << 1;   // Asta schieben numarul cu o pozitie in stanga
  printf("SHIFT LEFT = %d\n", z);


    return 0;
}

