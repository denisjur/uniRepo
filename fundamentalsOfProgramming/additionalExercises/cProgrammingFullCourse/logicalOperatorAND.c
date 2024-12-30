#include <stdio.h>
#include <stdbool.h>

int main() {
    // logical operators = && (AND) checks if two conditions are true
    float temp = 1000;
    bool sunny = true;

    if (temp >= 0 && temp <= 30 && sunny) {  //Tritt nur ein wenn beide Bedingungen wahr sind!
        printf("\nThe weather is good!\n");
    } else {
        printf("\nThe weather is bad!\n");
    };

    return 0;
};

// Truth Table for AND, OR, NOT
// -----------------------------
// Inputs    AND    OR     NOT
// A   B     A∧B   A∨B    ¬A
// -----------------------------
// 0   0      0     0      1
// 0   1      0     1      1
// 1   0      0     1      0
// 1   1      1     1      0
// -----------------------------

