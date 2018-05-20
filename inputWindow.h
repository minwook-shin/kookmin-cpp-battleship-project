#include <ncurses.h>
#include "windowManager.h"

class inputWindow
{
private:
  WINDOW *inputWIn;

public:
  inputWindow();
  ~inputWindow();
  WINDOW *getWin();
};