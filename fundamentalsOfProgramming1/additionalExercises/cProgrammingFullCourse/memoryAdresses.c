#include <stdio.h>

int main()
{
    // memory = an array of bytes within RAM (street)
    // memory block = a single unit (byte) within memory, used to hold some value (home storing a person)
    // memory address = the address of where a memory block is located (house address)
    
    char a = 'X';   // This uses one memory block, one adress. It is the size of 1 byte.
    short b = 'Y';  
    int c = 'Z';   
  // Now let us display the size of each of these memory blocks:
    printf("%d bytes\n", sizeof(a));
    printf("%d bytes\n", sizeof(b));
    printf("%d bytes\n", sizeof(c));

  // Now let us display the adress of the memory block using %p:
  // They are written in hex-format
    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("%p\n", &c);


    return 0;
};



