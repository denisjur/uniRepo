//  #include <stdio.h>
//
//  void birthday() {
//    printf("\nHappy birthday dear %s!", name);
//    printf("\nYou are %d years old!", age);
//  };
//
//  int main() {
//    char name[] = "Bro";
//    int age = 21;
//
//    birthday();
//
//    return 0;
//  };
//
//
//  Why wouldn't this code work? 
//    Functions can not see inside other functions. 
//    Our birthday-function is unaware of the age and name in the main function. 
//    This is why we can not call these variables like this.
//    In order to solve this, we need to connect the functions through parameters, like this:
//


#include <stdio.h>

void birthday(char n[], int a) {
    printf("\nHappy birthday dear %s!", n);
    printf("\nYou are %d years old!", a);
};

int main() {
    char name[] = "Bro";
    int age = 21;

    birthday(name, age);

    return 0;
};

