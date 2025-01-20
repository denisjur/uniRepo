#include <stdio.h>
#include <malloc.h>
//array : [1,2,3,4,5,6,7]

//listele simplu inlantuite:
//structuri de date care sunt alocate dinamic in HEAP
//node1 (informatie, NEXT) -----> node2(informatie, NEXT)------> node3(informatie, NEXT) ---> node4(informatie, NEXT)->>NULL

struct Node {
      int data;//infortie
      struct Node *next;//camp de legatura
};
//exercitiul 1
struct Node* list_create_node(int value) {

      //                     void*
      struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

      if(newNode == NULL) {
        printf("Eroare la alocare memorie!");
        return NULL;
      }

      newNode->data = value;
      newNode->next= NULL;

      return newNode;

}

struct Node *adaugaInLista(struct Node *head, int value) {

      struct Node* newNode = list_create_node(value);

      if(head == NULL) return newNode;

      struct Node *current = head;

      while(current->next != NULL) {

        current = current->next;
      }

      current->next = newNode;

      return head;
}

//exercitiul 2
void printList(struct Node* head) {

      struct Node*current = head;

      printf("Lista: ");

      while(current != NULL) {

          printf("%d -> ", current->data);

          current = current->next;
      }

      printf("NULL\n");

}

int countDiv3(struct Node *head) {

    int counterDiv3 = 0;

    struct Node*current = head;

    //ma deplasez pe fiecare nod pana cand ajung la NULL si testez daca este divizibil cu 3

    while(current!=NULL) {

        if(current->data % 3 == 0) counterDiv3++;

        current = current->next;
    }

    return counterDiv3;
}

int* copy3div_to_array(struct Node *head) {

    int SIZE = 100;
    //array alocat dinamic in HEAP
    int *ptr = (int*)malloc(SIZE * sizeof(int));

    struct Node* current = head;

    int i = 0;

    while(current!=NULL) {

      if(current->data % 3 == 0) {

        *(ptr+i) = current->data;
        i++;

      }

      current = current->next;
    }

    return ptr;

}


int main(int argc, char const *argv[]) {

  struct Node *head = NULL;

  head = adaugaInLista(head, 10);
  head = adaugaInLista(head, 20);
  head = adaugaInLista(head, 30);
  head = adaugaInLista(head, 40);
  head = adaugaInLista(head, 50);
  head = adaugaInLista(head, 33);
  head = adaugaInLista(head, 21);
  printList(head);

  printf("Numarul de noduri divizibile cu 3 = %d", countDiv3(head));

  int *ptr = copy3div_to_array(head);

  printf("\nNodurile divizibile cu 3 sunt urmatoarele \n");
  printf("%d ", *(ptr+0));
  printf("%d ", *(ptr+1));
  printf("%d ", *(ptr+2));

  return 0;
}
