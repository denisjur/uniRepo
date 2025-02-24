#include <stdio.h>

int main() {
    // ###################################################################################
    // while loop = checks a condition, THEN executes a block of code if condition is true
    // do-while-loop = always executes a block of code once, THEN checks a condition
    // ###################################################################################

    // Ca de exemplu: 
    //
    // int number = 0;
    // int sum = 0;
    //
    // while (number > 0) {
    //     printf("Enter a # above 0: ");
    //     scanf("%d", &number);
    //     if (number > 0)
    //     {
    //         sum += number;
    //     };
    // };
    //
    // Acest cod scris nu va executa nimic pentru ca mai intai verifica conditia, dar nu si la DO WHILE LOOP!!:
    
    do {
      printf("Enter a # above 0: ");
      scanf("%d", &number);
      if (number > 0) {
         sum += number;
      };
    } while (number > 0);
  

    return 0;
};

