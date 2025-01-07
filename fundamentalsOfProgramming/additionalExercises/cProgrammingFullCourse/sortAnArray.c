#include <stdio.h>

// Aici creem un program care imi sorteaza numerele in ordine crescatoare.
// El compara mereu vecinul din dreapta lui daca e mai mare sau mai mic. Daca e mai mic atunci schimba cu el.

    void sort(int array[], int size) {   // We use void here because we do not have anything to return back!
      for (int i = 0; i < size - 1; i++)    // Size - 1, ca incepe la pozitia 0
      {
        for (int j = 0; j < size - i - 1; j++)
        {
          if(array[j] > array[j+1]) 
          {
            int temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
          };
        };
      };
    };

void printArray(int array[], int size) {
  for(int i = 0; i < size; i++)
  {
    printf("%d", array[i]);
  };
  printf("\n");

};

int main () {
    
    int array[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);
    
    sort(array, size);
    printArray(array, size);
    return 0;
};
