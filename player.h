#include <ncurses.h>
#include <cctype>
#include <string>
#include "gameManager.h"

class player : public gameManager
{
private:
  vector<string> arr1;
  char* aiInput ;
  char* intelliWord;
  vector<string> arr2;

public:
  player();
  ~player();
  void inputPlayer(WINDOW *DW, WINDOW *AW, WINDOW *SW, WINDOW *IW, char *(&input), int **(&t));
  char* ai(int **(&map));
  void initAi();
};