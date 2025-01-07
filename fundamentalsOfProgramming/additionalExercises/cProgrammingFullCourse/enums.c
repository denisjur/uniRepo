#include <stdio.h>

enum Day {Sun = 1, Mon = 2, Tue = 3, Wed = 4, Thu = 5, Fri = 6, Sat = 7};
  // Aici am scris, e egal cu unu, doi, trei etc, pentru ca astfel incepea cu pozitia 0

int main()
{
    // enum = a user defined type of named integer identifiers
    //        helps to make a program more readable
    // ENUMS ARE NOT STRINGS!!! But they can be treated as integers. 
    // You can declare it outside and in the main function
    enum Day today = Sun; // You treat enums as integers, not as strings or characters
    printf("%d\n", today);    // THis is why you use %d in printf

    
    // Now we can write a program that will print a message during different days of the week.

    /*
    if (today == 1 || today == 7)
    {
      printf("\nIt's the weekend! Party time!");
    }
    else
    {
      printf("\nI have to work today :(");
    };
    */

    // Now to make this if statement more readable for other programers, we can instead of writing the integer just write the day:
    // It simply makes more sense for the programers:
    if (today == Sun || today == Sat)
    {
      printf("\nIt's the weekend! Party time!");
    }
    else
    {
      printf("\nI have to work today :(");
    };

    return 0;
};

