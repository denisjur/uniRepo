#include <stdio.h>
#include <math.h>

/*
  Funcția este folosită pentru a verifica dacă un număr este prim sau nu.
  - Numerele prime sunt acele numere care sunt divizibile doar cu 1 și cu ele însusi.
*/

int isPrime(int number) {

   // Dacă numărul este mai mic sau egal cu 1, nu este prim
   if(number <= 1) return 0; // FALSE

   // Dacă numărul este 2, este prim (este singurul număr par prim)
   if(number == 2) return 1; // TRUE

   // Dacă restul din "număr : 2" este 0, numărul este par, ci nu prim
   if(number % 2 == 0) return 0; // FALSE

   // Verificăm toți divizorii până la rădăcina pătrată a numărului
   for(int i = 3; i <= sqrt(number); i++) {
       if(number % i == 0) return 0; // Dacă găsim un divizor, nu este prim
   }

   // Dacă nu am găsit niciun divizor, numărul este prim
   return 1; // TRUE
}

int main() {

    int num;
    
    // Citim numărul de la utilizator
    printf("Introduceti un numar: ");
    scanf("%d", &num);

    // Verificăm dacă numărul este prim
    if(isPrime(num)) {                          // Aici if() primeste doar true si false. 0 = false / 1 = true
      printf("%d este un numar prim!\n", num);
    } else {
      printf("%d nu este un numar prim!\n", num);
    }

    return 0;
}

/*
  Pentru a compila un program C care folosește funcția matematică sqrt(), trebuie să adaugi flag-ul -lm 
  pentru a lega biblioteca matematică. Comanda de compilare va arăta astfel:
  gcc -o prime prime.c -lm
*/

