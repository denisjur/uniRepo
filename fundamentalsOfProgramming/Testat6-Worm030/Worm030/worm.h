// **********************************************************************
// Main Header File for Managing the Worm's Behavior and Game Logic
// **********************************************************************

// Author:
// Denis Jur
// University of Applied Sciences

#ifndef _WORM_H
#define _WORM_H

// Result codes of functions
enum ResCode {
  RES_OK,
  RES_FAILED,
};

// ### Konstanten deklarieren! Dimensions and Bounds ###

#define NAP_TIME 100          // Time in milliseconds to sleep between updates of display
#define MIN_NUMBER_OF_ROWS 3  // The guaranteed number of rows available for the board
#define MIN_NUMBER_OF_COLS 10 // The guaranteed number of columns available for the board
#define WORM_LENGTH 20        // Maximal length of the worm

// ### Codes for the array of positions ###
#define UNUSED_POS_ELEMENT -1 // Unused element in the worm arrays of positions

// Numbers for color pairs used by curses macro COLOR_PAIR
enum ColorPair {
  COLP_USER_WORM = 1,
  COLP_FREE_CELL,
};

// Symbols to display
#define SYMBOL_FREE_CELL ' '
#define SYMBOL_WORM_INNER_ELEMENT '0'

// Game state codes
enum GameState {
  WORM_GAME_ONGOING,  // Game is running
  WORM_OUT_OF_BOUNDS, // Left screen
  WORM_CROSSING,      // Worm head crossed another worm element
  WORM_GAME_QUIT,     // User likes to quit
};

#endif // #define _WORM_H
