#include <stdio.h>

int main()
{
    // 2D array = an array, where each element is an entire array
    //            useful if you need a matrix, grid, or table of data

  /*
  // ############ ERSTER VERSUCH #######################################################  
  // Asa poti sa faci o 2X3 Matrix. E ca si in matematica. 
  // Besteht aus 2 Zeilen und 3 Spalten. IDENTIC ca in Matematica
     
    int numbers[2][3] = {
                          {1, 2, 3},
                          {4, 5, 6}
                        };
  // ###################################################################################
    */

  // ############ Zweiter Versuch#######################################################
    // Noi si asa putem sa mai afisam matrici:
    
    int numbers[2][3];
    
    // Aici putem foarte usor sa calculam sizeof de la rows si columns
    int rows = sizeof(numbers)/sizeof(numbers[0]); // Aici imparti toate linile la o linie, de asta numbers la nubers[0]
    int columns = sizeof(numbers[0])/sizeof(numbers[0][0]); // Aici imparti o Linie, adica numbers [0] la un singur element din linie, adica numbers[0][0].

    numbers[0][0] = 1;
    numbers[0][1] = 2;
    numbers[0][2] = 3;
    numbers[1][0] = 4;
    numbers[1][1] = 5;
    numbers[1][2] = 6;
    
    // Wie können wir auf die Inhalte zugreifen? Durch Nested loops:  
    for (int i = 0; i < rows; i++)   // Anzahl an Zeilen, nämlich 2, wie wir oben sehen können.
    {
        for (int j = 0; j < columns; j++) // Anzahl an Spalten, nämlich 3, wie wir oben sehen können.
        {
            printf("%d ", numbers[i][j]);
        };
        printf("\n");
    };
    
  // ###################################################################################


  return 0;
};




