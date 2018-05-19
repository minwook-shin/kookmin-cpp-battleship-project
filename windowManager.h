#pragma once
#include <ncurses.h>

class windowManager
{
private:
public:
  windowManager(/* args */);
  ~windowManager();
  void setUi();
  void makeWin();
};