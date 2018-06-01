#include "gameManager.h"
#include<iostream>
#include<fstream>

using namespace std;

gameManager::gameManager() : turn(0), isEnd(true), turnStr(new char[2]), in(new char[3]) {}
gameManager::~gameManager()
{
  delete[] turnStr;
  delete[] in;
  for (int i = 0; i < X; ++i)
  {
    delete[] t[i];
  }
}
bool gameManager::getIsend()
{
  return isEnd;
}
void gameManager::addTurn()
{
  turn++;
}
int gameManager::getTurn()
{
  return turn;
}
int **gameManager::createMap()
{
  t = new int *[X];
  for (int i = 0; i < X; ++i)
  {
    t[i] = new int[Y];
    memset(t[i], 0, 4 * Y);
  }
  return t;
}
void gameManager::drawMap(int **(&t), WINDOW *w, WINDOW *c)
{
  for (int i = 0; i < X; i++)
  {
    for (int j = 0; j < Y; j++)
    {
      if (i == 0)
      {
        t[i][j] = 1;
      }
      if (j == 0)
      {
        t[i][j] = 1;
      }
      if (j == 9)
      {
        t[i][j] = 1;
      }
      if (i == 9)
      {
        t[i][j] = 1;
      }
    }
    drawShip(t, w, c);
  }
}

void gameManager::endGame(WINDOW *w,int i)
{
  sprintf(turnStr, "%d",i);
  mvwprintw(w,2,15,turnStr);
  wrefresh(w);
  ofstream file("turn.txt", ios::app);
  file <<i;
  file << " ";
  file.close();
  exit(0);
}

void gameManager::shipStatus(WINDOW *w, int i)
{
  if (getA() == 5)
  {
    mvwprintw(w, 3, 1, "                ");
    mvwprintw(w, 3, 1, "AIRCRAFT : AAAAA  ");
    wrefresh(w);
  }
  if (getA() == 4)
  {
    mvwprintw(w, 3, 1, "                ");
    mvwprintw(w, 3, 1, "AIRCRAFT : AAAA   ");
    wrefresh(w);
  }
  if (getA() == 3)
  {
    mvwprintw(w, 3, 1, "                ");
    mvwprintw(w, 3, 1, "AIRCRAFT : AAA    ");
    wrefresh(w);
  }
  if (getA() == 2)
  {
    mvwprintw(w, 3, 1, "                ");
    mvwprintw(w, 3, 1, "AIRCRAFT : AA     ");
    wrefresh(w);
  }
  if (getA() == 1)
  {
    mvwprintw(w, 3, 1, "                ");
    mvwprintw(w, 3, 1, "AIRCRAFT : A      ");
    wrefresh(w);
  }
  if (getA() == 0)
  {
    mvwprintw(w, 3, 1, "                ");
    mvwprintw(w, 3, 1, "AIRCRAFT DESTROYED");
    wrefresh(w);
  }
  if (getB() == 4)
  {
    mvwprintw(w, 4, 1, "                 ");
    mvwprintw(w, 4, 1, "BATTLESHIP : BBBB   ");
    wrefresh(w);
  }
  if (getB() == 3)
  {
    mvwprintw(w, 4, 1, "                 ");
    mvwprintw(w, 4, 1, "BATTLESHIP : BBB    ");
    wrefresh(w);
  }
  if (getB() == 2)
  {
    mvwprintw(w, 4, 1, "                 ");
    mvwprintw(w, 4, 1, "BATTLESHIP : BB     ");
    wrefresh(w);
  }
  if (getB() == 1)
  {
    mvwprintw(w, 4, 1, "                 ");
    mvwprintw(w, 4, 1, "BATTLESHIP : B      ");
    wrefresh(w);
  }
  if (getB() == 0)
  {
    mvwprintw(w, 4, 1, "                  ");
    mvwprintw(w, 4, 1, "BATTLESHIP DESTROYED");
    wrefresh(w);
  }

  if (getC() == 3)
  {
    mvwprintw(w, 5, 1, "              ");
    mvwprintw(w, 5, 1, "CRUISER : CCC    ");
    wrefresh(w);
  }
  if (getC() == 2)
  {
    mvwprintw(w, 5, 1, "              ");
    mvwprintw(w, 5, 1, "CRUISER : CC     ");
    wrefresh(w);
  }
  if (getC() == 1)
  {
    mvwprintw(w, 5, 1, "              ");
    mvwprintw(w, 5, 1, "CRUISER : C      ");
    wrefresh(w);
  }
  if (getC() == 0)
  {
    mvwprintw(w, 5, 1, "                ");
    mvwprintw(w, 5, 1, "CRUISER DESTROYED");
    wrefresh(w);
  }

  if (getD1() == 2)
  {
    mvwprintw(w, 6, 1, "              ");
    mvwprintw(w, 6, 1, "DESTROYER : DD     ");
    wrefresh(w);
  }
  if (getD1() == 1)
  {
    mvwprintw(w, 6, 1, "              ");
    mvwprintw(w, 6, 1, "DESTROYER : D      ");
    wrefresh(w);
  }
  if (getD1() == 0)
  {
    mvwprintw(w, 6, 1, "              ");
    mvwprintw(w, 6, 1, "DESTROYER :        ");
    wrefresh(w);
  }

  if (getD2() == 2)
  {
    mvwprintw(w, 6, 16, "  ");
    mvwprintw(w, 6, 16, "DD");
    wrefresh(w);
  }
  if (getD2() == 1)
  {
    mvwprintw(w, 6, 16, "  ");
    mvwprintw(w, 6, 16, "D ");
    wrefresh(w);
  }
  if (getD2() == 0)
  {
    mvwprintw(w, 6, 16, "  ");
    wrefresh(w);
  }
  if (getD1() == 0 && getD2() == 0)
  {
    mvwprintw(w, 6, 1, "                   ");
    mvwprintw(w, 6, 1, "DESTROYER DESTROYED");
    wrefresh(w);
  }
  if (getA() == 0 && getB() == 0 && getC() == 0 && getD1() == 0 && getD2() == 0)
  {
    endGame(w,i);
  }
}

