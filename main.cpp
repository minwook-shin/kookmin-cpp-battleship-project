#include <ncurses.h>
#include <cstring>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <set>
#include <cctype>
#define X 10
#define Y 10

using namespace std;

class windowManager
{
private:
public:
  windowManager(/* args */)
  {
    initscr();
    start_color();
    setUi();
  }
  ~windowManager()
  {
    endwin();
  }
  void setUi()
  {
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_WHITE);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    border('*', '*', '*', '*', '*', '*', '*', '*');
    mvprintw(1, 1, "-2018 KOOKMIN .UNIV CS C++ Programming BattleShip / 20171640 minwook-shin");
  };
  void makeWin();
};

class defendWindow : public windowManager
{
private:
  WINDOW *defendBox;
  WINDOW *defendWin;

public:
  defendWindow(/* args */)
  {
    defendBox = newwin(20, 19, 2, 3);
    box(defendBox, 0, 0);
    wattron(defendBox, COLOR_PAIR(1));
    mvwprintw(defendBox, 1, 1, "DEFENDER");
    mvwprintw(defendBox, 3, 0, "A");
    mvwprintw(defendBox, 5, 0, "B");
    mvwprintw(defendBox, 7, 0, "C");
    mvwprintw(defendBox, 9, 0, "D");
    mvwprintw(defendBox, 11, 0, "E");
    mvwprintw(defendBox, 13, 0, "F");
    mvwprintw(defendBox, 15, 0, "G");
    mvwprintw(defendBox, 17, 0, "H");
    mvwprintw(defendBox, 19, 2, "1");
    mvwprintw(defendBox, 19, 4, "2");
    mvwprintw(defendBox, 19, 6, "3");
    mvwprintw(defendBox, 19, 8, "4");
    mvwprintw(defendBox, 19, 10, "5");
    mvwprintw(defendBox, 19, 12, "6");
    mvwprintw(defendBox, 19, 14, "7");
    mvwprintw(defendBox, 19, 16, "8");
    wrefresh(defendBox);
    defendWin = newwin(17, 17, 4, 4);
    wbkgd(defendWin, COLOR_PAIR(2));
    wrefresh(defendWin);
  }
  ~defendWindow()
  {
    delwin(defendBox);
    delwin(defendWin);
  }
  WINDOW *getWin() { return defendWin; }
};

class attackWindow : public windowManager
{
private:
  WINDOW *attackBox;
  WINDOW *attackWin;

public:
  attackWindow(/* args */)
  {
    attackBox = newwin(20, 19, 2, 25);
    box(attackBox, 0, 0);
    wattron(attackBox, COLOR_PAIR(1));
    mvwprintw(attackBox, 1, 1, "ATTACKER");
    mvwprintw(attackBox, 3, 0, "A");
    mvwprintw(attackBox, 5, 0, "B");
    mvwprintw(attackBox, 7, 0, "C");
    mvwprintw(attackBox, 9, 0, "D");
    mvwprintw(attackBox, 11, 0, "E");
    mvwprintw(attackBox, 13, 0, "F");
    mvwprintw(attackBox, 15, 0, "G");
    mvwprintw(attackBox, 17, 0, "H");
    mvwprintw(attackBox, 19, 2, "1");
    mvwprintw(attackBox, 19, 4, "2");
    mvwprintw(attackBox, 19, 6, "3");
    mvwprintw(attackBox, 19, 8, "4");
    mvwprintw(attackBox, 19, 10, "5");
    mvwprintw(attackBox, 19, 12, "6");
    mvwprintw(attackBox, 19, 14, "7");
    mvwprintw(attackBox, 19, 16, "8");
    wrefresh(attackBox);
    attackWin = newwin(17, 17, 4, 26);
    wbkgd(attackWin, COLOR_PAIR(2));
    wrefresh(attackWin);
  }
  ~attackWindow()
  {
    delwin(attackBox);
    delwin(attackWin);
  }
  WINDOW *getWin() { return attackWin; }
};

class statusWindow : public windowManager
{
private:
  WINDOW *statusWin;

public:
  statusWindow(/* args */)
  {
    statusWin = newwin(9, 30, 3, 48);
    box(statusWin, 0, 0);
    wattron(statusWin, COLOR_PAIR(3));
    mvwprintw(statusWin, 1, 1, "<STATUS>");
    mvwprintw(statusWin, 2, 1, "TURN : 0");
    mvwprintw(statusWin, 3, 1, "AIRCRAFT : AAAAA");
    mvwprintw(statusWin, 4, 1, "BATTLESHIP : BBBB");
    mvwprintw(statusWin, 5, 1, "CRUISER : CCC");
    mvwprintw(statusWin, 6, 1, "DESTROYER : DD DD");
    mvwprintw(statusWin, 7, 1, "INPUT TEXT : ");
    wrefresh(statusWin);
  }
  ~statusWindow() { delwin(statusWin); }
  WINDOW *getWin() { return statusWin; }
};

