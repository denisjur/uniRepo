#include <stdio.h>
#include <stdlib.h>

// Datensegment
// HEAP-Segment
// Stapel-Segment (Stack)

int global_variabila;
// Wenn die globale Variable nicht initialisiert wird, wird sie automatisch mit 0 initialisiert.

// Wird im DATENSEGMENT gespeichert

void display() {

    int local_variabila = 101;
    printf("Der Wert der globalen Variablen ist: %d\n", global_variabila);
    printf("Der Wert der lokalen Variablen ist: %d\n", local_variabila);
}

// Die globale Variable ist in jeder Funktion zugänglich
// Lokale Variable: zugänglich nur innerhalb der Funktion, in der sie deklariert wurde
// Lebensdauer: während der gesamten Programmlaufzeit
void afiseaza() {

    int local_alta_variabila = 102;
    printf("Der Wert der globalen Variablen ist: %d\n", global_variabila);
    printf("Der Wert der lokalen Variablen ist: %d\n", local_alta_variabila);
}

int main(int argc, char const *argv[]) {

  int arr[5] = {10, 20, 30, 40, 50};

  int *arrayDynamic; // Deklaration eines Zeigers für das dynamische Array
  // Zeiger auf einen Integer

  // Anzahl der Elemente
  int dimensiune = 5;

  display();
  afiseaza();

  // Dynamische Speicherzuweisung
  // Speicher für das Array im HEAP mit malloc reservieren

  arrayDynamic = (int*)malloc(sizeof(int) * dimensiune); // void*

  // Mit der Größe multiplizieren, um die Gesamtzahl der benötigten Bytes zu berechnen

  // malloc gibt einen Zeiger auf void (void*) zurück
  // Dieser wird in einen Zeiger auf int umgewandelt

  // Speicherplatz im HEAP reservieren

  // printf("sizeof(int) = %d Bytes", sizeof(int));

  // Überprüfen, ob die Speicherzuweisung im HEAP erfolgreich war
  if (arrayDynamic == NULL) {

    printf("Speicherzuweisung fehlgeschlagen!");
    return 1;
  } else {
    printf("Speicherzuweisung erfolgreich!");
  }

  //* Dereferenzierungsoperator

  for (int i = 0; i < dimensiune; ++i) {
          *(arrayDynamic + i) = (i + 1) * 10; // 10, 20, 30, 40, 50
          // arrayDynamic + i: Zeiger wird zur nächsten Adresse verschoben
  }

  // Mit Zeigerarithmetik kann man von einer Speicherstelle zur nächsten wechseln

  printf("\n");

  for (int i = 0; i < dimensiune; ++i) {
      printf("%d ", arrayDynamic[i]);
  }

  int *ptr = arrayDynamic; // Zeiger `ptr` speichert die Startadresse des Arrays

  if (ptr == NULL) printf("Fehler bei der dynamischen Speicherzuweisung!");

  int suma = 0;

  for (int i = 0; i < dimensiune; ++i) {
      suma = suma + (*ptr); // Wert an der Adresse `ptr` extrahieren
      ptr++; // Zeiger `ptr` um eins verschieben
  }

  printf("\nSumme der Array-Elemente = %d\n", suma);

  // Speicherverwaltung
  free(arrayDynamic); // Freigeben des dynamisch zugewiesenen Speichers

  return 0;
}

/*
Schritt 1: Zeiger deklarieren, der das dynamisch zugewiesene Array speichert
*/

