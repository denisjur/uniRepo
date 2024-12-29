// Displaying messages and dialogs

#ifndef _MESSAGES_H
#define _MESSAGES_H

#include "board_model.h"
#include "worm.h"
#include "worm_model.h"

extern void clearLineInMessageArea(int row);
extern void showBorderLine();
extern void showStatus(struct worm *aworm);
extern int showDialog(char *prompt1, char *prompt2);

#endif // #define _MESSAGES_H
