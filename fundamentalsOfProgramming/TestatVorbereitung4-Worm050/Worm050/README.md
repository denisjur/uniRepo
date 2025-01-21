# Worm050

## What's New in This Version

- **Introduction of New Structures:**
  - `struct pos`: Stores the x and y coordinates of the worm.
  - `struct worm`: Stores all components related to a worm, such as its body parts, direction, size, etc.

- **Change in Storage Location for `userworm` Object:**
  The `userworm` object has been moved from `worm_model.c` to `worm.c`. This means that a pointer to the worm structure must now be passed around to ensure proper handling.

- **Improved Code Structure:**
  - The use of global variables in `worm_model.c` has been eliminated for better modularity and maintainability.

- **Preparation for Multiple Worms:**
  The game now supports the possibility of multiple worms in the game, opening the door for future gameplay enhancements.

- **New Message Area Added:**
  A dedicated area has been added at the bottom of the screen to display status updates and dialogs without interfering with the game area.
  - The reason for game termination can now be displayed in this message area, preventing screen corruption.

## Controls

During gameplay, the following keys have specific functions:

- `Arrow keys`: Control the movement of the worm.
- `q`: Exit the game.
- `s`: Toggle single-step mode.
- `space`: Exit single-step mode.

