#include <stdio.h>
#include <stdbool.h>

int main() {
    // logical operators = || (OR) checks if at least one condition is true
    float temp = 25;

    if (temp <= 0 || temp >= 30) {  // <-- Wenn mindestens eines davon wahr ist wird der code ausgeführt.
        printf("\nThe weather is bad!");
    } else {
        printf("\nThe weather is good!");
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


