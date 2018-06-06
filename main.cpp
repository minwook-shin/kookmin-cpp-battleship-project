#include "main.h"

using namespace std;
int main()
{
  int t = 0;
  gameManager gm;
  windowManager wm;
  player a;
  gm.createMap();
  refresh();
  defendWindow dw;
  attackWindow aw;
  statusWindow sw;
  inputWindow iw;
  gm.drawMap(gm.t, aw.getWin(), iw.getWin());
  for(;;)
  {
    gm.updateDefendmap(dw.getWin(), iw.getWin());
    gm.updateAttackmap(aw.getWin(), gm.in, iw.getWin());
    gm.shipStatus(sw.getWin(), t);
    a.inputPlayer(dw.getWin(), aw.getWin(), sw.getWin(), iw.getWin(), gm.in, gm.t,t);
  }
  getch();
  return 0;
}