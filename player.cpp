#include <unistd.h>
#include "player.h"

using namespace std;

player::player(/* args */):aiInput(new char[2])
{
  srand(time(0));
}
player::~player() {}

char* player::ai()
{
  randomInputX = (1 + rand() % 8);
  randomInputY = (1 + rand() % 8);
  if(randomInputX == 1)
  {
    aiInput[0] = 'A';
  }
  if(randomInputX == 2)
  {
    aiInput[0] = 'B';
  }
  if(randomInputX == 3)
  {
    aiInput[0] = 'C';
  }
  if(randomInputX == 4)
  {
    aiInput[0] = 'D';
  }
  if(randomInputX == 5)
  {
    aiInput[0] = 'E';
  }
  if(randomInputX == 6)
  {
    aiInput[0] = 'F';
  }
  if(randomInputX == 7)
  {
    aiInput[0] = 'G';
  }
  if(randomInputX == 8)
  {
    aiInput[0] = 'H';
  }

  if (randomInputY == 1) {
    aiInput[1] = '1';
  }
  if (randomInputY == 2) {
    aiInput[1] = '2';
  }
  if (randomInputY == 3) {
    aiInput[1] = '3';
  }
  if (randomInputY == 4) {
    aiInput[1] = '4';
  }
  if (randomInputY == 5) {
    aiInput[1] = '5';
  }
  if (randomInputY == 6) {
    aiInput[1] = '6';
  }
  if (randomInputY == 7) {
    aiInput[1] = '7';
  }
  if (randomInputY == 8) {
    aiInput[1] = '8';
  }
  
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


