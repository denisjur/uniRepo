#include <stdio.h>
#include <stdbool.h>

int main() {
    // logical operators = ! (NOT) reverses the state of a condition
    bool sunny = true;

    if (!sunny) {
        printf("\nIt's cloudy outside!\n");
    } else {
        printf("\nIt's sunny outside!\n");
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



