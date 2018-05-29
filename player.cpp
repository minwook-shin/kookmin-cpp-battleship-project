#include <unistd.h>
#include <string>
#include <algorithm>
#include "player.h"

using namespace std;

player::player(/* args */) : aiInput(new char[2])
{
  srand(time(0));
  initAi();
}
player::~player() {}

void player::initAi()
{
  arr1.push_back("A1");
  arr1.push_back("A2");
  arr1.push_back("A3");
  arr1.push_back("A4");
  arr1.push_back("A5");
  arr1.push_back("A6");
  arr1.push_back("A7");
  arr1.push_back("A8");
  arr1.push_back("B1");
  arr1.push_back("B2");
  arr1.push_back("B3");
  arr1.push_back("B4");
  arr1.push_back("B5");
  arr1.push_back("B6");
  arr1.push_back("B7");
  arr1.push_back("B8");
  arr1.push_back("C1");
  arr1.push_back("C2");
  arr1.push_back("C3");
  arr1.push_back("C4");
  arr1.push_back("C5");
  arr1.push_back("C6");
  arr1.push_back("C7");
  arr1.push_back("C8");
  arr1.push_back("D1");
  arr1.push_back("D2");
  arr1.push_back("D3");
  arr1.push_back("D4");
  arr1.push_back("D5");
  arr1.push_back("D6");
  arr1.push_back("D7");
  arr1.push_back("D8");
  arr1.push_back("E1");
  arr1.push_back("E2");
  arr1.push_back("E3");
  arr1.push_back("E4");
  arr1.push_back("E5");
  arr1.push_back("E6");
  arr1.push_back("E7");
  arr1.push_back("E8");
  arr1.push_back("F1");
  arr1.push_back("F2");
  arr1.push_back("F3");
  arr1.push_back("F4");
  arr1.push_back("F5");
  arr1.push_back("F6");
  arr1.push_back("F7");
  arr1.push_back("F8");
  arr1.push_back("G1");
  arr1.push_back("G2");
  arr1.push_back("G3");
  arr1.push_back("G4");
  arr1.push_back("G5");
  arr1.push_back("G6");
  arr1.push_back("G7");
  arr1.push_back("G8");
  arr1.push_back("H1");
  arr1.push_back("H2");
  arr1.push_back("H3");
  arr1.push_back("H4");
  arr1.push_back("H5");
  arr1.push_back("H6");
  arr1.push_back("H7");
  arr1.push_back("H8");

  random_shuffle(arr1.begin(), arr1.end());
}

char *player::ai()
{
  string t = arr1[0];
  char * tmp = new char[t.length()+1];
  strcpy(tmp,t.c_str());
  aiInput = tmp;
  arr1.erase(arr1.begin());
  return aiInput;
}

void player::inputPlayer(WINDOW *DW, WINDOW *AW, WINDOW *SW, WINDOW *IW, char *(&input), int **(&t))
{
  // wgetnstr(IW, in, 2);
  in = ai();
  sleep(1);

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
