// ****************************************************************************
// Functions of the Worm Model: Managing the Worm's Structure and Behavior
// ****************************************************************************

// Author:
// Denis Jur
// University of Applied Sciences

#include <curses.h>
#include "worm_model.h"
#include "board_model.h"
#include "worm.h"

// Last usable index for the arrays 
// theworm_wormpos_y and thworm_wormpos_x
static int theworm_max_index;

// An index for the array for the worm's head position
// 0 <= theworm_headindex <= theworm_maxindex
static int theworm_head_index;

// Data defining the worm
static int theworm_wormpos_y[WORM_LENGTH];  // Array of y-coordinates for worm elements
static int theworm_wormpos_x[WORM_LENGTH];  // Array of x-coordinates for worm elements

// The current heading of the worm
// These are offsets from the set {-1,0,+1}
static int theworm_dx;                      // Ich bewege mich um Delta x in x Richtung
static int theworm_dy;

// Code of color pair used for the worm
static enum ColorPair theworm_wcolor;

// Initialize the worm
enum ResCode initializeWorm(int len_max, int headpos_y, int headpos_x, enum WormHeading dir, enum ColorPair color) {
  // Initialize last usable index to len_max - 1
  theworm_max_index = len_max - 1;

  // Initialize head index
  theworm_head_index = 0;

  // Mark all elements as unused in the arrays of positions (Both have the same
  // length). An unused position in the array is marked with code
  // UNUSED_POS_ELEMENT
  for (int i = 0; i < sizeof(theworm_wormpos_x) / sizeof(int); i++) {
    theworm_wormpos_x[i] = UNUSED_POS_ELEMENT;
    theworm_wormpos_y[i] = UNUSED_POS_ELEMENT;
  }
  
  // Initialize position of worms head
  theworm_wormpos_x[theworm_head_index] = headpos_x;
  theworm_wormpos_y[theworm_head_index] = headpos_y;

  // Initialize the heading of the worm
  setWormHeading(dir);

  // Initialze color of the worm
  theworm_wcolor = color;

  return RES_OK;
}

// #### Setters (= Set or update values of an objects atributes, Counterpart of getters!) ###
void setWormHeading(enum WormHeading dir) {
  switch (dir) {
    case WORM_UP: // User wants up
          // Prohibit moving in opposite direction
          if (theworm_dy == 1) {
            break;
          }
        theworm_dx = 0;
        theworm_dy = -1;
        break;

    case WORM_DOWN: // User wants down
          // Prohibit moving in opposite direction
          if (theworm_dy == -1) {
            break;
          }
        theworm_dx = 0;
        theworm_dy = 1;
        break;

    case WORM_LEFT: // User wants left
          // Prohibit moving in opposite direction
          if (theworm_dx == 1) {
            break;
          }
        theworm_dx = -1;
        theworm_dy = 0;
        break;

    case WORM_RIGHT: // User wants right
          // Prohibit moving in opposite direction
          if (theworm_dx == -1) {
            break;
          }  
        theworm_dx = 1;
        theworm_dy = 0;
        break;
   }
}

// Show the worms's elements on the display
// Simple version
void showWorm() {
  // Due to our encoding we just need to show the head element
  // All other elements are already displayed
  placeItem(theworm_wormpos_y[theworm_head_index],
            theworm_wormpos_x[theworm_head_index], 
            SYMBOL_WORM_INNER_ELEMENT,
            theworm_wcolor);
}

// Cleanup worm tail element
void cleanWormTail() {
  int tail_index;

  // Compute tail_index (ring buffer)
  tail_index = (theworm_head_index + 1) % theworm_max_index;

  // Check the array of worm elements.
  // Is the array element at tail_index already in use?
  if (theworm_wormpos_x[tail_index] != UNUSED_POS_ELEMENT) {
    // YES -> Place a SYMBOL_FREE_CELL at the tail's position
    placeItem(theworm_wormpos_y[tail_index], theworm_wormpos_x[tail_index], SYMBOL_FREE_CELL, COLP_FREE_CELL);
  }
}

void moveWorm(enum GameState *agame_state) {
  // Get the current position of the worm's head element
  int headpos_x = theworm_wormpos_x[theworm_head_index];
  int headpos_y = theworm_wormpos_y[theworm_head_index];

  // Calculate the next position
  headpos_x += theworm_dx;
  headpos_y += theworm_dy;

  // Check if we would leave the display if we move the worm's head according
  // to worm's last direction.
  // We are not allowed to leave the display's window.
  if (headpos_x < 0) {
    *agame_state = WORM_OUT_OF_BOUNDS;
  } else if (headpos_x > getLastCol()) {
    *agame_state = WORM_OUT_OF_BOUNDS;
  } else if (headpos_y < 0) {
    *agame_state = WORM_OUT_OF_BOUNDS;
  } else if (headpos_y > getLastRow()) {
    *agame_state = WORM_OUT_OF_BOUNDS;
  } else {
    // We will stay within bounds.
    // Check if the worm's head will collide with itself at the new position
    if (isInUseByWorm(headpos_y, headpos_x)) {
      // Not so good -> Stop the game
      *agame_state = WORM_CROSSING;
    }
  }

  // Check status of `agame_state`
  // Go on if nothing bad happened
  if ( *agame_state == WORM_GAME_ONGOING ) {
    // Calculate new head index (ring buffer) MODULO!
    theworm_head_index++;
    theworm_head_index = theworm_head_index % theworm_max_index;

    // Store new coordinates of head element in worm structure
    theworm_wormpos_x[theworm_head_index] = headpos_x;
    theworm_wormpos_y[theworm_head_index] = headpos_y;
  }
}

// Simple collision detection
bool isInUseByWorm(int new_headpos_y, int new_headpos_x) {
  int i = 0;
  bool collision = false;

  do {
    // Compare the position of the current worm element with the new_headpos
    if (theworm_wormpos_y[i] == new_headpos_y &&
        theworm_wormpos_x[i] == new_headpos_x) {
      // Worm collided with itself -> break loop
      collision = true;
      break;
    }
    i = i + 1;
  } while (i != theworm_max_index &&
           theworm_wormpos_x[i] != UNUSED_POS_ELEMENT);

  return collision;
}

