/*
Definition von Zeigern:

Ein Zeiger ist eine spezielle Variable, die eine Speicheradresse einer anderen Variablen speichert.

Mit anderen Worten, der Zeiger zeigt auf die Speicherstelle, an der diese Variable gespeichert ist,

wodurch ein direkter Zugriff und eine direkte Manipulation der Daten über die Speicheradresse möglich sind.

Deklaration:

- wird mit dem Symbol * deklariert
- int *ptr: ein Zeiger, der die Adresse einer Integer-Variablen speichern kann
- float *ptr: ein Zeiger, der die Adresse einer Fließkommazahl-Variablen speichern kann
- double *ptr: ein Zeiger, der die Adresse einer Double-Variablen speichern kann
*/

#include <stdio.h>

int main(int argc, char const *argv[]) {

  int x = 10; // eine Integer-Variable

  // double *pointer2 = &x;

  // pointer2 = &x; // Fehler

  int *pointer = &x; // ein Zeiger auf eine Integer-Variable

  printf("Der Wert von x: %d\n", x);
  printf("Die Adresse von x: %p\n", &x);
  printf("Der Wert des Zeigers: %p\n", pointer);
  printf("Der Wert, auf den der Zeiger zeigt: %d\n", *pointer);

  return 0;
}

