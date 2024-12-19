#include <stdio.h>

// Funcție pentru scalarea unei matrice pătrate
void scaleMatrix(char square[][100], int size, int scalingFactor) {
    int newSize = size * scalingFactor;

    // Afișarea matricei scalate
    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
            printf("%c ", '*');
        }
        printf("\n");
    }
}

int main() {
    int size, scalingFactor;

    // Introducerea dimensiunii formei originale
    printf("Dimensiunea formei = ");
    scanf("%d", &size);

    if (size <= 0 || size > 10) {
        printf("Dimensiunea trebuie să fie între 1 și 10.\n");
        return 1;
    }

    // Introducerea factorului de scalare
    printf("Factorul de scalare = ");
    scanf("%d", &scalingFactor);

    char square[100][100];

    // Inițializarea matricei cu caracterul '*'
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            square[i][j] = '*';
        }
    }

    // Afișarea matricei originale
    printf("\nMatricea originală:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", square[i][j]);
        }
        printf("\n");
    }

    printf("\nMatricea scalată:\n");

    // Apelarea funcției de scalare
    scaleMatrix(square, size, scalingFactor);

    return 0;
}

