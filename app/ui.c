#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
  WINDOW *win;
  int height;
  int width;
  int x;
  int y;
  int id;
} windowData;

#define MAX_WINDOWS 10 

typedef windowData[MAX_WINDOWS] windowList;

typedef struct {
  windowList windows;
  int numWindows;
} state;

void makeWindow(state* s, int height,int width,int x,int y) {
  if (s->numWindows + 1 > MAX_WINDOWS) {
    //TODO: add erroring (or not)
    return;
  }
  s->numWindows += 1;
  windowData window;
  window.height = height;
  window.width = width;
  window.x = x;
  window.y = y;
  window.win = newwin(height,width,y,x);
  window.id = s->numWindows;
  
  s->windows[s->numWindows] = window;
}

void delWindow(state* s, int id) {
  s->windows[id] = NULL;
}

void renderWindow(windowData window) {
  WINDOW* nwin = window.win;
  box(nwin,0,0);
  wrefresh(nwin);
}

void renderState(state s) {
  for (int i=0;i<s.numWindows;i++) {
    renderWindow(s.windows[i]);
  }
}

//this makes an example window because why not i guess
int main() {
  initscr();
  
  int height = 10;
  int width = 20;
  int start_y = 10;
  int start_x = 10;

  WINDOW * win = newwin(height,width,start_y,start_x);
  refresh();

  box(win,0,0);
  wprintw(win, "testing window!");
  mvwprintw(win,1,1,"this is a window with all of the cools");
  wrefresh(win);

  int c = getch();

  endwin();
  return 0;

}
