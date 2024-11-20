// A simple variant of the game Snake
//
// Used for teaching in classes
//
// Author:
// Denis Jur
// University of Applied Sciences
// 

#include <curses.h>
#include <string.h>

// ********************************************************************************************
// Constants, data structures
// ********************************************************************************************

// Result codes of functions
#define RES_OK 0
#define RES_FAILED 1

// *********************************************
// Standard curses initialization and cleanup
// *********************************************

// Initialize application with respect to curses settings
void initializeCursesApplication() {
    initscr(); // Initialize the curses screen

    // Note:
    // The call to initscr() defines various global variables of the curses framework.
    // stdscr, LINES, COLS, TRUE, FALSE

    noecho();  // Characters typed are not echoed
    cbreak();  // No buffering of stdin
    nonl();    // Do not translate 'return key' on keyboard to newline character
    keypad(stdscr, TRUE); // Enable the keypad
    curs_set(0);          // Make cursor invisible
    // Begin in non-single-step mode (getch will not block)
    nodelay(stdscr, TRUE);  // make getch to be a non-blocking call
}

// Reset display to normale state and terminate curses application
void cleanupCursesApp(void)
{
    standend();   // Turn off all attributes
    refresh();    // Write changes to terminal
    curs_set(1);  // Set cursor state to normal visibility
    endwin();     // Terminate curses application
}

// ********************************************************************************************
// MAIN
// ********************************************************************************************

int main(void) {
    int res_code;         // Result code from functions
    char* message_template = "Das Fenster hat xxx Zeilen und yyy Spalten";
    int msg_len;
    int min_rows = 3;

    // Here we start
    @01                             // Init various settings of our application

    msg_len = @02                   // Compute length of our template

    // Maximal LINES and COLS are set by curses for the current window size.
    // Check if the window is large enough to display our message
    if ( LINES < @03       || COLS < @03     ) {
        // Cleanup special curses settings and restore the normal terminal functionality
        @04
        // Print a conventional error message via printf.
        // Note: this only work after the call to  cleanupCursesApp();
        printf("Das Fenster ist zu klein: wir brauchen mindestens %dx%d\n", @05, @05 );

        // Set the result code to report the error
        res_code = RES_FAILED;
    } else {
        // Center output
        int mid_row = @06
        int start_col = @06

        // Write letter A to the top    left  corner of our display
        @07          // Move to position
        @07          // Put character there

        // Write letter B to the top    right corner of our display
        // Use combination of move() and addch() functions
        @08
        // Write letter C to the bottom right corner of our display
        @09
        // Write letter D to the bottom left  corner of our display
        @10
 
        // Write our message centered onto the display
        mvprintw(mid_row, start_col,"Das Fenster hat %3d Zeilen und %3d Spalten", @11, @11);

        // Refresh the screen in order to show all changes on the screen
        @12
        
        // Wait for user to press a key
        @13                   // make getch to be a blocking call
        getch();

        // Set the result code to report success
        res_code = RES_OK;

        // Cleanup special curses settings and restore the normal terminal functionality
        @14
    }
    return res_code;
}
