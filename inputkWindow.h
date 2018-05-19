#include <ncurses.h>
#include "windowManager.h"

class inputkWindow
{
private:
  WINDOW *inputWIn;

public:
  inputkWindow();
  ~inputkWindow();
  WINDOW *getWin();
};