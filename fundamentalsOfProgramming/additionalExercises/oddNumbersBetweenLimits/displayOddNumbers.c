// Titlu: Afișarea numerelor impare dintr-un interval dat
// Descriere: Acest program afiseaza toate numerele impare dintr-un interval specificat de utilizator.

#include <stdio.h>

int main() {
    int a, b;

    // Citirea limitelor intervalului
    printf("Introduceti limita inferioara a = ");
    scanf("%d", &a);
    printf("Introduceti limita superioara b = ");
    scanf("%d", &b);

    // Verificare si inversare limite daca a > b
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Afisarea numerelor impare din interval
    printf("Numerele impare din intervalul [%d, %d] sunt: ", a, b);
    for (int i = a; i <= b; ++i) {
        if (i % 2 != 0) { // Verificam daca numarul este impar
            printf("%d ", i);
        }
    }

    printf("\n"); // Pentru o afisare mai ordonata

    return 0;
}

