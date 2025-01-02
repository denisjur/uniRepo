#include <stdio.h>

int main()
{
    // continue = skips rest of code & forces the next iteration of the loop
    // break = exits a loop/like for instance in a switch

    for (int i = 1; i <= 20; i++)
    {
      if (i == 13)
      {
        continue;   // Now I can just skip the 13th iteration and keeps going.
                    // If we used a BREAK instead we would simply break out of the loop entirely.

      };
      printf("%d\n", i);
    };
  

    return 0;
};

// This would be the expected output for CONTINUE:
//  1
//  2
//  3
//  4
//  5
//  6
//  7
//  8
//  9
//  10
//  11
//  12
//  14
//  15
//  16
//  17
//  18
//  19
//  20

// Expected output for BREAK:
//  1
//  2
//  3
//  4
//  5
//  6
//  7
//  8
//  9
//  10
//  11
//  12



