#include <stdio.h>
#include <ncurses.h>

int main() {
  printf("hello");
  scanf("test");
  initscr();                // Initialize ncurses
  noecho();                 // Don't echo input
  cbreak();                 // Disable line buffering

  // Create a new window
  WINDOW *my_win = newwin(10, 30, 5, 5);
  box(my_win, 0, 0);       // Draw a box around the window
  mvwprintw(my_win, 1, 1, "Hello, ncurses!"); // Print text
  wrefresh(my_win);        // Refresh to show the window

  getch();                 // Wait for user input
  delwin(my_win);          // Delete the window
  endwin();                // End ncurses mode

  return 0;
}