class inputkWindow : public windowManager
{
private:
  WINDOW *inputWIn;

public:
  inputkWindow(/* args */)
  {
    inputWIn = newwin(10, 30, 12, 48);
    box(inputWIn, 0, 0);
    wattron(inputWIn, COLOR_PAIR(4));
    mvwprintw(inputWIn, 1, 1, "input position...(ex A3) ");
    mvwprintw(inputWIn, 2, 1, "input : ");
    mvwprintw(inputWIn, 3, 1, "[EXIT : ctrl + c]");
    wmove(inputWIn, 2, 9);
    wrefresh(inputWIn);
  }
  ~inputkWindow() { delwin(inputWIn); }
  WINDOW *getWin() { return inputWIn; }
};

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
  ship(/* args */)
  {
    setA();
    setB();
    setC();
    setD1();
    setD2();

    srand(time(0));
    genValue();
  }
  ~ship() {}

  void setA() { this->aHp = 5; }
  void setB() { this->bHp = 4; }
  void setC() { this->cHp = 3; }
  void setD1() { this->d1Hp = 2; }
  void setD2() { this->d2Hp = 2; }

  void hitA() { this->aHp--; }
  void hitB() { this->bHp--; }
  void hitC() { this->cHp--; }
  void hitD1() { this->d1Hp--; }
  void hitD2() { this->d2Hp--; }

  int getA() { return this->aHp; }
  int getB() { return this->bHp; }
  int getC() { return this->cHp; }
  int getD1() { return this->d1Hp; }
  int getD2() { return this->d2Hp; }

  int getA(int i)
  {
    return randomA[i];
  }
  int getB(int i)
  {
    return randomB[i];
  }
  int getC(int i)
  {
    return randomC[i];
  }
  int getD(int i)
  {
    return randomD[i];
  }
  int genArrow()
  {
    random0.push_back(1 + rand() % 2);
    return random0[0];
  }
  void genValue()
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

  void drawShip(int **(&t), WINDOW *w, WINDOW *c)
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
};

class gameManager : public ship
{
private:
  int turn;
  bool isEnd;

public:
  char *turnStr;
  char *in;
  int **t;
  gameManager(/* args */) : turn(0), isEnd(true), turnStr(new char[2]), in(new char[3]) {}
  ~gameManager()
  {
    delete[] turnStr;
    delete[] in;
    delete[] t;
  }
  bool getIsend()
  {
    return isEnd;
  }
  void addTurn()
  {
    turn++;
  }
  int getTurn()
  {
    return this->turn;
  }
  int **createMap()
  {
    t = new int *[X];
    for (int i = 0; i < X; ++i)
    {
      t[i] = new int[Y];
      memset(t[i], 0, 4 * Y);
    }
    return t;
  }
  void drawMap(int **(&t), WINDOW *w, WINDOW *c)
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

  void endGame()
  {
    exit(0);
  }

  void shipStatus(WINDOW *w,int i)
  {
    if (getA() == 5)
    {
      mvwprintw(w, 3, 1, "                ");
      mvwprintw(w, 3, 1, "AIRCRAFT : AAAAA");
      wrefresh(w);
    }
    if (getA() == 4)
    {
      mvwprintw(w, 3, 1, "                ");
      mvwprintw(w, 3, 1, "AIRCRAFT : AAAA ");
      wrefresh(w);
    }
    if (getA() == 3)
    {
      mvwprintw(w, 3, 1, "                ");
      mvwprintw(w, 3, 1, "AIRCRAFT : AAA  ");
      wrefresh(w);
    }
    if (getA() == 2)
    {
      mvwprintw(w, 3, 1, "                ");
      mvwprintw(w, 3, 1, "AIRCRAFT : AA   ");
      wrefresh(w);
    }
    if (getA() == 1)
    {
      mvwprintw(w, 3, 1, "                ");
      mvwprintw(w, 3, 1, "AIRCRAFT : A    ");
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
      mvwprintw(w, 4, 1, "BATTLESHIP : BBBB");
      wrefresh(w);
    }
    if (getB() == 3)
    {
      mvwprintw(w, 4, 1, "                 ");
      mvwprintw(w, 4, 1, "BATTLESHIP : BBB ");
      wrefresh(w);
    }
    if (getB() == 2)
    {
      mvwprintw(w, 4, 1, "                 ");
      mvwprintw(w, 4, 1, "BATTLESHIP : BB  ");
      wrefresh(w);
    }
    if (getB() == 1)
    {
      mvwprintw(w, 4, 1, "                 ");
      mvwprintw(w, 4, 1, "BATTLESHIP : B   ");
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
      mvwprintw(w, 5, 1, "CRUISER : CCC ");
      wrefresh(w);
    }
    if (getC() == 2)
    {
      mvwprintw(w, 5, 1, "              ");
      mvwprintw(w, 5, 1, "CRUISER : CC  ");
      wrefresh(w);
    }
    if (getC() == 1)
    {
      mvwprintw(w, 5, 1, "              ");
      mvwprintw(w, 5, 1, "CRUISER : C   ");
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
      mvwprintw(w, 6, 1, "DESTROYER : DD");
      wrefresh(w);
    }
    if (getD1() == 1)
    {
      mvwprintw(w, 6, 1, "              ");
      mvwprintw(w, 6, 1, "DESTROYER : D ");
      wrefresh(w);
    }
    if (getD1() == 0)
    {
      mvwprintw(w, 6, 1, "              ");
      mvwprintw(w, 6, 1, "DESTROYER :   ");
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
      endGame();
    }
  }

