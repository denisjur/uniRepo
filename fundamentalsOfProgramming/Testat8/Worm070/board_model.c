// A simple variant of the game Snake
//
// Author:
// Denis Jur
// University of Applied Sciences
//
// The board model

#include <curses.h>
#include "worm.h"
#include "board_model.h"
#include "messages.h"

// *************************************************
// Placing and removing items from the game board
// Check boundaries of game board
// *************************************************

// Place an item onto the curses display.
void placeItem(struct board* aboard, int y, int x, enum BoardCodes board_code, chtype symbol, enum ColorPairs color_pair){

    move(y, x);                         // Move cursor to (y,x)
    attron(COLOR_PAIR(color_pair));     // Start writing in selected color
    addch(symbol);                      // Store symbol on the virtual display
    attroff(COLOR_PAIR(color_pair));    // Stop writing in selected color
    aboard->cells[y][x] = board_code;
}


// Get the last usable row on the display
int getLastRowOnBoard(struct board* aboard) {
  return aboard->last_row;
}

// Get the last usable column on the display
// Get the last usable row on the display
int getLastColOnBoard(struct board* aboard) {
  return aboard->last_col;
}

int getNumberOfFoodItems(struct board* aboard) {
  return aboard->food_items;
}

enum BoardCodes getContentAt(struct board* aboard, struct pos position) {
  return aboard->cells[position.y][position.x];
}

void setNumberOfFoodItems(struct board* aboard, int n) {
  aboard->food_items = n;
}

void decrementNumberOfFoodItems(struct board* aboard) {
  aboard->food_items -= 1;
}

enum ResCodes initializeBoard(struct board* aboard) {
  // Check dimensions of the board
  if ( COLS < MIN_NUMBER_OF_COLS ||
    LINES < MIN_NUMBER_OF_ROWS + ROWS_RESERVED ) {
    char buf[100];
    sprintf(buf,"Das Fenster ist zu klein: wir brauchen %dx%d",
    MIN_NUMBER_OF_COLS , MIN_NUMBER_OF_ROWS + ROWS_RESERVED );
    showDialog(buf,"Bitte eine Taste druecken");
    return RES_FAILED;
  }
  // Maximal index of a row
  aboard->last_row = MIN_NUMBER_OF_ROWS - 1;
  // Maximal index of a column
  aboard->last_col = MIN_NUMBER_OF_COLS - 1;
  return RES_OK;
}

enum ResCodes initializeLevel(struct board* aboard) {
  // define local variables for loops etc
  int y, x;

  // Fill board and screen buffer with empty cells.
  for (y = 0; y <= aboard->last_row ; y++) {
  for (x = 0; x <= aboard->last_col ; x++) {
    placeItem(aboard,y,x,BC_FREE_CELL,SYMBOL_FREE_CELL,COLP_FREE_CELL);
  }
  }
  // Draw a line in order to separate the message area
  // Note: we cannot use function placeItem() since the message area
  // is outside the board!
  y = aboard->last_row + 1;
  for (x=0; x <= aboard->last_col ; x++) {
    move(y, x);
    attron(COLOR_PAIR(COLP_BARRIER));
    addch(SYMBOL_BARRIER);
    attroff(COLOR_PAIR(COLP_BARRIER));
  }
  // Draw a line to signal the rightmost column of the board.
  for (y = 0; y <= aboard->last_row ; y++) {
    placeItem(aboard,y,aboard->last_col,
    BC_BARRIER,SYMBOL_BARRIER,COLP_BARRIER);
  }
  // Barriers: use a loop
  for (y = 7; y < 21; y++) {
    int x = 17;
    placeItem(aboard,y,x,BC_BARRIER,SYMBOL_BARRIER,COLP_BARRIER);
  }
  for (y = 13; y < 25; y++) {
    int x = aboard->last_col - 11;
    placeItem(aboard,y,x,BC_BARRIER,SYMBOL_BARRIER,COLP_BARRIER);
  }
  // Food
  placeItem(aboard, 3, 3, BC_FOOD_1, SYMBOL_FOOD_1, COLP_FOOD_1);
  placeItem(aboard, 15, 40, BC_FOOD_1, SYMBOL_FOOD_1, COLP_FOOD_1);

  placeItem(aboard, 15, 50, BC_FOOD_2, SYMBOL_FOOD_2, COLP_FOOD_2);
  placeItem(aboard, 4, 29, BC_FOOD_2, SYMBOL_FOOD_2, COLP_FOOD_2);
  placeItem(aboard, 3, 55, BC_FOOD_2, SYMBOL_FOOD_2, COLP_FOOD_2);
  placeItem(aboard, 18, 5, BC_FOOD_2, SYMBOL_FOOD_2, COLP_FOOD_2);

  placeItem(aboard, 14, 43, BC_FOOD_3, SYMBOL_FOOD_3, COLP_FOOD_3);
  placeItem(aboard, 21, 47, BC_FOOD_3, SYMBOL_FOOD_3, COLP_FOOD_3);
  placeItem(aboard, 19, 36, BC_FOOD_3, SYMBOL_FOOD_3, COLP_FOOD_3);
  placeItem(aboard, 23, 8, BC_FOOD_3, SYMBOL_FOOD_3, COLP_FOOD_3);

  // Initialize number of food items
  // Attention: must match number of items placed on the board above
  aboard->food_items = 10;
  return RES_OK;
}

