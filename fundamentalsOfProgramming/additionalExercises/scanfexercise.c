#include <stdio.h>

int main(int argc, char const *argv[]) {

    int number;
    char text[100];

    // Citim un numar intreg de la tastatura
    printf("Introduceti un numar intreg:\n");
    scanf("%d", &number); // Citirea unui numar intreg (%d) + valoarea introdusa va fi salvata în variabila number (& = adresa in C)

    // Citim un sir de caractere de la tastatura
    printf("Introduceti un sir de caractere:\n"); // Afisarea
    scanf("%s", text);  // Citim un sir de caractere (fara spatii)

    // Afisam valorile citite
    printf("Numarul introdus este: %d\n", number);
    printf("Sirul de caractere introdus este: %s\n", text);

    return 0;
}

// -----------------------------------------------------------------------
// // Code kompilieren:
// $ gcc <Programmname.c> -o <neuerProgramname>
//
// Beispiel:
// $ gcc scanfexercise.c -o scanfprog
//
// Programmausführung:
// $ ./prog2
// -----------------------------------------------------------------------

