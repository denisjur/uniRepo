#include <stdio.h>
#include <math.h> //Diese Bibliothek enthält viele mathematische funktionen.

int main () {
  
  double A = sqrt(9);  //Square root of 9
                       // float = 32 Bit -> double = 64 bit
  double B = pow(2, 3);   //2³ bzw. two to the power of 3
  int C = round (3.14);   // Rundet
  int D = ceil(3.14);     // RUndet hoch
  int E = floor(3.99);    // RUndet runter
  double F = fabs(-100);  // Gibt den Betrag an
  double G = log(3);      // Logarithmus
  double H = sin(45);     //Sinus
  double I = cos(45);
  double J = tan (45);
  
  printf("%lf\n", G);

  return 0;
};














