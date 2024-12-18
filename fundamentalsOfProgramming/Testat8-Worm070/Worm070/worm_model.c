// A simple variant of the game Snake
//
// Author:
// Denis Jur
// University of Applied Sciences
//
// The worm model

#include <curses.h>
#include "worm.h"
#include "board_model.h"
#include "worm_model.h"

// *****************************************************
// Functions concerning the management of the worm data
// *****************************************************
// Initialize the worm
enum ResCodes initializeWorm(struct worm* aworm, int len_max, int len_cur,
struct pos headpos, enum WormHeading dir, enum ColorPairs color) {
  int i;
  // Initialize last usable index to len_max -1
  aworm->maxindex = len_max - 1;
  // Current last usable index in array. May grow upto maxindex
  aworm->cur_lastindex = len_cur - 1;
  // Initialize headindex
  aworm->headindex = 0; // Index pointing to head position is set to 0
  // Mark all elements as unused in the array of positions.
  // This allows for the effect that the worm appears element by element at
  // the start of each level
  for (i = 0; i <= aworm->maxindex; i++) {
    aworm->wormpos[i].y = UNUSED_POS_ELEM;
    aworm->wormpos[i].x = UNUSED_POS_ELEM;
  }
  // Initialize position of worms head
  aworm->wormpos[aworm->headindex] = headpos;
  // Initialize the heading of the worm
  setWormHeading(aworm, dir);
  // Initialze color of the worm
  aworm->wcolor = color;
  return RES_OK;
}

// Show the worms's elements on the display
// Simple version
void showWorm(struct board* aboard, struct worm* aworm) {
    int i = aworm->headindex;
    char symbol;
    
    int tailindex = (aworm->headindex + 1) % (aworm->cur_lastindex + 1);
    // Schleife über alle belegten Wurmelemente im Ringpuffer bis cur_lastindex
    do {
        // Bestimme das Symbol für das Wurmelement
        if (i == aworm->headindex) {
            symbol = SYMBOL_WORM_HEAD_ELEMENT;  // Kopf
        } else if (i == tailindex) {
            symbol = SYMBOL_WORM_TAIL_ELEMENT;  // Schwanz
        } else {
            symbol = SYMBOL_WORM_INNER_ELEMENT; // Körper
        }
        
        // Wurmelement zeichnen
        placeItem(aboard, aworm->wormpos[i].y, aworm->wormpos[i].x,
                  BC_USED_BY_WORM, symbol, aworm->wcolor);
        
        // Nächsten Index im Ringpuffer bestimmen
        //i = (i + 1) % (aworm->cur_lastindex + 1);  // nur bis cur_lastindex!
          i = (i+aworm->cur_lastindex) % (aworm->cur_lastindex + 1);
    } while (i != aworm->headindex && aworm->wormpos[i].y != UNUSED_POS_ELEM);
}


void cleanWormTail(struct board* aboard, struct worm* aworm) {
  // Compute tailindex
  int tailindex = (aworm->headindex + 1) % (aworm->cur_lastindex + 1);

  // Check the array of worm elements.
  // Is the array element at tailindex already in use?
  // Checking either array theworm_wormpos_y
  // or theworm_wormpos_x is enough.
  if (aworm->wormpos[tailindex].y != UNUSED_POS_ELEM &&
      aworm->wormpos[tailindex].x != UNUSED_POS_ELEM ) {
    // YES: place a SYMBOL_FREE_CELL at the tail's position

    placeItem(aboard,
              aworm->wormpos[tailindex].y,
              aworm->wormpos[tailindex].x,
              BC_FREE_CELL,
              SYMBOL_FREE_CELL,
              COLP_FREE_CELL);
  }
}


void moveWorm(struct board* aboard, struct worm* aworm, enum GameStates* agame_state) {
  
  struct pos headpos;
  headpos = aworm->wormpos[aworm->headindex];
  headpos.y += aworm->dy;
  headpos.x += aworm->dx;

  // Check if we would hit something (for good or bad) or are going to leave
  // the display if we move the worm's head according to worm's last
  // direction. We are not allowed to leave the display's window.
  if (headpos.x < 0) {
    *agame_state = WORM_OUT_OF_BOUNDS;
    } else if (headpos.x > getLastColOnBoard(aboard) ) {
    *agame_state = WORM_OUT_OF_BOUNDS;
    } else if (headpos.y < 0) {
    *agame_state = WORM_OUT_OF_BOUNDS;
    } else if (headpos.y > getLastRowOnBoard(aboard) ) {
    *agame_state = WORM_OUT_OF_BOUNDS;
    } else {

    switch ( getContentAt(aboard,headpos) ) {
      case BC_FOOD_1:
        *agame_state = WORM_GAME_ONGOING;
        // Grow worm according to food item digested
        growWorm(aworm, BONUS_1);
        decrementNumberOfFoodItems(aboard);
        break;
      case BC_FOOD_2:
        *agame_state = WORM_GAME_ONGOING;
        // Grow worm according to food item digested
        growWorm(aworm, BONUS_2);
        decrementNumberOfFoodItems(aboard);
        break;
      case BC_FOOD_3:
        *agame_state = WORM_GAME_ONGOING;
        // Grow worm according to food item digested
        growWorm(aworm, BONUS_3);
        decrementNumberOfFoodItems(aboard);
        break;
      case BC_BARRIER:
        // That's bad: stop game
        *agame_state = WORM_CRASH;
        break;
      case BC_USED_BY_WORM:
        // That's bad: stop game
        *agame_state = WORM_CROSSING;
        break;
      default:
        // Without default case we get a warning message.
        {;} // Do nothing. C syntax dictates some statement, here.
    }
  }
  // Check the status of *agame_state
  // Go on if nothing bad happened
  if ( *agame_state == WORM_GAME_ONGOING ) {
    // So all is well: we did not hit anything bad and did not leave the
    // window. --> Update the worm structure.
    // Increment headindex
    // Go round if end of worm is reached (ring buffer)
    aworm->headindex++;
    if (aworm->headindex > aworm->cur_lastindex) {
      aworm->headindex = 0;
    }
    // Store new coordinates of head element in worm structure
    aworm->wormpos[aworm->headindex] = headpos;
  }
}

void growWorm(struct worm* aworm, enum Boni growth) {
  // Play it safe and inhibit surpassing the bound
  if (aworm->cur_lastindex + growth <= aworm->maxindex) {
    aworm->cur_lastindex += growth;
  } else {
    aworm->cur_lastindex = aworm->maxindex;
    }
}

// A simple collision detection
bool isInUseByWorm(struct worm* aworm, struct pos new_headpos) {
  int i;
  bool collision = false;
  i = aworm->headindex;

  do {
    // Compare the position of the current worm element with the new_headpos
    if (aworm->wormpos[i].y == new_headpos.y && aworm->wormpos[i].x == new_headpos.x) {
      // If we find a match, a collision occurred
      collision = true;
      break;  // Exit the loop once a collision is detected
    }
    

    // Move to the next position in the circular array
    i = (i - 1 + WORM_LENGTH) % WORM_LENGTH;  // Going backwards in the worm array, as head is at index 0
  } while (i != aworm->headindex);

  // Return whether a collision was detected
  return collision;
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


// Getters
struct pos getWormHeadPos(struct worm* aworm) {
  // Structures are passed by value!
  // -> we return a copy here
  return aworm->wormpos[aworm->headindex];
}

int getWormLength(struct worm* aworm) {
    return aworm->cur_lastindex + 1;
}
// END WORM_DETAIL
