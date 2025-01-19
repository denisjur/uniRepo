#include <stdio.h>

void printLambda(int n) {

    // Determine console width ; presupunem 87 charactere
    int consoleWidth = 87;

    // Calculam the total width of the lambda
    int lambdaWidth = 4 + (n - 1) * 2 + 3 + (n - 1) * 2 + 3;

    // Calculam padding to center lambda
    int padding = (consoleWidth - lambdaWidth) / 2;

    int initialSpace = 4 + (n - 1) * 2;

    // afisam top
    for (int i = 0; i < padding + initialSpace; ++i) printf(" ");
    printf("*\n");

    int currentSpace = initialSpace - 1;
    int innerSpacing = 1;

    // afisam the diagonal part of the lambda
    for (int row = 1; row <= n + 1; row++) {
        for (int i = 0; i < padding + currentSpace; ++i) printf(" ");
        printf("*");

        for (int i = 0; i < innerSpacing; ++i) printf(" ");
        printf("*\n");

        currentSpace--;
        innerSpacing += 2;
    };

    // Afisam bottom part left side of the bottom row
    for (int i = 0; i < padding + currentSpace-1; ++i) printf(" ");
    for (int i = 0; i < 3; i++) printf("*"); // Left asterisks

    // spatiile din mijloc
    for (int i = 0; i < innerSpacing - 2; i++) printf(" ");

    // Afisam bottom part right side of the bottom row
    for (int i = 0; i < 3; i++) printf("*"); // Right asterisks
    printf("\n");
};

int main(int argc, char const *argv[]) {
    int n; // Adjust n = 1; n = 2; n = 3; n = 4; n = 5
    printf("Geben Sie die Skalierung ein (n): ");
    scanf("%d", &n); // Eingabe der Skalierung
    printLambda(n);
    return 0;
};


