#pragma once
#include <ncurses.h>
#include <cstring>
#include <cstdlib>
#include "ship.h"
#define X 10
#define Y 10

class gameManager : public ship
{
private:
  int turn;
  bool isEnd;

public:
  char *turnStr;
  char *in;
  int **t;
  gameManager();
  ~gameManager();
  bool getIsend();
  void addTurn();
  int getTurn();
  int **createMap();
  void drawMap(int **(&t), WINDOW *w, WINDOW *c);
  void endGame(WINDOW* w,int i);
  void shipStatus(WINDOW *w, int i);

  void updateDefendmap(WINDOW *w, WINDOW *c);
  void updateAttackmap(WINDOW *w, char *input, WINDOW *c);
};