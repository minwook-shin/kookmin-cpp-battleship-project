#include <ncurses.h>
#include <cctype>
#include <string>
#include "gameManager.h"

class player : public gameManager
{
private:
  vector<string> arr1;
  char* aiInput;

public:
  player();
  ~player();
  void inputPlayer(WINDOW *DW, WINDOW *AW, WINDOW *SW, WINDOW *IW, char *(&input), int **(&t));
  char* ai();
  void initAi();
};