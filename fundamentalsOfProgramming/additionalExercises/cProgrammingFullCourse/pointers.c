    // pointer = a "variable-like" reference that holds a memory address to another variable, array, etc.
    //           some tasks are performed more easily with pointers
    //           * = indirection operator (value at address)


  /*
    Benefits of Using Pointers
    - Less time in program execution.
    - Working on the original variable.
    - With the help of pointers, we can create data structures (linked list, stack, queue).
    - Returning more than one value from functions.
    - Searching and sorting large data very easily.
    - Dynamically memory allocation.
##########################################################################################
    What is Dynamic memory allocation?
      Dynamic memory allocation is a process in programming where memory is allocated during the runtime of a program, rather than at compile time. 
      It allows programs to request memory when needed, and release it when no longer required, making efficient use of system memory.
##########################################################################################
  Key Features:
    Runtime Allocation:
      Memory is allocated while the program is running.
      The size of the memory can be determined dynamically, based on user input or other runtime conditions.
    Efficient Memory Use:
      You allocate only as much memory as required, reducing waste.
    Memory Management:
      Memory can be released manually when it is no longer needed to avoid memory leaks.
    Flexibility:
      Enables the creation of dynamic data structures like linked lists, trees, graphs, etc., whose size can change during execution.

###########################################################################################
These functions are available in <stdlib.h>:

Function	Description
malloc()	Allocates a specified number of bytes and returns a pointer to the first byte.
calloc()	Allocates memory for an array of elements and initializes them to zero.
realloc()	Resizes previously allocated memory block to a new size.
free()	Frees the memory allocated by malloc(), calloc(), or realloc().
##########################################################################################
*/

#include <stdio.h>

void printAge(int *pAge) {
  printf("You are %d years old!\n", *pAge);
};


int main() {
    // ---------------------------------------------------------------------------------
    // This sign "*" is beeing used whedn you declare a Pointer,
    // As well as when you want to EXTRACT the VALUE of the adress, you are pointing to!
    // ----------------------------------------------------------------------------------
    
    //Now we can try to store the adress of this int age in another variable (A Pointer)!
    int age = 21;
    int *pAge = &age; // Der Pointer muss den selben Datentyp haben, wie der Inhalt der Adresse auf der es zeigt
                      // Da age vom typ int ist, muss auch pAge vom Typ int sein!
   // -----------------------------------------------------------------------------------
   // Daca sti ca vrei sa folosesti un Pointer, si nu sti inca pe ce sa arate, poti mai intai sa il declari cu NULL,
   // si dupa sa ii spui unde sa arate. Asta ar arata asa in locul codului scris sus:
   // int age = 21;
   // int *pAge = NULL;
   // *pAge = &age;
   // -----------------------------------------------------------------------------------


    printf("address of age: %p\n", &age); // Prints the memory address of the variable 'age'
    printf("address of pAge: %p\n", pAge);

    printf("value of age: %d\n", age);   // Prints the value of the variable 'age'
    printf("value at stored adress: %d\n", *pAge); // with "*" in pAge we are extracting a value from this adress.

    printf("size of age: %d bytes\n", sizeof(age));
    printf("size of pAge: %d bytes\n", sizeof(pAge));

    printAge(pAge);
    return 0;   
};

