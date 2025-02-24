#include <stdio.h>
#define MAX_ROWS 10

int calculamElementPascal(int rand, int coloana) {

     if(coloana == 0 || coloana  == rand) {

         return 1;
     }

     return calculamElementPascal(rand-1,coloana-1) + calculamElementPascal(rand-1, coloana);
}

void afiseazaTriunghiulPascal(int nrRanduri) {

    for(int rand = 0; rand < nrRanduri; rand++) {

            for(int spatiu = 0; spatiu < nrRanduri - rand - 1; ++spatiu)

                printf("   ");

    //afisam elementele fiecarui rand
    for(int coloana = 0; coloana <= rand; coloana++) {

             printf("%6d", calculamElementPascal(rand, coloana));
    }

   printf("\n");
  }

}

int main(int argc, char const *argv[]) {

  int inaltime;

  printf("dati inaltimea Triunghiului: ");
  scanf("%d", &inaltime);

  printf("Triunghiul lui Pascal:\n");

  afiseazaTriunghiulPascal(inaltime);

  //afiseazaTriunghiulPascal(inaltime);
  return 0;
}