void gameManager::updateDefendmap(WINDOW *w, WINDOW *c)
{ // AAAAA : 2 , BBBB : 3 , CCC : 4 , DD : 5
  for (int i = 0; i < X; i++)
  {
    for (int j = 0; j < Y; j++)
    {
      if (t[i][j] == 0)
      {
        mvwprintw(w, i * 2 - 1, j * 2 - 1, "O");
      }
      if (t[i][j] == 2)
      {
        mvwprintw(w, i * 2 - 1, j * 2 - 1, "A");
      }
      if (t[i][j] == 3)
      {
        mvwprintw(w, i * 2 - 1, j * 2 - 1, "B");
      }
      if (t[i][j] == 4)
      {
        mvwprintw(w, i * 2 - 1, j * 2 - 1, "C");
      }
      if (t[i][j] == 5)
      {
        mvwprintw(w, i * 2 - 1, j * 2 - 1, "D");
      }
      if (t[i][j] == 6)
      {
        mvwprintw(w, i * 2 - 1, j * 2 - 1, "D");
      }
    }
  }
  wrefresh(w);
  wmove(c, 2, 9);
}
void gameManager::updateAttackmap(WINDOW *w, char *input, WINDOW *c)
{ // AAAAA : 2 , BBBB : 3 , CCC : 4 , DD : 5
  int tmp = atoi(input);
  for (int i = 0; i < X; i++)
  {
    for (int j = 0; j < Y; j++)
    {
      if (t[tmp / 10][tmp % 10] == 0)
      {
        t[tmp / 10][tmp % 10] = 7;
      }
      if (t[tmp / 10][tmp % 10] == 2)
      {
        hitA();
        t[tmp / 10][tmp % 10] = 8;
      }
      if (t[tmp / 10][tmp % 10] == 3)
      {
        hitB();
        t[tmp / 10][tmp % 10] = 8;
      }
      if (t[tmp / 10][tmp % 10] == 4)
      {
        hitC();
        t[tmp / 10][tmp % 10] = 8;
      }
      if (t[tmp / 10][tmp % 10] == 5)
      {
        hitD1();
        t[tmp / 10][tmp % 10] = 8;
      }
      if (t[tmp / 10][tmp % 10] == 6)
      {
        hitD2();
        t[tmp / 10][tmp % 10] = 8;
      }
    }
  }

  for (int i = 0; i < X; i++)
  {
    for (int j = 0; j < Y; j++)
    {
      if (t[i][j] == 0)
      {
        mvwprintw(w, i * 2 - 1, j * 2 - 1, "O");
      }
      if (t[i][j] == 2)
      {
        mvwprintw(w, i * 2 - 1, j * 2 - 1, "O");
      }
      if (t[i][j] == 3)
      {
        mvwprintw(w, i * 2 - 1, j * 2 - 1, "O");
      }
      if (t[i][j] == 4)
      {
        mvwprintw(w, i * 2 - 1, j * 2 - 1, "O");
      }
      if (t[i][j] == 5)
      {
        mvwprintw(w, i * 2 - 1, j * 2 - 1, "O");
      }
      if (t[i][j] == 6)
      {
        mvwprintw(w, i * 2 - 1, j * 2 - 1, "O");
      }
      if (t[i][j] == 7)
      {
        mvwprintw(w, i * 2 - 1, j * 2 - 1, "M");
      }
      if (t[i][j] == 8)
      {
        mvwprintw(w, i * 2 - 1, j * 2 - 1, "H");
      }
    }
  }
  wmove(c, 2, 9);
  wrefresh(c);
  wrefresh(w);
  wmove(c, 2, 9);
}