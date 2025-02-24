#include <stdio.h>

// This is how to store variables
int main () {
    int x;  // declaration
    x = 123; // initializations
    // Alternativ:
    int y = 321; // declaration and initialization at the same time.
    // When declaring a variable you always need to define the data Type, like int for instance:
    int age = 100;
    float height = 1.80;
    char grade = 'A'; //single character
    // Now in C there are no string data types, A char is an object, so to write a name we need an array.
    char name[100] = "Denis"; //array of characters

    // THis is how to display a variable within a printf statement:
    printf ("Hello, I am %s.\nI am %d years old.\nMy average grade is %c.\nMy height is %fm.\n", name, age, grade, height);
    // Asa scri daca vrei 2 Nachkommastellen in float;
    printf ("My height is %.2fm.\n", height);

  return 0;
}

