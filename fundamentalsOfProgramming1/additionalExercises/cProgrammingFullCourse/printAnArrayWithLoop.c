#include <stdio.h>

int main()
{
    double prices[5] = {5.0, 10.0, 15.0, 25.0, 20.0};
   

    // Aici noi vrem ca for loop sa mearga pana la  i<5. Adica i < sizul array-ulul.
    // Ca sa calculam sizeul array-ulul atunci trebe sa luam tot sizul si sa il impartim la sizul unui element. Pentru ca toate elementele au aceasi marime in bytes.
    // Din cauza asta avem aici sizeof(prices)/sizeof(prices[0])

    for(int i = 0; i < sizeof(prices)/sizeof(prices[0]) ; i++) 
    {
    printf("The price is $%.2lf\n", prices[i]);
    };
    return 0;
};

