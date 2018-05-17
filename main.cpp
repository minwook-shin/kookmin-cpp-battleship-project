#include <ncurses.h>
#include <cstring>
#include <vector>
#include <iostream>
#include <stdlib.h>
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
    init_pair(2, COLOR_GREEN, COLOR_BLUE);
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
  ~defendWindow() {}
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
  ~attackWindow() {}
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
  ~statusWindow() {}
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
  ~inputkWindow() {}
  WINDOW *getWin() { return inputWIn; }
};

class gameManager
{
private:
  int turn;
  bool isEnd;

public:
  char *turnStr;
  char *in;
  int **t;
  gameManager(/* args */) : turn(0), isEnd(false), turnStr(new char[2]), in(new char[3]) {}
  ~gameManager() {}
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
    return turn;
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
      }
    }
    wrefresh(w);
    wmove(c, 2, 9);
  }
  void updateAttackmap(WINDOW *w, char *input, WINDOW *c)
  { // AAAAA : 2 , BBBB : 3 , CCC : 4 , DD : 5
    int tmp = atoi(input);
    t[tmp / 10][tmp % 10] = 6;
    
    for (int i = 0; i < X; i++)
    {
      for (int j = 0; j < Y; j++)
      {
        if (t[i][j] == 0)
        {
          mvwprintw(w, i * 2 - 1, j * 2 - 1, "0");
        }
        if (t[i][j] == 2)
        {
          mvwprintw(w, i * 2 - 1, j * 2 - 1, "0");
        }
        if (t[i][j] == 3)
        {
          mvwprintw(w, i * 2 - 1, j * 2 - 1, "0");
        }
        if (t[i][j] == 4)
        {
          mvwprintw(w, i * 2 - 1, j * 2 - 1, "0");
        }
        if (t[i][j] == 5)
        {
          mvwprintw(w, i * 2 - 1, j * 2 - 1, "0");
        }
        if (t[i][j] == 6)
        {
          mvwprintw(w, i * 2 - 1, j * 2 - 1, "H");
        }
      }
    }
    wmove(c, 2, 9);

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
  void inputPlayer(WINDOW *DW, WINDOW *AW, WINDOW *SW, WINDOW *IW, char *(&input))
  {
    wgetnstr(IW, in, 2);

    if (in[0] == 'A' || in[0] == 'B' || in[0] == 'C' || in[0] == 'D' || in[0] == 'E' || in[0] == 'F' || in[0] == 'G' || in[0] == 'H')
    {
      if (in[1] == '1' || in[1] == '2' || in[1] == '3' || in[1] == '4' || in[1] == '5' || in[1] == '6' || in[1] == '7' || in[1] == '8')
      {

        mvwprintw(SW, 7, 14, in);
        addTurn();
        sprintf(turnStr, "%d", getTurn());
        mvwprintw(SW, 2, 8, turnStr);
        wrefresh(SW);
        wmove(IW, 2, 9);

        if (in[0] == 'A')
        {
          in[0] = '1';
        }
        if (in[0] == 'B')
        {
          in[0] = '2';
        }
        if (in[0] == 'C')
        {
          in[0] = '3';
        }
        if (in[0] == 'D')
        {
          in[0] = '4';
        }
        if (in[0] == 'E')
        {
          in[0] = '5';
        }
        if (in[0] == 'F')
        {
          in[0] = '6';
        }
        if (in[0] == 'G')
        {
          in[0] = '7';
        }
        if (in[0] == 'H')
        {
          in[0] = '8';
        }

        input = in;
      }
      else
      {
        wmove(IW, 2, 9);
      }
    }
    else
    {
      wmove(IW, 2, 9);
    }
  }
};

class ship
{
private:
  /* data */
public:
  ship(/* args */) {}
  ~ship() {}
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

  while (gm.getIsend() == false)
  {
    gm.updateDefendmap(dw.getWin(), iw.getWin());
    gm.updateAttackmap(aw.getWin(), gm.in, iw.getWin());
    a.inputPlayer(dw.getWin(), aw.getWin(), sw.getWin(), iw.getWin(), gm.in);
  }

  getch();

  return 0;
}
