#include <stdio.h>
#include <stdlib.h>

// #################################################
// VERSIOUNEA mai REALA
// Normal codul care lam folosit inainte nu este, chiar 
// cum implementam o lista intrun mod normal.
// Ci asa ar fii normal:
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

node_t *create_new_node(int value) {
      node_t *result = malloc(sizeof(node_t));
      result->value = value;
      result->next = NULL;
      return result;
};
// -----------------------------------------------------------


int main() {
    node_t *head;
    node_t *tmp;

    tmp = create_new_node(32);
    head = tmp;
    tmp = create_new_node(8);
    tmp->next = head;
    head = tmp;
    tmp = create_new_node(34);
    tmp->next = head;
    tmp = head;


    printlist(head);  // Liste ausdrucken

    return 0;
}


