#include <stdio.h>
#include <math.h>

int main () {

  double num1;
  double num2;
  double result;
  char operator;

  printf("\nEnter an operator (+ - * /): ");
  scanf("%c", &operator);

  printf("\nEnter number 1: ");
  scanf("%lf", &num1);

  printf("\nEnter number 2: ");
  scanf("%lf", &num2);

 switch (operator) {
    case '+':
        result = num1 + num2;
        printf("\nResult: %.2lf\n", result);
      break;
    case '-':
        result = num1 - num2;
        printf("\nResult: %.2lf\n", result);
      break;
    case '*':
        result = num1 * num2;
        printf("\nResult: %.2lf\n", result);
      break;
    case '/':
        result = num1 / num2;
        printf("\nResult: %.2lf\n", result);
      break;
    default:
        printf("%c is not valid\n", operator);
    };

  return 0;
};
