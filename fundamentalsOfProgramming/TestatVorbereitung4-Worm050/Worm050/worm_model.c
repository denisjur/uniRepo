// ****************************************************************************
// Functions of the Worm Model: Managing the Worm's Structure and Behavior
// ****************************************************************************

// Author:
// Denis Jur
// University of Applied Sciences


#include "worm_model.h"
#include "board_model.h"
#include "worm.h"
#include <curses.h>

// Initialize the worm
enum ResCode initializeWorm(struct worm *aworm, int len_max, struct pos headpos,
                            enum WormHeading dir, enum ColorPair color) {
  // Initialize last usable index to len_max - 1
  aworm->maxindex = len_max - 1;

  // Initialize head index
  aworm->headindex = 0;

  // Mark all elements as unused in the arrays of positions (Both have the same
  // length). An unused position in the array is marked with code
  // UNUSED_POS_ELEMENT
  for (int i = 0; i <= aworm->maxindex; i++) {
    aworm->wormpos[i].y = UNUSED_POS_ELEMENT;
    aworm->wormpos[i].x = UNUSED_POS_ELEMENT;
  }

  // Initizialize positions of worm's head
  aworm->wormpos[aworm->headindex] = headpos;

  // Initialize the heading of the worm
  setWormHeading(aworm, dir);

  // Initialze color of the worm
  aworm->wcolor = color;

  return RES_OK;
}

// Show the worms's elements on the display
// Simple version
void showWorm(struct worm *aworm) {
  // Due to our encoding we just need to show the head element
  // All other elements are already displayed
  placeItem(aworm->wormpos[aworm->headindex].y,
            aworm->wormpos[aworm->headindex].x, SYMBOL_WORM_INNER_ELEMENT,
            aworm->wcolor);
}

// Cleanup worm tail element
void cleanWormTail(struct worm *aworm) {
  int tail_index;

  // Compute tail_index (ring buffer)
  tail_index = (aworm->headindex + 1) % aworm->maxindex;

  // Check the array of worm elements.
  // Is the array element at tail_index already in use?

  if (aworm->wormpos[tail_index].x != UNUSED_POS_ELEMENT) {
    // YES -> Place a SYMBOL_FREE_CELL at the tail's position
    placeItem(aworm->wormpos[tail_index].y, aworm->wormpos[tail_index].x,
              SYMBOL_FREE_CELL, COLP_FREE_CELL);
  }
}

void moveWorm(struct worm *aworm, enum GameState *agame_state) {
  // Get the current position of the worm's head element
  struct pos headpos = {
      aworm->wormpos[aworm->headindex].y,
      aworm->wormpos[aworm->headindex].x,
  };

  // Calculate the next position
  headpos.y += aworm->dy;
  headpos.x += aworm->dx;

  // Check if we would leave the display if we move the worm's head according
  // to worm's last direction.
  // We are not allowed to leave the display's window.
  if (headpos.x < 0) {
    *agame_state = WORM_OUT_OF_BOUNDS;
  } else if (headpos.x > getLastCol()) {
    *agame_state = WORM_OUT_OF_BOUNDS;
  } else if (headpos.y < 0) {
    *agame_state = WORM_OUT_OF_BOUNDS;
  } else if (headpos.y > getLastRow()) {
    *agame_state = WORM_OUT_OF_BOUNDS;
  } else {
    // We will stay within bounds.
    // Check if the worm's head will collide with itself at the new position
    if (isInUseByWorm(aworm, headpos)) {
      // Not so good -> Stop the game
      *agame_state = WORM_CROSSING;
    }
  }

  // Check status of `agame_state`
  // Go on if nothing bad happened
  if (*agame_state == WORM_GAME_ONGOING) {
    // Calculate new head index (ring buffer)
    aworm->headindex++;
    aworm->headindex %= aworm->maxindex;

    // Store new coordinates of head element in worm structure
    aworm->wormpos[aworm->headindex].y = headpos.y;
    aworm->wormpos[aworm->headindex].x = headpos.x;
  }
}

// Simple collision detection
bool isInUseByWorm(struct worm *aworm, struct pos new_headpos) {
  int i = 0;
  bool collision = false;

  do {
    // Compare the position of the current worm element with the new_headpos
    if (aworm->wormpos[i].y == new_headpos.y &&
        aworm->wormpos[i].x == new_headpos.x) {
      // Worm collided with itself -> break loop
      collision = true;

      break;
    }

    i++;
  } while (i != aworm->maxindex && aworm->wormpos[i].x != UNUSED_POS_ELEMENT);

  return collision;
}

// ### Getters ###
struct pos getWormHeadPos(struct worm *aworm) {
  // Structures are passed by value! -> we return a copy here
  return aworm->wormpos[aworm->headindex];
}

// ### Setters ###
void setWormHeading(struct worm *aworm, enum WormHeading dir) {
  switch (dir) {
  case WORM_UP: // User wants up
    // Prohibit to move in opposite direction
    if (aworm->dy == 1) {
      break;
    }

    aworm->dx = 0;
    aworm->dy = -1;

    break;

  case WORM_DOWN: // User wants down
    // Prohibit to move in opposite direction
    if (aworm->dy == -1) {
      break;
    }

    aworm->dx = 0;
    aworm->dy = 1;

    break;

  case WORM_LEFT: // User wants left
    // Prohibit to move in opposite direction
    if (aworm->dx == 1) {
      break;
    }

    aworm->dx = -1;
    aworm->dy = 0;

    break;

  case WORM_RIGHT: // User wants right
    // Prohibit to move in opposite direction
    if (aworm->dx == -1) {
      break;
    }

    aworm->dx = 1;
    aworm->dy = 0;

    break;
  }
}
