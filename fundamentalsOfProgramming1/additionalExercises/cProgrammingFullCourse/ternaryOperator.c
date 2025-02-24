//
//
//  #include <stdio.h>
//
//  int main()
//  {
// ********************************************************************************
//      // ternary operator = shortcut to if/else when assigning/returning a value
//      // (condition) ? value if true : value if false
// ********************************************************************************
//    return 0;
//  }

#include <stdio.h>

// Definition der Funktion findMax
int findMax(int x, int y) {
    return (x > y) ? x : y; // Verwendet den ternären Operator
};

int main()
{
    // ternary operator = shortcut to if/else when assigning/returning a value
    // (condition) ? value if true : value if false

    int max = findMax(5, 4); // Ruft findMax auf

    printf("%d\n", max); // Gibt den größeren Wert aus

    return 0;
};

