#include <stdio.h>
#include <stdlib.h>

// Funktion zur Initialisierung des Spielfeldes mit einem Rahmen und inneren Leerzeichen
void WhereIsWhichElementOfRahmen(char **board, int ZEILEN, int SPALTEN) {
  // Obere und untere Ränder setzen
  for (int i = 0; i < ZEILEN; i++) {
    board[i][0] = '*';           // Linker Rand
    board[i][SPALTEN - 1] = '*'; // Rechter Rand
  }
  // Linke und rechte Ränder setzen
  for (int i = 0; i < SPALTEN; i++) {
    board[0][i] = '*';           // Oberer Rand
    board[ZEILEN - 1][i] = '*';  // Unterer Rand
  }
  // Innere Felder mit Leerzeichen füllen
  for (int i = 1; i < ZEILEN - 1; i++) {
    for (int j = 1; j < SPALTEN - 1; j++) {
      board[i][j] = ' ';
    }
  }
}

// Funktion zur Ausgabe des gesamten Spielfeldes
void PrintAll(char **board, int ZEILEN, int SPALTEN) {
  for (int i = 0; i < ZEILEN; i++) {
    for (int j = 0; j < SPALTEN; j++) {
      printf("%c", board[i][j]); // Aktuelles Element ausgeben
    }
    printf("\n"); // Zeilenumbruch nach jeder Zeile
  }
}

// Funktion zum Zeichnen von Strahlen ausgehend vom Mittelpunkt
void DrawRays(char **board, int ZEILEN, int SPALTEN) {
  int i = 1;         // Abstand vom Mittelpunkt
  char x = 'A';      // Startbuchstabe
  board[ZEILEN / 2][SPALTEN / 2] = x; // Mittelpunkt initialisieren

  // Strahlen in alle Richtungen zeichnen
  do { board[ZEILEN / 2][SPALTEN / 2 - i] = x + i; i++; } while (board[ZEILEN / 2][SPALTEN / 2 - i] != '*'); i = 1; // Links
  do { board[ZEILEN / 2][SPALTEN / 2 + i] = x + i; i++; } while (board[ZEILEN / 2][SPALTEN / 2 + i] != '*'); i = 1; // Rechts
  do { board[ZEILEN / 2 + i][SPALTEN / 2] = x + i; i++; } while (board[ZEILEN / 2 + i][SPALTEN / 2] != '*'); i = 1; // Unten
  do { board[ZEILEN / 2 - i][SPALTEN / 2] = x + i; i++; } while (board[ZEILEN / 2 - i][SPALTEN / 2] != '*'); i = 1; // Oben

  // Diagonale Strahlen zeichnen
  do { board[ZEILEN / 2 + i][SPALTEN / 2 + i] = x + i; i++; } while (board[ZEILEN / 2 + i][SPALTEN / 2 + i] != '*'); i = 1; // Rechts unten
  do { board[ZEILEN / 2 + i][SPALTEN / 2 - i] = x + i; i++; } while (board[ZEILEN / 2 + i][SPALTEN / 2 - i] != '*'); i = 1; // Links unten
  do { board[ZEILEN / 2 - i][SPALTEN / 2 + i] = x + i; i++; } while (board[ZEILEN / 2 - i][SPALTEN / 2 + i] != '*'); i = 1; // Rechts oben
  do { board[ZEILEN / 2 - i][SPALTEN / 2 - i] = x + i; i++; } while (board[ZEILEN / 2 - i][SPALTEN / 2 - i] != '*'); i = 1; // Links oben
}

int main() {
  int z_len; // Höhe des Spielfeldes
  int s_len; // Breite des Spielfeldes

  // Eingabe der Spielfeldgröße
  printf("Bitte Höhe: ");
  scanf("%d", &z_len);
  printf("Bitte Breite: ");
  scanf("%d", &s_len);

  // Speicher für das Spielfeld dynamisch reservieren
  char **array2 = (char **)malloc(z_len * sizeof(char *));
  for (int i = 0; i < z_len; i++) {
    array2[i] = (char *)malloc(s_len * sizeof(char));
  }

  // Funktionen aufrufen
  WhereIsWhichElementOfRahmen(array2, z_len, s_len); // Rahmen setzen
  DrawRays(array2, z_len, s_len);                    // Strahlen zeichnen
  PrintAll(array2, z_len, s_len);                    // Spielfeld ausgeben

  // Speicher freigeben
  for (int i = 0; i < z_len; i++) {
    free(array2[i]);
  }
  free(array2);

  return EXIT_SUCCESS;
}


