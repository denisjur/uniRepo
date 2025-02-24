#include <stdio.h>
#include <stdbool.h>  //<-- with this we can use the datatype boolean
int main () {
  
  char a = 'C'; // single character %c
  char b[] = "Bro"; // array of characters %s from string

  float c = 3.141592; // 4 bytes (32 bits precision) 6 - 7 digits %f (Alternative for only 2 decimals after coma: %.2f)
  double d = 3.141592653589793; // 8 bytes (64 bits of precision) 15 - 16 digits %lf (They have double the precision of a float)
  
  bool e = true;  // 1 byte (true or false) %d => a decimal integer (base 10). But why %d?? Becuase true = 1 and false=0

  char f = 100; // 1 byte (-128 to +127)we can store this integer number 100 in either %d or %c
  printf("%d or %c\n",f, f); //If we store it with %d we get the integer 100, If we store it with %c we get the ASCII representation of the letter d instead of 100.
  unsigned char g; // 1byte (0 to +255) %d or %c
  
  short int h = 32767;  // 2 bytes (-32,768 to +32,767) %d
  unsigned short int i = 65535; // 2 bytes (0 to +65,535) %d
  //Alternativ auch short h = 32767 oder unsigned short i = 65535

  int j = 2143456753; // 4bytes (-2.147.483.648 to + 2.147.483.647) %d
  unsigned int k = 4294967295;  // 4bytes (0 to +4,294,967,295) %u
  
  long long int l = 2222233333334444444; // 8bytes (-9 quintillion to +9 quintillion)  %lld
  unsigned long long int m = 333333444444444243U;   // 8bytes (0 to + 18 quintillion) % llu
                                                                // To prevent any warning we can simply put an U at the end of the number so that the number can be displayed.
                                
  return 0;
};
