// **********************************************************************
// Header file (.h)
// Adding and removing elements from the game board
// Verifying game board boundaries (limits or edges of the playing area)
// **********************************************************************

// Author:
// Denis Jur
// University of Applied Sciences

// The board model
#ifndef _BOARD_MODEL_H
#define _BOARD_MODEL_H

#include "worm.h"
#include <curses.h>

// Placing and removing items on game board
extern void placeItem(int y, int x, chtype symbol, enum ColorPair color_pair);

// Getters (= Methoden oder Funktionen, die verwendet werden, um den Wert eines Attributs oder einer Eigenschaft eines Objekts abzurufen)
extern int getLastRow();
extern int getLastCol();

#endif // #define _BOARD_MODEL_H
