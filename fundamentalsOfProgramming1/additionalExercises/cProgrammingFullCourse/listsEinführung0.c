#include <stdio.h>
#include <stdlib.h>

// #################################################
// Versiunea comprimata de la lists.c
// #################################################

// Definition eines Knotens der Liste
struct node {
    int value;
    struct node* next;
};
typedef struct node node_t;

// Funktion zum Ausdrucken der Liste
void printlist(node_t* head) {
    node_t* temp = head;
    while (temp != NULL) {
        printf("%d - ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node_t n1, n2, n3;  // Drei Knoten
    node_t *head;

    // Knotenwerte zuweisen
    n1.value = 45;
    n2.value = 8;
    n3.value = 32;

    // Verknüpfen der Knoten
    head = &n1;  // Kopf zeigt auf n3
    n3.next = NULL;
    n2.next = &n3;
    n1.next = &n2;  // Ende der Liste

    // Hai sa adaugam aici mai un node on lista:
    // .........................................
    node_t n4;
    n4.value = 13;
    n4.next = &n3;
    n2.next = &n4;
    // .........................................

    // Iar daca vrem sa stergem ceva din lista. Spre exemplu
    // Sa spunem ca vrem sa stergem primul node n1 din lista:
    // Atunci simplu doar  facem, ca head sa arate pe urmatorul
    // element din lista:
    head = head->next;

    printlist(head);  // Liste ausdrucken

    return 0;
}

