#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// a) ---------------------------------------------------------------------------

bool istVokal(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return true;
    } else {
        return false;
    };
};

// b) --------------------------------------------------------------------------

int zaehleVokale(char *s) {
    int anzahlVokale = 0;
    for (int i = 0; *(s + i) != '\0'; i++) {
        if (istVokal(*(s + i))) {
            anzahlVokale++;
        };
    };
    return anzahlVokale;
};

// c) -------------------------------------------------------------------------

// Funktion, um einen Satz in die B-Sprache zu übersetzen
char* nachB(char* s) {
    // Länge des Originalsatzes
    int len = strlen(s);

    // Zähle die Anzahl der Vokale
    int vokale = zaehleVokale(s);

    // Speicherplatz für den neuen String berechnen
    int newSize = len + (vokale * 2) + 1; // +2 für jedes zusätzliche 'b' und Vokal, +1 für '\0'
    char* transformed = (char*)malloc(newSize * sizeof(char));

    if (transformed == NULL) {
        printf("Fehler: Speicher konnte nicht zugewiesen werden!\n");
      return NULL;
    };

    int j = 0; // Index für den neuen String

    // Originalsatz durchlaufen und in die B-Sprache übersetzen
    for (int i = 0; s[i] != '\0'; i++) {
        if (istVokal(s[i])) {
            // Vokal -> 'vokal', 'b', 'vokal'
            transformed[j++] = s[i];        // Hier wird der neue Satz aufgebaut!
            transformed[j++] = 'b';
            transformed[j++] = s[i];
        } else {
            // Nicht-Vokale unverändert kopieren
            transformed[j++] = s[i];        // Falls kein Vokal, so baut man einfach die Buchstaben weiter auf!
        };
    };

    transformed[j] = '\0'; // Nullterminator hinzufügen am Ende des Strings !
    return transformed;
};

// Ausgangsfunktion: -------------------------------------------------------------------------
int main(void) {
    char* saetze[] = {
        "das ist die b-sprache.",
        "kannst du die auch?",
        "die kann doch jedes kind!",
        NULL,
    };
   
    int i = 0;
    // Ausgabe Übersetzung Oiginal + Transformed sentences:
    while (saetze[i] != NULL) {
        char* trans;
        trans = nachB(saetze[i]);
        printf("Original:  %s\n", saetze[i]);
        printf("Übersetzt: %s\n", trans);
        printf("\n");
        free(trans);
        i++;
      };
    return 0;
};

