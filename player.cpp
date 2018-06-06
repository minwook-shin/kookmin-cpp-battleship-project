#include <unistd.h>
#include <string>
#include <algorithm>
#include <iostream>
#include "player.h"

using namespace std;

player::player(/* args */) : aiInput(new char[2]), intelliWord(new char[2])
{
  srand(time(0));
  initAi();
}
player::~player() {}

void player::initAi()
{
  arr1.push_back("B2");
  arr1.push_back("B4");
  arr1.push_back("B6");
  arr1.push_back("C5");
  arr1.push_back("C7");
  arr1.push_back("D2");
  arr1.push_back("D4");
  arr1.push_back("E3");
  arr1.push_back("E5");
  arr1.push_back("E7");
  arr1.push_back("F2");
  arr1.push_back("F6");
  arr1.push_back("G3");
  arr1.push_back("G5");
  arr1.push_back("G7");
  /*-------------------15*/
  arr1.push_back("A3");
  arr1.push_back("A7");
  arr1.push_back("C1");
  arr1.push_back("D8");
  arr1.push_back("G1");
  arr1.push_back("H4");
  /*-------------------21*/
  arr1.push_back("C3");
  arr1.push_back("D6");
  arr1.push_back("F4");
  /*-------------------24*/
  arr1.push_back("A1");
  arr1.push_back("A5");
  arr1.push_back("B8");
  arr1.push_back("E1");
  arr1.push_back("F8");
  arr1.push_back("H2");
  arr1.push_back("H6");
  arr1.push_back("H8");
  /*-------------------32*/
  arr1.push_back("A2");
  arr1.push_back("A4");
  arr1.push_back("A6");
  arr1.push_back("A8");
  arr1.push_back("B1");
  arr1.push_back("B3");
  arr1.push_back("B5");
  arr1.push_back("B7");
  arr1.push_back("C2");
  arr1.push_back("C4");
  arr1.push_back("C6");
  arr1.push_back("C8");
  arr1.push_back("D1");
  arr1.push_back("D3");
  arr1.push_back("D5");
  arr1.push_back("D7");
  arr1.push_back("E2");
  arr1.push_back("E4");
  arr1.push_back("E6");
  arr1.push_back("E8");
  arr1.push_back("F1");
  arr1.push_back("F3");
  arr1.push_back("F5");
  arr1.push_back("F7");
  arr1.push_back("G2");
  arr1.push_back("G4");
  arr1.push_back("G6");
  arr1.push_back("G8");
  arr1.push_back("H1");
  arr1.push_back("H3");
  arr1.push_back("H5");
  arr1.push_back("H7");
  srand(time(0));
  random_shuffle(arr1.begin(), arr1.begin() + 15);
  srand(time(0));
  random_shuffle(arr1.begin() + 16, arr1.begin() + 21);
  srand(time(0));
  random_shuffle(arr1.begin() + 22, arr1.begin() + 24);
  srand(time(0));
  random_shuffle(arr1.begin() + 25, arr1.begin() + 32);
  srand(time(0));
  random_shuffle(arr1.begin() + 33, arr1.end());
}

char *player::ai(int **(&map))
{
  if (arr2.empty())
  {
    string t = arr1[0];
    strcpy(aiInput, t.c_str());
    arr1.erase(arr1.begin());

    int tmp1 = t[0] - 64;
    int tmp2 = t[1] - 48;

    if (map[tmp1][t[1] - 48] == 2 || map[tmp1][t[1] - 48] == 3 || map[tmp1][t[1] - 48] == 4 || map[tmp1][t[1] - 48] == 5 || map[tmp1][t[1] - 48] == 6)
    {
      string tmpWord1(2, '0');
      tmpWord1[0] = (char)tmp1 + 64;
      tmpWord1[1] = (char)tmp2 + 49;
      
      string tmpWord2(2, '0');
      tmpWord2[0] = (char)tmp1 + 64;
      tmpWord2[1] = (char)tmp2 + 47;
      
      string tmpWord3(2, '0');
      tmpWord3[0] = (char)tmp1 + 65;
      tmpWord3[1] = (char)tmp2 + 48;
      
      string tmpWord4(2, '0');
      tmpWord4[0] = (char)tmp1 + 63;
      tmpWord4[1] = (char)tmp2 + 48;
      arr2.insert(arr2.begin(), tmpWord1);
      
      arr2.insert(arr2.begin(), tmpWord3);

      arr2.insert(arr2.begin(), tmpWord2);
      
      arr2.insert(arr2.begin(), tmpWord4);
    }
  }

  else if (!arr2.empty())
  {
    string t2 = arr2[0];
    strcpy(aiInput, t2.c_str());
    arr2.erase(arr2.begin());
    int tmp1 = t2[0] - 64;
    int tmp2 = t2[1] - 48;

    if (map[tmp1][t2[1] - 48] == 2 || map[tmp1][t2[1] - 48] == 3 || map[tmp1][t2[1] - 48] == 4 || map[tmp1][t2[1] - 48] == 5 || map[tmp1][t2[1] - 48] == 6)
    {
      string tmpWord1(2, '0');
      tmpWord1[0] = (char)tmp1 + 64;
      tmpWord1[1] = (char)tmp2 + 47;
      arr2.insert(arr2.begin(), tmpWord1);
      string tmpWord2(2, '0');
      tmpWord2[0] = (char)tmp1 + 64;
      tmpWord2[1] = (char)tmp2 + 49;
      arr2.insert(arr2.begin(), tmpWord2);
      string tmpWord3(2, '0');
      tmpWord3[0] = (char)tmp1 + 63;
      tmpWord3[1] = (char)tmp2 + 48;
      arr2.insert(arr2.begin(), tmpWord3);
      string tmpWord4(2, '0');
      tmpWord4[0] = (char)tmp1 + 65;
      tmpWord4[1] = (char)tmp2 + 48;
      arr2.insert(arr2.begin(), tmpWord4);
    }
  }

  return aiInput;
}

void player::inputPlayer(WINDOW *dw, WINDOW *aw, WINDOW *sw, WINDOW *iw, char *(&input), int **(&t), int &turn)
{
  // wgetnstr(IW, in, 2);
  in = ai(t);
  usleep(10000);

  if (toupper(in[0]) == 'A' || toupper(in[0]) == 'B' || toupper(in[0]) == 'C' || toupper(in[0]) == 'D' || toupper(in[0]) == 'E' || toupper(in[0]) == 'F' || toupper(in[0]) == 'G' || toupper(in[0]) == 'H')
  {
    if (in[1] == '1' || in[1] == '2' || in[1] == '3' || in[1] == '4' || in[1] == '5' || in[1] == '6' || in[1] == '7' || in[1] == '8')
    {

      mvwprintw(sw, 7, 14, in);

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
        turn++;
      }

      sprintf(turnStr, "%d", getTurn());
      mvwprintw(sw, 2, 8, turnStr);
      wrefresh(sw);
      wmove(iw, 2, 9);
      mvwprintw(iw, 2, 9, "  ");
      wrefresh(iw);
      input = in;
    }
    else
    {
      mvwprintw(iw, 2, 9, "  ");
      wrefresh(iw);
      wmove(iw, 2, 9);
    }
  }
  else
  {
    mvwprintw(iw, 2, 9, "  ");
    wrefresh(iw);
    wmove(iw, 2, 9);
  }
}