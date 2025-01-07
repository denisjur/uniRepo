#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // pseudo random numbers = A set of values or elements that are statistically random
    //                          (Don't use these for any sort of cryptographic security)


srand(time(0)); // YOu need to use a random seed for the current time to actualy get different numbers. Seed random function of current time.
int number1 = (rand() % 6) + 1; // with rand() you generate a random number between 0 - 32.767 thousand.
                                // by using modulo % 6. Yo generate a random number between 0 and 5. If you need a random number between 0 and 6, you add + 1 to the end, like this.
                                // You use modulos and the max number you'd like

    printf("%d\n", number1);
    return 0;
}

