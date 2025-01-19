#include<stdio.h>
#include<stdlib.h>

//#define ZEILEN 15
//#define SPALTEN 15

void WhereIsWhichElementOfRahmen(char **board, int ZEILEN, int SPALTEN){
  //obere und unteren rand
  for(int i=0;i <ZEILEN; i++){
    board[i][0]         = '*';
    board[i][SPALTEN-1]  = '*';
  }
  //linke und rechte rand
  for(int i=0;i <SPALTEN; i++){
    board[0][i]         = '*';
    board[ZEILEN-1][i] = '*';
  }
  //Innere Blanks
  for(int i=1; i < ZEILEN -1; i++){
    for(int j=1; j< SPALTEN -1; j++){
      board[i][j]=' ';
    }
  }
}


void PrintAll(char **board, int ZEILEN, int SPALTEN){
  for(int i=0; i < ZEILEN; i++){
    for(int j=0; j < SPALTEN; j++){
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
}

void DrawRays(char **board, int ZEILEN, int SPALTEN){
  int i=1;
  char x='A';
  board[ZEILEN/2][SPALTEN/2]=x;

  do{board[ZEILEN/2][SPALTEN/2-i] = x+i; i++;} while(board[ZEILEN/2][SPALTEN/2-i] != '*'); i=1;
  do{board[ZEILEN/2][SPALTEN/2+i] = x+i; i++;} while(board[ZEILEN/2][SPALTEN/2+i] != '*'); i=1;
  do{board[ZEILEN/2+i][SPALTEN/2] = x+i; i++;} while(board[ZEILEN/2+i][SPALTEN/2] != '*'); i=1;
  do{board[ZEILEN/2-i][SPALTEN/2] = x+i; i++;} while(board[ZEILEN/2-i][SPALTEN/2] != '*'); i=1;
  
  do{board[ZEILEN/2+i][SPALTEN/2+i] = x+i; i++;} while(board[ZEILEN/2+i][SPALTEN/2+i] != '*'); i=1;
  do{board[ZEILEN/2+i][SPALTEN/2-i] = x+i; i++;} while(board[ZEILEN/2+i][SPALTEN/2-i] != '*'); i=1;
  do{board[ZEILEN/2-i][SPALTEN/2+i] = x+i; i++;} while(board[ZEILEN/2-i][SPALTEN/2+i] != '*'); i=1;
  do{board[ZEILEN/2-i][SPALTEN/2-i] = x+i; i++;} while(board[ZEILEN/2-i][SPALTEN/2-i] != '*'); i=1;
}

int main(){
  int z_len;
  int s_len;


  printf("Bitte Höhe: ");
  scanf("%d", &z_len);
  printf("Bitte Breite: ");
  scanf("%d", &s_len);

  char **array2 = (char **)malloc(z_len * sizeof(char *)); //malloc für ZEILEN

  for(int i = 0; i < z_len; i++){
    array2[i] = (char *)malloc(s_len * sizeof(char));      //malloc für SPALTEN
  }

  WhereIsWhichElementOfRahmen(array2, z_len, s_len);
  DrawRays(array2, z_len, s_len);
  PrintAll(array2, z_len, s_len);
  return EXIT_SUCCESS;
}
