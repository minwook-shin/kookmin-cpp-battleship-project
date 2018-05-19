#include "main.h"

using namespace std;
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
    gm.shipStatus(sw.getWin(), gm.getTurn());
    a.inputPlayer(dw.getWin(), aw.getWin(), sw.getWin(), iw.getWin(), gm.in, gm.t);
  }
  getch();
  return 0;
}
