#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node* next;  // Diesen Pointer nenne wir next. Er soll zum nächsten Inhalt in der List zeigen
};
typedef struct node node_t;

//---------------------------------------------------------------------------------------------------
  //Aici punem o functie care sa dea print la lista, ca sa vedem si noi ce se intampla:
  void printlist (node_t* head) { // Aici introducem in functie head pointerul, ca sa stim unde sa incepem cu afisarea printf
        node_t *temporary = head;   // Aici punem un pointer temporara sa ne arate Headul listei
        
        while (temporary != NULL) { // Atata timp cat temporary pointer nu este NULL, adica nu a ajuns la sfarsitul listei, condinuam.
            printf("%d - ", temporary->value); // Aici printf actuala Valuare care node points to.
            temporary = temporary->next; // Aici dupa ce am afisat valoarea, temporary arata pe urmatorul node in lista.
            };
          printf("\n");
        };
//--------------------------------------------------------------------------------------------------

int main () {
  node_t n1, n2, n3; // AIci spunem ca vrem 3 noduri.
  node_t *head; // Asta e startul, Head bzw. Anker

  // Acum le dam la fiecare valorii:
  n1.value = 45;
  n2.value = 8;
  n3.value = 32;

  // Now let us link them up. And just for fun let us put them like this:
  // 3(32) -> 2(8) -> 1 (45)
  // But you can usuallly put them in every order you want to
  

  head = &n3; // Here we'll make the head the adress of n3.
  n3.next = &n2;
  n2.next = &n1;
  n1.next = NULL; // Aici punem NULL, ca e sfarsitul listei.

  printlist (head); // Aici chemam functia, ce am contruito sus

return 0;
};

