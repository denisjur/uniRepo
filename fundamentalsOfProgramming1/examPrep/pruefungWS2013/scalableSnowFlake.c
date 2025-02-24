#include <stdio.h>
#include <stdlib.h>

// Makro zur Kapselung des Zugriffs auf das Array via Pointer-Arithmetik
#define arrayAccess(array, Spalten, z, s) (*((array) + (z) * (Spalten) + (s)))

// Funktion zum Zeichnen des Rahmens
void rahmen(void* einFeld, int zeilen, int spalten) {
    char* feld = (char*)einFeld; // Typ-Casting des void-Pointers
    // Rahmen zeichnen (oben und unten)
    for (int i = 0; i < spalten; i++) {
        arrayAccess(feld, spalten, 0, i) = '-';               // obere Kante
        arrayAccess(feld, spalten, zeilen - 1, i) = '-';      // untere Kante
    }
    // Rahmen zeichnen (links und rechts)
    for (int i = 0; i < zeilen; i++) {
        arrayAccess(feld, spalten, i, 0) = '|';               // linke Kante
        arrayAccess(feld, spalten, i, spalten - 1) = '|';     // rechte Kante
    }
    // Ecken
    arrayAccess(feld, spalten, 0, 0) = '+';
    arrayAccess(feld, spalten, 0, spalten - 1) = '+';
    arrayAccess(feld, spalten, zeilen - 1, 0) = '+';
    arrayAccess(feld, spalten, zeilen - 1, spalten - 1) = '+';
}

// Funktion zum Zeichnen eines Arms des Sterns in eine Richtung
void arm(void* einFeld, int zeilen, int spalten, int z0, int s0, int dz, int ds) {
    char* feld = (char*)einFeld; // Typ-Casting des void-Pointers
    int z = z0 + dz;
    int s = s0 + ds;

    // Zeichnen, bis der Rand erreicht wird
    while (arrayAccess(feld, spalten, z, s) == ' ') {
        arrayAccess(feld, spalten, z, s) = '*'; // Stern zeichnen
        z += dz; // Bewegung in z-Richtung
        s += ds; // Bewegung in s-Richtung
    }
}

// Funktion zur Ausgabe des Arrays auf der Konsole
void ausgabe(void* einFeld, int zeilen, int spalten) {
    char* feld = (char*)einFeld; // Typ-Casting des void-Pointers
    for (int i = 0; i < zeilen; i++) {
        for (int j = 0; j < spalten; j++) {
            printf("%c", arrayAccess(feld, spalten, i, j)); // Feldinhalt ausgeben
        }
        printf("\n"); // Zeilenumbruch nach jeder Zeile
    }
}

void stern(void* einFeld, int zeilen, int spalten, int z0, int s0) {
    char* feld = (char*)einFeld; // Typ-Casting des void-Pointers

    // Mittelpunkt des Sterns setzen
    arrayAccess(feld, spalten, z0, s0) = '*';

    // Zeichne die Arme des Sterns
    arm(einFeld, zeilen, spalten, z0, s0, -1, 0);  // nach oben
    arm(einFeld, zeilen, spalten, z0, s0, +1, 0);  // nach unten
    arm(einFeld, zeilen, spalten, z0, s0, 0, -1);  // nach links
    arm(einFeld, zeilen, spalten, z0, s0, 0, +1);  // nach rechts
    arm(einFeld, zeilen, spalten, z0, s0, -1, -1); // nach links oben
    arm(einFeld, zeilen, spalten, z0, s0, +1, +1); // nach rechts unten
    arm(einFeld, zeilen, spalten, z0, s0, +1, -1); // nach links unten
    arm(einFeld, zeilen, spalten, z0, s0, -1, +1); // nach rechts oben
}

int main() {
    // Statisches Array lokal definieren
    #define ZEILEN 15
    #define SPALTEN 15
    char feld[ZEILEN][SPALTEN];

    // Ursprung des Sterns vom Benutzer einlesen
    int z0, s0;

    printf("Bitte geben Sie die Zeilenkoordinate des Ursprungs ein (0-%d): ", ZEILEN - 1);
    scanf("%d", &z0);
    printf("Bitte geben Sie die Spaltenkoordinate des Ursprungs ein (0-%d): ", SPALTEN - 1);
    scanf("%d", &s0);

    // Überprüfen, ob die Eingabe innerhalb des gültigen Bereichs liegt
    if (z0 < 1 || z0 >= ZEILEN - 1 || s0 < 1 || s0 >= SPALTEN - 1) {
        printf("Fehler: Der Ursprung muss sich innerhalb des Rahmens befinden!\n");
        return EXIT_FAILURE;
    }

    // Typinformation über Array vergessen, Zuweisung an void-Pointer
    void* vp_feld = feld;

    // Array initialisieren (mit Leerzeichen füllen)
    for (int i = 0; i < ZEILEN; i++) {
        for (int j = 0; j < SPALTEN; j++) {
            feld[i][j] = ' ';
        }
    }

    // Rahmen, Stern und Ausgabe
    rahmen(vp_feld, ZEILEN, SPALTEN);
    stern(vp_feld, ZEILEN, SPALTEN, z0, s0);
    ausgabe(vp_feld, ZEILEN, SPALTEN);

    return EXIT_SUCCESS;
}

