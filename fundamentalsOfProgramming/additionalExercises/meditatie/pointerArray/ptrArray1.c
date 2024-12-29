#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  int arr[5] = {10, 20, 30, 40, 50};

  int *arrayDynamic; // Wir deklarieren einen Zeiger, um das dynamisch allokierte Array zu speichern.
  // Zeiger auf einen int

  // Anzahl der Elemente
  int dimension = 5;

  // Dynamische Speicherzuweisung
  // Wir allokieren Speicher im HEAP für das Array mit malloc

  arrayDynamic = (int*)malloc(sizeof(int) * dimension); // void*

  // Multiplizieren mit der Dimension, um die insgesamt benötigte Anzahl an Bytes zu ermitteln.

  // Gibt einen Zeiger auf void zurück (void*)
  // Danach konvertieren wir ihn zu einem Zeiger auf int.

  // 1__ 2__ 3____ 4___ 5__

  // Speicherplatz im HEAP allokieren.

  // printf("sizeof(int) = %d bytes", sizeof(int));

  // Überprüfen, ob die Speicherzuweisung im HEAP erfolgreich war.

  if (arrayDynamic == NULL) {
    printf("Speicherzuweisung fehlgeschlagen!\n");
    return 1;
  } else {
    printf("Speicherzuweisung erfolgreich!\n");
  }

  //* Dereferenzierungsoperator

  for (int i = 0; i < dimension; ++i) {
    *(arrayDynamic + i) = (i + 1) * 10; // 10, 20, 30, 40, 50
    // arrayDynamic + i = Zeiger verschieben zur nächsten Adresse
    // *(arrayDynamic + 0)
    // *(arrayDynamic + 1)
    // *(arrayDynamic + 2)
    // *(arrayDynamic + 3)
    // *(arrayDynamic + 4)
  }

  // Mit Zeigerarithmetik kann man von einer Speicheradresse zur nächsten wechseln.

  // arrayDynamic[0] = 10
  // arrayDynamic[1] = 20
  // arrayDynamic[2] = 30
  // arrayDynamic[3] = 40
  // arrayDynamic[4] = 50

  printf("\n");

  for (int i = 0; i < dimension; ++i) {
    printf("%d ", arrayDynamic[i]);
  }

  int *ptr = arrayDynamic; // Die Startadresse des Arrays wird im Zeiger ptr gespeichert.

  if (ptr == NULL) printf("Fehler bei der dynamischen Speicherzuweisung\n");

  // int *x = arrayDynamic;

  int summe = 0;
  // Dynamisch = Flexibilität
  // Der Speicher wird zur Laufzeit und nicht zur Kompilierungszeit allokiert.

  for (int i = 0; i < dimension; ++i) {
    summe = summe + (*ptr); // Extrahiert den Wert aus der Adresse ptr.
    // summe = 0 + 10;
    // summe = 10 + 20;
    // summe = 30 + 30;
    // summe = 60 + 40;
    // summe = 100 + 50;

    ptr++; // ptr = ptr + 1;
  }
  // arrayDynamic: Adresse1, Adresse2, Adresse3, Adresse4, Adresse5
  // Ox1223f3

  // ptr

  printf("\nSumme der Array-Elemente = %d\n", summe);

  // Speicherverwaltung
  free(arrayDynamic); // Gibt den dynamisch zugewiesenen Speicher frei.

  return 0;
}

/*
Schritt 1: Einen Zeiger deklarieren, der das dynamisch zugewiesene Array enthält.
*/

