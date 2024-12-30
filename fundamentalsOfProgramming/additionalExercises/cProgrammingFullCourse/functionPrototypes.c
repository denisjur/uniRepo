// function prototype
// WHAT IS IT?
// Function declaration, w/o a body, before main()
// Ensures that calls to a function are made with the correct arguments

#include <stdio.h>

//  Asa ar merge programmul: 
//  void hello(char name[], int age) {
//    printf("Hello %s!\n",name);
//    printf("You are %d years old!\n", age);
//  };
//
//  int main () {
//    char name[] = "Abraham";
//    int age =  100;
//
//    hello(name, age);
//    return 0;
//  };

// Dar daca schimbam Reihenfolgele functilor, trebuie pron o function prototype sa declaram
// ca va urma functia candva in programm. Pentru asta ne trebuie.


void hello(char name[], int age); // --> ASTA e un FUNCTION PROTOTYPE

int main () {
  char name[] = "Abraham";
  int age =  100;

  hello(name, age);
  return 0;
};

void hello(char name[], int age) {
  printf("Hello %s!\n",name);
  printf("You are %d years old!\n", age);
};


