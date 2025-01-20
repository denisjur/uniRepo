#include <stdio.h>
#include <stdlib.h>

// Definition des Knotens für die verkettete Liste
typedef struct node {
    int data;              // Daten des Knotens
    struct node* next;     // Zeiger auf den nächsten Knoten
} node_t;

// a) Funktion welche neue Nodes erstellt
node_t* list_create_node(int d) {
    // Erstellen eines neuen Knotens mit dem Wert `d`
    node_t* new_node = (node_t*)malloc(sizeof(node_t)); // Speicher reservieren
    
    if (new_node == NULL) {
        fprintf(stderr, "Speicher konnte nicht zugewiesen werden\n");
        exit(EXIT_FAILURE);
    }
    
    new_node->data = d;    // Wert setzen
    new_node->next = NULL; // Initialisieren des Zeigers auf NULL
    return new_node;       // Zeiger auf den neuen Knoten zurückgeben
}


// Hilfsfunktion zum Einfügen eines Elements am Anfang der Liste
node_t* insert(node_t* list, int value) {
    node_t* new_node = list_create_node(value); // Neuen Knoten erstellen
    new_node->next = list;                     // Neuer Knoten zeigt auf aktuellen Kopf
    return new_node;                           // Neuer Kopf der Liste zurückgeben
}

//  b) Iterative Funktion, welche die Liste printed
void print_list(node_t* list) {
    // Durchläuft die Liste und gibt alle Werte aus
    while (list != NULL) {
        printf("%d, ", list->data); // Wert des aktuellen Knotens ausgeben
        list = list->next;          // Zum nächsten Knoten gehen
    }
    printf("\n"); // Neue Zeile nach der Ausgabe
}

// c) Rekursive Implementierung der Funktion `count3div`
int count3div(node_t* node) {
    // Basisfall: Wenn die Liste leer ist, gibt es keine Elemente mehr
    if (node == NULL) return 0;

    // Rekursive Zählung: Prüfen, ob der aktuelle Wert durch 3 teilbar ist
    return (node->data % 3 == 0) + count3div(node->next);
}

//  d) Implementierung der Funktion `copy3div_to_array`
int* copy3div_to_array(node_t* node) {
    int count = count3div(node); // Anzahl der durch 3 teilbaren Elemente zählen

    // Falls keine durch 3 teilbaren Elemente existieren, NULL zurückgeben
    if (count == 0) return NULL;

    // Speicherplatz für das Array reservieren
    int* array = (int*)malloc(count * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Speicher konnte nicht zugewiesen werden\n");
        exit(EXIT_FAILURE);
    }

    // Kopieren der durch 3 teilbaren Elemente ins Array
    int index = 0;
    while (node != NULL) {
        if (node->data % 3 == 0) { // Nur durch 3 teilbare Werte speichern
            array[index++] = node->data;
        }
        node = node->next; // Zum nächsten Knoten gehen
    }

    return array; // Array zurückgeben
}

// Funktion zur Ausgabe eines Arrays
void print_array(int* array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d, ", array[i]); // Array-Wert ausgeben
    }
    printf("\n");
}

// Funktion zum Freigeben des Speichers der Liste
void delete_list(node_t* list) {
    while (list != NULL) {
        node_t* temp = list;   // Temporären Zeiger setzen
        list = list->next;     // Zum nächsten Knoten gehen
        free(temp);            // Speicher des aktuellen Knotens freigeben
    }
}

// Hauptprogramm
int main(void) {
    node_t* list; // Anker für eine verkettete Liste (Startknoten)

    // Liste erzeugen
    list = insert(insert(insert(NULL, 7), 3), 4);
    list = insert(list, 27);
    list = insert(list, 48);

    // Liste ausgeben
    printf("Liste: ");
    print_list(list);

    // Zähle Anzahl der Elemente, die durch 3 teilbar sind
    int l = count3div(list);
    printf("Anzahl durch 3 teilbarer Elemente: %d\n", l);

    // Kopiere die durch 3 teilbaren Elemente in ein Array
    int* array = copy3div_to_array(list);

    // Array ausgeben
    if (array != NULL) {
        printf("Array der durch 3 teilbaren Elemente: ");
        print_array(array, l);
        free(array); // Speicher des Arrays freigeben
    }

    // Speicher der Liste freigeben
    delete_list(list);

    exit(EXIT_SUCCESS);
}

