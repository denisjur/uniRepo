// ### Return Statement ###
//  #include <stdio.h>
//
//  void square(double x) {
//      // Function body to be implemented
//  }
//
//  int main() {
//      // return = returns a value back to a calling function
//
//      return 0;
//  };

// #########################################################################################################
// A return statement is a key component in programming that specifies the value or values a function should 
// output (or "return") when it is executed. 
// Once the return statement is encountered in a function, the execution of the function stops, 
// and the specified value is sent back to the part of the program that called the function.
// #########################################################################################################

#include <stdio.h>

double square(double x) {   // Aici void square(double x) devine double square(double x). Pentru ca returnam result. Iar result e de typ double. Daca era int, atunci si functia trebuia sa fie int. 
    double result = x * x;
    return result;
};

int main() {
    double x = square(3.14);
    printf("%lf", x);

    return 0;
};

