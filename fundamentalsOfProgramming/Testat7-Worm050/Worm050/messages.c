// Displaying messages and dialogs

#include <curses.h>

#include "board_model.h"
#include "messages.h"
#include "worm.h"
#include "worm_model.h"

// Clear an entire line on the display
void clearLineInMessageArea(int row) {
  move(row, 0);

  for (int i = 1; i <= COLS; i++) {
    addch(' ');
  }
}

// Display the board line in order to separate the message area
void showBorderLine() {
  int pos_line0 = LINES - ROWS_RESERVED;

  for (int i = 0; i < COLS; i++) {
    move(pos_line0, i);
    attron(COLOR_PAIR(COLP_BARRIER));
    addch(SYMBOL_BARRIER);
    attroff(COLOR_PAIR(COLP_BARRIER));
  }
}

// Display status about the game in the message area
void showStatus(struct worm *aworm) {
  int pos_line2 = LINES - ROWS_RESERVED + 2;

  struct pos headpos = getWormHeadPos(aworm);
  mvprintw(pos_line2, 1, "Worm is at position: y=%3d x=%3d", headpos.y,
           headpos.x);
}

// Display a dialog in the message area and wait for confirmation
// String prompt1 is displayed in the second line of the message area
// String prompt2 is displayed in the  third line of the message area
int showDialog(char *prompt1, char *prompt2) {
  int pos_line1 = LINES - ROWS_RESERVED + 1;
  int pos_line2 = LINES - ROWS_RESERVED + 2;
  int pos_line3 = LINES - ROWS_RESERVED + 3;

  int ch;

  if (prompt1 == NULL) {
    return RES_FAILED;
  }

  // Delete lines in the message area
  clearLineInMessageArea(pos_line1);
  clearLineInMessageArea(pos_line2);
  clearLineInMessageArea(pos_line3);

  // Display message
  mvprintw(pos_line2, 1, "%s", prompt1);
  if (prompt2 != NULL) {
    mvprintw(pos_line3, 1, "%s", prompt2);
  }
  refresh();

  nodelay(stdscr, FALSE);
  ch = getch(); // Wait for user to press an arbitrary key
  nodelay(stdscr, TRUE);

  // Delete lines in the message area
  clearLineInMessageArea(pos_line1);
  clearLineInMessageArea(pos_line2);
  clearLineInMessageArea(pos_line3);

  // Display changes
  refresh();

  // Return code of key pressed
  return ch;
}
