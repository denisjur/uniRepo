// **********************************************************************
// Source file (.c) for header file (.h), called:
// Adding and removing elements from the game board
// Verifying game board boundaries (limits or edges of the playing area)
// **********************************************************************

// Author:
// Denis Jur
// University of Applied Sciences

#include "board_model.h"
#include "worm.h"
#include <curses.h>

// Place an item onto the curses display.
void placeItem(int y, int x, chtype symbol, enum ColorPair color_pair) {
  // Store item on the display (symbol code)
  move(y, x);                      // Move cursor to (y,x)
  attron(COLOR_PAIR(color_pair));  // Start writing in selected color
  addch(symbol);                   // Store symbol on the virtual display
  attroff(COLOR_PAIR(color_pair)); // Stop writing in selected color
}

// ### Getters ###

// Get the last usable row on the display
int getLastRow() { return LINES - 1 - ROWS_RESERVED; }

// Get the last usable column on the display
int getLastCol() { return COLS - 1; }

