// ****************************************************************************
// Implementation of the Worm Model: Managing the Worm's Structure and Behavior
// ****************************************************************************

// Author:
// Denis Jur
// University of Applied Sciences

// The worm model

#ifndef _WORM_MODEL_H
#define _WORM_MODEL_H

#include "board_model.h"

// Worm structure
struct worm {
  int maxindex;  // Last usable index of the array pointed to by wormpos
  int headindex; // An index of the array for the worm's head position; 0 <=
                 // headindex <= maxindex

  struct pos wormpos[WORM_LENGTH]; // Array of the x & y positions of all
                                   // elements of the worm

  // The current heading of the worm
  // These are offsets from the set {-1, 0, +1}
  int dx;
  int dy;

  enum ColorPair wcolor; // Color of the worm
};

// Directions for the worm
enum WormHeading {
  WORM_UP,
  WORM_DOWN,
  WORM_LEFT,
  WORM_RIGHT,
};

// Functions concerning the management of the worm data
extern enum ResCode initializeWorm(struct worm *aworm, int len_max,
                                   struct pos headpos, enum WormHeading dir,
                                   enum ColorPair color);
extern void showWorm(struct worm *aworm);
extern void cleanWormTail(struct worm *aworm);
extern void moveWorm(struct worm *aworm, enum GameState *agame_state);
extern bool isInUseByWorm(struct worm *aworm, struct pos new_headpos);

// Getters
extern struct pos getWormHeadPos(struct worm *aworm);

// Setters
extern void setWormHeading(struct worm *aworm, enum WormHeading dir);

#endif // #define _WORM_MODEL_H
