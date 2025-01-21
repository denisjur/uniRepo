// Das Pascalsche Dreieck:

//                1
//              1   1
//            1   2   1
//          1   3   3   1
//        1   4   6   4   1
//      1   5  10  10   5   1
//    1   6  15  20  15   6   1

// n\k  |  0   1   2   3   4   5   6
// ---------------------------------
//   0  |  1
//   1  |  1   1
//   2  |  1   2   1
//   3  |  1   3   3   1
//   4  |  1   4   6   4   1
//   5  |  1   5  10  10   5   1
//   6  |  1   6  15  20  15   6   1

// Rekursive Lösung:

#include <stdio.h>

// Rekursive Funktion zur Berechnung des Binomialkoeffizienten
int BinKoeff(int n, int k) {
    if (k == 0 || k == n) {
        return 1; // Basisfall
    } else {
        return BinKoeff(n - 1, k - 1) + BinKoeff(n - 1, k); // Rekursive Berechnung
                                                            // Ca sa intelegi asta, trebuie sa te uiti cas la dreieck
    };
};

// Funktion zum Drucken des Pascalschen Dreiecks
void PrintPascalsTriangle(int rows) {
    for (int n = 0; n < rows; ++n) {
        // Einrücken für die Dreiecksform
        for (int space = 0; space < rows - n - 1; ++space) {
            printf("  ");
        };
        for (int k = 0; k <= n; ++k) {
            printf("%4d", BinKoeff(n, k)); // Ausgabe mit Abstand
        }
        printf("\n");
    };
};

int main() {
    int rows;

    // Benutzer gibt die Anzahl der Zeilen ein
    printf("Geben Sie die Anzahl der Zeilen für das Pascalsche Dreieck ein: ");
    scanf("%d", &rows);

    // Ausgabe des Pascalschen Dreiecks
    PrintPascalsTriangle(rows);

    return 0;
};


