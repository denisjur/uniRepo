#include <stdio.h>
#include <string.h>

int main()
{
    char cars[][10] = {"Mustang", "Corvette", "Camaro"};

    // cars[0] = "Tesla";
    // Daca vrei sa ersetze un Wert din matirx trebuie sa folosesti functia asta, nu merge simplus sa faci precum pe linie de deasupra.
    // Trebuie sa importezi libraria string.h si sa folosesti functia strcpy() asa:
    strcpy(cars[0], "Tesla");

    for (int i = 0; i < sizeof(cars) / sizeof(cars[0]); i++)
    {
        printf("%s\n", cars[i]);
    };

    return 0;
};

