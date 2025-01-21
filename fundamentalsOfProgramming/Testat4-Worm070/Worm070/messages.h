// A simple variant of the game Snake
//
// Author:
// Denis Jur
// University of Applied Sciences
//
// Displaying messages and dialogs

#ifndef _MESSAGES_H
#define _MESSAGES_H

#include "worm.h"
#include "worm_model.h"
#include "board_model.h"

extern void clearLineInMessageArea(int row);
extern void showStatus(struct board* aboard, struct worm* aworm);
extern int showDialog(char* prompt1, char* prompt2);

#endif  // #define _MESSAGES_H
