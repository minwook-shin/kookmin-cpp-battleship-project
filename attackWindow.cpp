#include "attackWindow.h"
attackWindow::attackWindow(/* args */)
{
  attackBox = newwin(20, 19, 2, 25);
  box(attackBox, 0, 0);
  wattron(attackBox, COLOR_PAIR(1));
  mvwprintw(attackBox, 1, 1, "ATTACKER");
  mvwprintw(attackBox, 3, 0, "A");
  mvwprintw(attackBox, 5, 0, "B");
  mvwprintw(attackBox, 7, 0, "C");
  mvwprintw(attackBox, 9, 0, "D");
  mvwprintw(attackBox, 11, 0, "E");
  mvwprintw(attackBox, 13, 0, "F");
  mvwprintw(attackBox, 15, 0, "G");
  mvwprintw(attackBox, 17, 0, "H");
  mvwprintw(attackBox, 19, 2, "1");
  mvwprintw(attackBox, 19, 4, "2");
  mvwprintw(attackBox, 19, 6, "3");
  mvwprintw(attackBox, 19, 8, "4");
  mvwprintw(attackBox, 19, 10, "5");
  mvwprintw(attackBox, 19, 12, "6");
  mvwprintw(attackBox, 19, 14, "7");
  mvwprintw(attackBox, 19, 16, "8");
  wrefresh(attackBox);
  attackWin = newwin(17, 17, 4, 26);
  wbkgd(attackWin, COLOR_PAIR(2));
  wrefresh(attackWin);
}
attackWindow::~attackWindow()
{
  delwin(attackBox);
  delwin(attackWin);
}
WINDOW *attackWindow::getWin()
{
  return attackWin;
}