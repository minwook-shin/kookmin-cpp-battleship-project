#include "ship.h"

using namespace std;

ship::ship(/* args */)
{
  setA();
  setB();
  setC();
  setD1();
  setD2();

  srand(time(0));
  genValue();
}
ship::~ship() {}

void ship::setA() { this->aHp = 5; }
void ship::setB() { this->bHp = 4; }
void ship::setC() { this->cHp = 3; }
void ship::setD1() { this->d1Hp = 2; }
void ship::setD2() { this->d2Hp = 2; }

void ship::hitA()
{
  this->aHp--;
}
void ship::hitB()
{
  this->bHp--;
}
void ship::hitC()
{
  this->cHp--;
}
void ship::hitD1()
{
  this->d1Hp--;
}
void ship::hitD2()
{
  this->d2Hp--;
}

int ship::getA()
{
  return this->aHp;
}
int ship::getB()
{
  return this->bHp;
}
int ship::getC() { return this->cHp; }
int ship::getD1()
{
  return this->d1Hp;
}
int ship::getD2()
{
  return this->d2Hp;
}

int ship::genArrow()
{
  random0.push_back(1 + rand() % 2);
  return random0[0];
}
void ship::genValue()
{
  while (numCheck.size() != 5)
  {
    numCheck.clear();
    randomA.clear();
    randomB.clear();
    randomC.clear();
    randomD.clear();
    randomA.push_back(1 + rand() % 8);
    randomB.push_back(1 + rand() % 8);
    randomC.push_back(1 + rand() % 8);
    randomD.push_back(1 + rand() % 8);
    randomD.push_back(1 + rand() % 8);

    numCheck.insert(randomA[0]);
    numCheck.insert(randomB[0]);
    numCheck.insert(randomC[0]);
    numCheck.insert(randomD[0]);
    numCheck.insert(randomD[1]);
  }
  randomA.push_back(1 + rand() % 4);
  randomB.push_back(1 + rand() % 5);
  randomC.push_back(1 + rand() % 6);
  randomD.push_back(1 + rand() % 7);
  randomD.push_back(1 + rand() % 7);
}

void ship::drawShip(int **(&t), WINDOW *w, WINDOW *c)
{
  if (genArrow() == 1)
    for (int i = 0; i < X; i++)
    {
      for (int j = 0; j < Y; j++)
      {
        if (i == randomA[0] && j == randomA[1])
        {
          t[i][j] = 2;
          t[i][j + 1] = 2;
          t[i][j + 2] = 2;
          t[i][j + 3] = 2;
          t[i][j + 4] = 2;
        }
        if (i == randomB[0] && j == randomB[1])
        {
          t[i][j] = 3;
          t[i][j + 1] = 3;
          t[i][j + 2] = 3;
          t[i][j + 3] = 3;
        }
        if (i == randomC[0] && j == randomC[1])
        {
          t[i][j] = 4;
          t[i][j + 1] = 4;
          t[i][j + 2] = 4;
        }
        if (i == randomD[0] && j == randomD[2])
        {
          t[i][j] = 5;
          t[i][j + 1] = 5;
        }
        if (i == randomD[1] && j == randomD[3])
        {
          t[i][j] = 6;
          t[i][j + 1] = 6;
        }
      }
    }
  if (genArrow() == 2)
    for (int i = 0; i < X; i++)
    {
      for (int j = 0; j < Y; j++)
      {
        if (j == randomA[0] && i == randomA[1])
        {
          t[i][j] = 2;
          t[i + 1][j] = 2;
          t[i + 2][j] = 2;
          t[i + 3][j] = 2;
          t[i + 4][j] = 2;
        }
        if (j == randomB[0] && i == randomB[1])
        {
          t[i][j] = 3;
          t[i + 1][j] = 3;
          t[i + 2][j] = 3;
          t[i + 3][j] = 3;
        }
        if (j == randomC[0] && i == randomC[1])
        {
          t[i][j] = 4;
          t[i + 1][j] = 4;
          t[i + 2][j] = 4;
        }
        if (j == randomD[0] && i == randomD[2])
        {
          t[i][j] = 5;
          t[i + 1][j] = 5;
        }
        if (j == randomD[1] && i == randomD[3])
        {
          t[i][j] = 6;
          t[i + 1][j] = 6;
        }
      }
    }
}