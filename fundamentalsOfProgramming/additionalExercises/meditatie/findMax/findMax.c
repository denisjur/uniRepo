/*
   Programul găsește cel mai mare număr dintr-un array de numere întregi.

   Descrierea pseudocodului:
   - Se compară fiecare element din array cu valoarea maximă curentă.
   - Dacă găsește un element mai mare, acea valoare devine noua valoare maximă.

   Se afișează și dimensiunile în bytes pentru diferite tipuri de date (int, float, double, char).
*/

#include <stdio.h>

int main(int argc, char const *argv[]) {

  // Declarăm un array de numere întregi
  int arr[] = { -123, 122, 3, 4, 5, 11, 33, 44, 55, -4, 552, 0, 123 };
  // Position:     0    1   2  3  4  5   6   7   8   9   10   11 12

  // Calculăm dimensiunea array-ului
  int size = sizeof(arr)/sizeof(arr[0]); // sizeof determină câte elemente sunt în array

  printf("Lungimea sirului = %d\n", size);

  // Afișăm dimensiunile în BYTES pentru diferite tipuri de date
  printf("Lungimea in BYTES int = %ld\n", sizeof(int));
  printf("Lungimea in BYTES float = %ld\n", sizeof(float));
  printf("Lungimea in BYTES double = %ld\n", sizeof(double));
  printf("Lungimea in BYTES char = %ld\n", sizeof(char));

  // Inițializăm valoarea maximă cu primul element al array-ului
  int max = arr[0];

  // Iterăm prin array și comparăm fiecare element cu valoarea maximă
  // Dacă găsim un element mai mare, actualizăm valoarea maximă
  for (int index = 0; index < size; ++index) {
      if (arr[index] > max) {
          max = arr[index];
      }
  }

  // Afișăm cel mai mare număr din array
  printf("Cel mai mare numar din sir = %d\n", max);

  return 0;
}

