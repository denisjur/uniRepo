#include <stdio.h>
#include <ctype.h> // -> A lot of string Functions

int main() {
    char unit;
    float temp;

    printf("\nIs the temperature in (F) or (C)?: ");
    scanf("%c", &unit);

    unit = toupper(unit); // ->> Falls man kleine Buchstaben eingibt, werden diese durch die Funktion in Großbuchstaben umgeschrieben.

    if (unit == 'C') {
        printf("\nEnter the temp in Celsius: ");
        scanf("%f", &temp);
          temp = (temp * 9 / 5) + 32;
        printf("\nThe temp in Fahrenheit is: %.1f\n", temp);
    }
    else if (unit == 'F') {
        printf("\nEnter the temp in Fahrenheit: ");
        scanf("%f", &temp);
          temp = ((temp - 32) * 5) / 9;
        printf("\nThe temp in Celsius is: %.1f\n", temp);
    }
    else {
        printf("\n%c is not a valid unit of measurement\n", unit);
    };

  return 0;
};
