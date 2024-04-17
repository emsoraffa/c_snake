
#include "csnake.h"
#include "ncurses.h"
#include "stdio.h"
#include <stdlib.h>
#include <unistd.h> // for usleep()

int *initialize() {
  // initialize positional array
  int *pos;
  pos = (int *)malloc(10 * sizeof(int));

  return pos;
}

int main(void) {
  int ch;

  initscr();
  keypad(stdscr, TRUE);
  timeout(0); // Set non-blocking input mode

  int *pos = initialize();

  while ((ch = getch()) != 'q') {

    if (ch != ERR) { // Check if a key was pressed
      switch (ch) {
      case KEY_UP:
        handle_keypress('u');
        break;
      case KEY_DOWN:
        handle_keypress('d');
        break;
      case KEY_LEFT:
        handle_keypress('l');
        break;
      case KEY_RIGHT:
        handle_keypress('r');
        break;
      }
    }

    // game logic
    render_board();

    refresh();     // Refresh the screen
    usleep(10000); // Sleep for a short while to avoid consuming excessive CPU
    clear();
  }

  endwin();
  return 0;
}
