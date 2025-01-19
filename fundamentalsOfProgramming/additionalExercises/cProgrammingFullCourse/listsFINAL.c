#include <stdio.h>
#include <stdlib.h>

// #################################################
// Acum insertam functii, care sunt oft folosite in lists
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


// ################## OFTEN USED FUNCTIONS REGARDING LISTS #########################
// ---------------------------------------------------------------------------------
// Function to insert the node at the head position:
  node_t *insert_at_head(node_t *head, node_t *node_to_insert) {
    node_to_insert->next = head; // Der gerade eben erstellte node ist unser neuer Kopf
    return node_to_insert;
  };
// ---------------------------------------------------------------------------------
// Now let us make a function that helos us find a node:
  node_t* find_node(node_t *head, int value) {
    node_t *tmp = head;  // Beginne mit dem Kopf der Liste
    while (tmp != NULL) {  // Solange der Zeiger nicht NULL ist
        if (tmp->value == value) {  // Wenn der Wert des aktuellen Knotens dem gesuchten Wert entspricht
            return tmp;  // Den gefundenen Knoten zurückgeben
        };
        tmp = tmp->next;  // Zum nächsten Knoten weitergehen
    };
    return NULL;  // Wenn der Wert nicht gefunden wurde, NULL zurückgeben
  };
// ---------------------------------------------------------------------------------
// Now let us make a function, that helps us insert a node, after a node in the list:
  void insert_after_node(node_t *node_to_insert_after, node_t *newnode) {
    newnode->next = node_to_insert_after->next;  // Der neue Knoten zeigt auf das nächste Element des alten Knotens
    node_to_insert_after->next = newnode;        // Der alte Knoten zeigt jetzt auf den neuen Knoten
};
// ---------------------------------------------------------------------------------


int main() {
    node_t *head = NULL;
    node_t *tmp;

    for (int i=0; i < 25; i++) {
        tmp = create_new_node(i); // Creaza un nou node cu functia
        head = insert_at_head(head, tmp);
    };

    printlist(head);  // Liste ausdrucken

    return 0;
};


