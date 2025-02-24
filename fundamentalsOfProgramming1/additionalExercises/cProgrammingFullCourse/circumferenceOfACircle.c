#include <stdio.h>
#include <math.h>

int main (){
  
  const double PI = 3.141592;
  double r;
  double circumference;

  printf("Geben Sie den Radius des Kreises an:\n");
  scanf("%lf", &r );

  while (getchar() != '\n');
  
  circumference = 2*r*PI;
  printf("Der Umfang beträgt: %.2lf\n", circumference);
  return 0;
};
