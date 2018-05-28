#include <ncurses.h>
#include <cctype>
#include "gameManager.h"

class player : public gameManager
{
private:
  int randomInputX;
  int randomInputY;;
  char* aiInput;

public:
  player();
  ~player();
  void inputPlayer(WINDOW *DW, WINDOW *AW, WINDOW *SW, WINDOW *IW, char *(&input), int **(&t));
  char* ai();
};
