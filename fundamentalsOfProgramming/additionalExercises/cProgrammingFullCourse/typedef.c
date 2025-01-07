/* 
###### Ce e un TYPEDEF? ############################################################
=== Asta ar fii folosirea unui typedef ===
In loc de a folosi char user1[25] = "Bro"; scri asa si definesti orice cuvant cu un typ de date. 
Adica cuvantul user acum devine un typ de date care il poti utiliza. 
Cand il chemi nu mai trebuie sa spui ca e de typ character, ca lai definit deja:

#include <stdio.h>
#include <string.h>

typedef char user[25];

int main()
{
    // typedef = reserved keyword that gives an existing datatype a "nickname"
    if (0) // Diese Bedingung wird nie wahr sein
    {
        user user1 = "Bro";
        printf("This code will never execute!\n");
    }
    return 0;
};

#####################################################################################
*/
// Haide sa vedem cum am folosi asa un typedef la structs:



#include <stdio.h>
#include <string.h>

// Now if I would want to use typedef on this example:
/*

struct User
{
    char name[25];
    char password[12];
    int id;
};

int main () {  
  struct user1 = {"Bro", "pasword123", 123456789};
  struct user2 = {"Bruh", "paswod123", 123444789};
  return 0;
};

// I would have to write it like this:
*/

typedef struct
{
    char name[25];
    char password[12];
    int id;
} User;

int main () {
  User user1 = {"Bro", "pasword123", 123456789};
  User user2 = {"Bruh", "paswod123", 123444789};
  
  printf("%s\n", user1.name);
  printf("%s\n", user1.password);
  printf("%d\n", user1.id);
  printf("\n");

  printf("%s\n", user2.name);
  printf("%s\n", user2.password);
  printf("%d\n", user2.id);

  return 0;
};

