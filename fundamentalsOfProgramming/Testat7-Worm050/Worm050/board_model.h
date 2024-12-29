// **********************************************************************
// Header file (.h)
// Adding and removing elements from the game board
// Verifying game board boundaries (limits or edges of the playing area)
// **********************************************************************

// Author:
// Denis Jur
// University of Applied Sciences

// The board model

// The board model

#ifndef _BOARD_MODEL_H
#define _BOARD_MODEL_H

#include "worm.h"
#include <curses.h>

// Positions on the board
struct pos {
  int y; // y-Coordinate (row)
  int x; // x-Coordinate (column)
};

// Placing and removing items from the game board
extern void placeItem(int y, int x, chtype symbol, enum ColorPair color_pair);

// Getters
extern int getLastRow();
extern int getLastCol();

#endif // #define _BOARD_MODEL_H
