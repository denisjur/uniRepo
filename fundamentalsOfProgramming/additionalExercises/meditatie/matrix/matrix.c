/*
               1 2 3 4
    Matrice =  1 2 3 4
               4 5 6 7
               7 8 9 10

               1 2 3 4
    Matrice =  1 2 3 4
               4 5 6 7
               7 8 9 10
               11 12 13 14

matrix[5][4]


f:MxM->M

matrice[][]

   - array of array
   - tablou bidimensional

   matrix[LINIE][COLOANA];

   matrice[0][0] = 1
   matrice[0][1] = 2
   matrice[0][2] = 3
   matrice[0][3] = 4

   matrice[1][0] = 1
   matrice[1][1] = 2
   matrice[1][2] = 3
   matrice[1][3] = 4


*/
#include <stdio.h>
#define LINII 3
#define COLOANE 4

void afisareMatrice(int matrix[LINII][COLOANE]){

    for(int i = 0; i < LINII; ++i) {

        for(int j = 0; j < COLOANE; ++j) {

             printf("%4d", matrix[i][j]);
        }

        printf("\n");
    }

}

int main(int argc, char const *argv[]) {


  int matrix[ LINII ][ COLOANE ] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
  };

  printf("Afisare matrice: \n");

  afisareMatrice( matrix );
  return 0;
}
