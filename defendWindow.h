#include "windowManager.h"

class defendWindow{
private:
  WINDOW *defendBox;
  WINDOW *defendWin;

public:
  defendWindow();
  ~defendWindow();
  WINDOW *getWin();
};