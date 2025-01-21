// n=1
//     *    a)
//    * *
//   *   *
// ***   ***

// n=2
//      *       a)
//     * *      b)
//    *   *     b)
//   *     *    b)
// ***     ***  c)

// Entwicklung des Algotithmus
// 
// a-Zeile: 3 + n,   *\n
// 
// b-Zeilen: Anzahl * _*-Zeilen: n + 1; Zeilenindex z
// - 2 + n - z Leerzeichen
// - *
// - 1 + (2 * z) Leerzeichen
// - *\n
//
// c-Zeile:
// - ***
// - 1 + (2 * n) Leerzeichen
// - ***


#include <stdio.h>

void drucke(int n) {
    int i, z;
    for (i = 0; i < 3+n; i++) printf(" ");
    printf("*\n");
    for (z = 0; z < n+1; z++) {
        for (i = 0; i < 2+n-z; i++) printf(" ");
        printf("*");
        for (i = 0; i < 1+2*z; i++) printf(" ");
        printf("*\n");
    }
    printf("***");
    for (i = 0; i < 1+2*n; i++) printf(" ");
    printf("***\n");
}



int main () {
  int wert;
  printf("Geben Sie einen Wert zur Skalierung ein:\n");
  scanf("%d", &wert);
  drucke (wert);
return 0;
};
