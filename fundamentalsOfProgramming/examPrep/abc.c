#include <stdio.h>

void drucke(int n) {
    int breite = 2 * n + 1; // Breite des Musters

    // Oberer Teil des Lambda
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < breite; j++) {
            if (j == n - i || j == n + i) { // Sternpositionen
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Unterer Teil (Füße des Lambda)
    for (int j = 0; j < breite; j++) {
        if (j <= n - 1 || j >= n + 1) { // Bereich der Füße
            printf("*");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Geben Sie die Größe n ein: ");
    scanf("%d", &n);
    drucke(n);
    return 0;
}

