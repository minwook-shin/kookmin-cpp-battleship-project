#include "windowManager.h"

class attackWindow
{
private:
  WINDOW *attackBox;
  WINDOW *attackWin;

public:
  attackWindow();
  ~attackWindow();
  WINDOW *getWin();
};