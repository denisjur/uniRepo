// Collatz ITERATIV ----------------------------------------------------------
/*
#include <stdio.h>

void collatz_iter(unsigned int n) {
    while (n > 1) {
        printf("%d ", n);  // Aktuellen Wert ausgeben
        if (n % 2 == 0) {
            n = n / 2;  // Wenn n gerade ist
        } else {
            n = 3 * n + 1;  // Wenn n ungerade ist
        };
    };
    printf("%d\n", n);  // Letzten Wert ausgeben (immer 1)
};


int main () {
    
    int zahl;

    printf("(Collatz Programm iterativ) Geben Sie eine Zahl ein:\n");
    scanf("%d", &zahl);

    collatz_iter(zahl);
  return 0;
};
*/
// Collatz REKURSIV -----------------------------------------------------------
#include <stdio.h>

void collatz_rek(unsigned int n) {
    printf("%d ", n);  // Aktuellen Wert ausgeben
    if (n == 1) {
        return;  // Basisfall: Wenn n 1 erreicht hat, beenden
    }
    if (n % 2 == 0) {
        collatz_rek(n / 2);  // Rekursiver Aufruf für gerades n
    } else {
        collatz_rek(3 * n + 1);  // Rekursiver Aufruf für ungerades n
    };
};

int main () {

    int zahl;

    printf("(Collatz Programm rekursiv)Geben Sie eine Zahl ein:\n");
    scanf("%d", &zahl);

    collatz_rek(zahl);
    
    printf("\n");

  return 0;
};

