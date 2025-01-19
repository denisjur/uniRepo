#include <stdio.h>
#include <stdlib.h>

// #################################################
// VERSIOUNEA REALA:
// Asa am folosi Lists normal
// #################################################

// Definition eines Knotens der Liste
struct node {
    int value;
    struct node* next;
};
typedef struct node node_t;

// Funktion zum Ausdrucken der Liste -------------------------
void printlist(node_t* head) {
    node_t* temp = head;
    while (temp != NULL) {
        printf("%d - ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}
// -----------------------------------------------------------


// Let us create a function, that creates new nodes for us ---
node_t *create_new_node(int received_value) {  // Int value wird erhalten, so wie vorhin n1 = 12 z.B
      node_t *result = malloc(sizeof(node_t));  //Speicher im Heap wird zugewiesen
      result->value = received_value;   // Unser Value in node_t wird unser recieved value 
      result->next = NULL;              // Unser node zeigt nun auf NUll
      return result;
};
// -----------------------------------------------------------


int main() {
    node_t *head = NULL;
    node_t *tmp;

    for (int i=o; i < 25; i++) {
        tmp = create_new_mode(i); // Creaza un nou node cu functia
        tmp->next = head;         // Unser gerade eben erstellter node soll auf den vorherigen Kopf zeigen
        head = tmp;               // Der gerade eben erstellte node ist unser neuer Kopf
    };

    printlist(head);  // Liste ausdrucken

    return 0;
}



