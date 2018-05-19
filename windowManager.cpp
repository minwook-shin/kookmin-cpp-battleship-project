#include "windowManager.h"

using namespace std;

windowManager::windowManager(/* args */)
{
  initscr();
  start_color();
  setUi();
}
windowManager::~windowManager()
{
  endwin();
}
void windowManager::setUi()
{
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_WHITE);
  init_pair(3, COLOR_CYAN, COLOR_BLACK);
  init_pair(4, COLOR_YELLOW, COLOR_BLACK);
  border('*', '*', '*', '*', '*', '*', '*', '*');
  mvprintw(1, 1, "-2018 KOOKMIN .UNIV CS C++ Programming BattleShip / 20171640 minwook-shin");
};