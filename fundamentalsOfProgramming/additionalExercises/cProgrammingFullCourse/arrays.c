#include <stdio.h>

int main()
{
    // array = a data structure that can store many values ONLY of the SAME data type!
    
    double prices[] = {5.0, 10.0, 15.0, 25.0, 20.0};
    //      position:    0,   1,   2,    3,    4     
    char name[] = "Bro";

    printf("The price is $%.2lf\n", prices[0]); // Aici in Array specificam ce element din Aray vrem.
                              // Gen Elementul cu pozitia 1.

    return 0;
};


// Alternativ kannst du auch, falls du nicht sofort alle Elemente des Array kennst, erst nur den Array definieren und später im Programm füllen:

//  int main()
//  {
//     
//     double prices[5];    // -> Here you simply set a size in the beginning.
//
//     prices[0] = 5.0;
//     prices[1] = 10.0;
//     prices[2] = 15.0;
//     prices[3] = 25.0;
//     prices[4] = 20.0;
//
//
//     // UNd so weiter...
//     
//     char name[] = "Bro";
//
//     printf("The price is $%.2lf\n", prices[0]); 
//                               
//     return 0;
//  };


