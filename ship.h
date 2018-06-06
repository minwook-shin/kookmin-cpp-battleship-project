#pragma once
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <set>
#include <vector>

#define X 10
#define Y 10

using namespace std;


class ship
{
private:
  vector<int> randomA;
  vector<int> randomB;
  vector<int> randomC;
  vector<int> randomD;
  vector<int> random0;

  set<int> numCheck;
  int aHp;
  int bHp;
  int cHp;
  int d1Hp;
  int d2Hp;

public:
  ship(/* args */);
  ~ship();
  bool isHit;
  void initShip();

  void setA();
  void setB();
  void setC();
  void setD1();
  void setD2();
  void hitA();
  void hitB();
  void hitC();
  void hitD1();
  void hitD2();

  int getA();
  int getB();
  int getC();
  int getD1();
  int getD2();

  int genArrow();
  void genValue();

  void drawShip(int **(&t), WINDOW *w, WINDOW *c);
};