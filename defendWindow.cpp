#include "defendWindow.h"

defendWindow::defendWindow(/* args */)
{
  defendBox = newwin(20, 19, 2, 3);
  box(defendBox, 0, 0);
  wattron(defendBox, COLOR_PAIR(1));
  mvwprintw(defendBox, 1, 1, "DEFENDER");
  mvwprintw(defendBox, 3, 0, "A");
  mvwprintw(defendBox, 5, 0, "B");
  mvwprintw(defendBox, 7, 0, "C");
  mvwprintw(defendBox, 9, 0, "D");
  mvwprintw(defendBox, 11, 0, "E");
  mvwprintw(defendBox, 13, 0, "F");
  mvwprintw(defendBox, 15, 0, "G");
  mvwprintw(defendBox, 17, 0, "H");
  mvwprintw(defendBox, 19, 2, "1");
  mvwprintw(defendBox, 19, 4, "2");
  mvwprintw(defendBox, 19, 6, "3");
  mvwprintw(defendBox, 19, 8, "4");
  mvwprintw(defendBox, 19, 10, "5");
  mvwprintw(defendBox, 19, 12, "6");
  mvwprintw(defendBox, 19, 14, "7");
  mvwprintw(defendBox, 19, 16, "8");
  wrefresh(defendBox);
  defendWin = newwin(17, 17, 4, 4);
  wbkgd(defendWin, COLOR_PAIR(2));
  wrefresh(defendWin);
}
defendWindow::~defendWindow()
{
  delwin(defendBox);
  delwin(defendWin);
}
WINDOW *defendWindow::getWin()
{
  return defendWin;
}