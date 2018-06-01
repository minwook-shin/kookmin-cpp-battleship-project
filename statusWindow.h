#pragma once
#include "windowManager.h"

class statusWindow
{
private:
  WINDOW *statusWin;

public:
  statusWindow();
  ~statusWindow();
  WINDOW *getWin();
};