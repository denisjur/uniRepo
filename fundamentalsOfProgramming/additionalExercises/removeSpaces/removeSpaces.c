#include <stdio.h>
#include <string.h>

// Funktion, die Leerzeichen aus einem String entfernt
void remove_spaces(char *str) {
    char *source = str; // Zeiger auf den Anfang des Strings
    char *dest = str;   // Zeiger für die Position zum Schreiben

    // Iteration durch den String
    while (*source) {
        if (*source != ' ') { // Nur Zeichen, die keine Leerzeichen sind, werden kopiert
            *dest = *source;
            dest++;
        }
        source++;
    }
    *dest = '\0'; // Null-Terminierung des Strings
}

int main() {
    char string_buffer[100]; // Puffer für die Eingabe

    printf("Bitte geben Sie einen String ein: ");
    fflush(stdout); // Puffer leeren, um sicherzustellen, dass die Ausgabe erfolgt

    if (fgets(string_buffer, sizeof(string_buffer), stdin)) { // Lesen des Strings von der Eingabe
        string_buffer[strcspn(string_buffer, "\n")] = '\0'; // Entfernen des abschließenden Zeilenumbruchs
        printf("Originaler String: %s\n", string_buffer);

        remove_spaces(string_buffer); // Aufruf der Funktion zur Entfernung von Leerzeichen
        printf("String ohne Leerzeichen: %s\n", string_buffer);
    } else {
        printf("Fehler beim Lesen der Eingabe.\n");
    }

    return 0;
}

