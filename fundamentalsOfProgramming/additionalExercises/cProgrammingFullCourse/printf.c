#include <stdio.h> //This includes a library with some standart input/ output functions

int main () {
  // Escape Sequences: \n or \t
  printf("Hello World!\n"); // \n = new line
  printf("0\t2\t3\n");  // \t = tab 
  
  // Print Quotes: \"
  printf("\"Hello World\" - Someone\n");
  // And if you want to display \ then simply use twoo \\.i
  printf("\\This is how to display backslashes\\\n");
  return 0; // If the programm runs successfully, then we always return 0
}


