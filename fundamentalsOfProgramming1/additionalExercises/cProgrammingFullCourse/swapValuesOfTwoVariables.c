#include <stdio.h>
#include <string.h>

int main()
{
  /*
  // This is how you swap if you have to swap characters: Pretty easy:
    char x = 'X';
    char y = 'Y';
    
    char temp;

    temp = x;
    x = y;
    y = temp;

    printf("x = %c\n", x);
    printf("y = %c\n", y);
  */
  // But now it is different for arrays, you need to do it like this:

    char x[15] = "Water";
    char y[15] = "Lemonade";

    char temp[15]; // --> Declare a random size

    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);

    printf("x = %c\n", x);
    printf("y = %c\n", y);


    return 0;
};

