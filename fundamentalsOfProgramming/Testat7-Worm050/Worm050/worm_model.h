// ****************************************************************************
// Implementation of the Worm Model: Managing the Worm's Structure and Behavior
// ****************************************************************************

// Author:
// Denis Jur
// University of Applied Sciences

// The worm model

#ifndef _WORM_MODEL_H
#define _WORM_MODEL_H

#include "worm.h"
#include <stdbool.h>

// Directions for the worm
enum WormHeading {
  WORM_UP,
  WORM_DOWN,
  WORM_LEFT,
  WORM_RIGHT,
};

// Functions concerning the management of the worm data
extern enum ResCode initializeWorm(int len_max, int headpos_y, int headpos_x, enum WormHeading dir, enum ColorPair color);
extern void showWorm();
extern void cleanWormTail();
extern void moveWorm(enum GameState *agame_state);
extern bool isInUseByWorm(int new_headpos_y, int new_headpos_x);

// Setters
extern void setWormHeading(enum WormHeading dir);

#endif // #define _WORM_MODEL_H
