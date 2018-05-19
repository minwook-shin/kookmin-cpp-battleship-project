#include "statusWindow.h"

statusWindow::statusWindow(/* args */)
{
  statusWin = newwin(9, 30, 3, 48);
  box(statusWin, 0, 0);
  wattron(statusWin, COLOR_PAIR(3));
  mvwprintw(statusWin, 1, 1, "<STATUS>");
  mvwprintw(statusWin, 2, 1, "TURN : 0");
  mvwprintw(statusWin, 3, 1, "AIRCRAFT : AAAAA");
  mvwprintw(statusWin, 4, 1, "BATTLESHIP : BBBB");
  mvwprintw(statusWin, 5, 1, "CRUISER : CCC");
  mvwprintw(statusWin, 6, 1, "DESTROYER : DD DD");
  mvwprintw(statusWin, 7, 1, "INPUT TEXT : ");
  wrefresh(statusWin);
}
statusWindow::~statusWindow()
{
  delwin(statusWin);
}
WINDOW *statusWindow::getWin()
{
  return statusWin;
}