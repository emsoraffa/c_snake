#include "csnake.h"
#include "ncurses.h"
#include "stdio.h"
#include <stdlib.h>
#include <unistd.h> // for usleep()

typedef struct {
  float *pos;
  int board[64][64];
} gamestate;

gamestate initialize() {
  // initialize positional array
  float *pos = (float *)malloc(10 * sizeof(float));

  gamestate init;

  for (int i = 0; i < 64; i++) {
    for (int j = 0; i < 64; j++) {
      init.board[i][j] = 0;
    }
  }
  init.pos = pos;
  return init;
}

int main(void) {
  int ch;

  initscr();
  keypad(stdscr, TRUE);
  timeout(0); // Set non-blocking input mode

  gamestate init = initialize();

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

  free(init.pos);
  endwin();
  return 0;
}