  void updateDefendmap(WINDOW *w, WINDOW *c)
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
  void updateAttackmap(WINDOW *w, char *input, WINDOW *c)
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
};

class player : public gameManager
{
private:
  /* data */
public:
  player(/* args */) {}
  ~player() {}
  void inputPlayer(WINDOW *DW, WINDOW *AW, WINDOW *SW, WINDOW *IW, char *(&input), int **(&t))
  {
    wgetnstr(IW, in, 2);

    if (toupper(in[0]) == 'A' || toupper(in[0]) == 'B' || toupper(in[0]) == 'C' || toupper(in[0]) == 'D' || toupper(in[0]) == 'E' || toupper(in[0]) == 'F' || toupper(in[0]) == 'G' || toupper(in[0]) == 'H')
    {
      if (in[1] == '1' || in[1] == '2' || in[1] == '3' || in[1] == '4' || in[1] == '5' || in[1] == '6' || in[1] == '7' || in[1] == '8')
      {

        mvwprintw(SW, 7, 14, in);

        if (in[0] == 'A' || in[0] == 'a')
        {
          in[0] = '1';
        }
        if (in[0] == 'B' || in[0] == 'b')
        {
          in[0] = '2';
        }
        if (in[0] == 'C' || in[0] == 'c')
        {
          in[0] = '3';
        }
        if (in[0] == 'D' || in[0] == 'd')
        {
          in[0] = '4';
        }
        if (in[0] == 'E' || in[0] == 'e')
        {
          in[0] = '5';
        }
        if (in[0] == 'F' || in[0] == 'f')
        {
          in[0] = '6';
        }
        if (in[0] == 'G' || in[0] == 'g')
        {
          in[0] = '7';
        }
        if (in[0] == 'H' || in[0] == 'h')
        {
          in[0] = '8';
        }
        int tmp = atoi(in);
        if (t[tmp / 10][tmp % 10] != 7 && t[tmp / 10][tmp % 10] != 8)
        {
          addTurn();
        }

        sprintf(turnStr, "%d", getTurn());
        mvwprintw(SW, 2, 8, turnStr);
        wrefresh(SW);
        wmove(IW, 2, 9);
        mvwprintw(IW, 2, 9, "  ");
        wrefresh(IW);
        input = in;
      }
      else
      {
        mvwprintw(IW, 2, 9, "  ");
        wrefresh(IW);
        wmove(IW, 2, 9);
      }
    }
    else
    {
      mvwprintw(IW, 2, 9, "  ");
      wrefresh(IW);
      wmove(IW, 2, 9);
    }
  }
};

int main()
{
  gameManager gm;
  windowManager wm;
  player a;
  gm.createMap();

  refresh();

  defendWindow dw;
  attackWindow aw;
  statusWindow sw;
  inputkWindow iw;

  gm.drawMap(gm.t, aw.getWin(), iw.getWin());

  while (true)
  {
    gm.updateDefendmap(dw.getWin(), iw.getWin());
    gm.updateAttackmap(aw.getWin(), gm.in, iw.getWin());
    gm.shipStatus(sw.getWin(),gm.getTurn());
    a.inputPlayer(dw.getWin(), aw.getWin(), sw.getWin(), iw.getWin(), gm.in,gm.t);
  }

  getch();

  return 0;
}
