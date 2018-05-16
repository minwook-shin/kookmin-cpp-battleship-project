#include <ncurses.h>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    WINDOW *defendBox;
    WINDOW *defendWin;
    WINDOW *attackBox;
    WINDOW *attackWin;
    WINDOW *statusWIn;
    WINDOW *inputWIn;
    char *in = new char[3];
    int turn = 0;
    bool isEnd = false;

    char *turnStr = new char[2];

    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLUE);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);

    border('*', '*', '*', '*', '*', '*', '*', '*');
    mvprintw(1, 1, "KOOKMIN .UNIV CS C++ Programming BattleShip / 20171640 minwook-shin");
    refresh();
    getch();

    defendBox = newwin(20, 20, 3, 3);
    box(defendBox, 0, 0);
    wattron(defendBox, COLOR_PAIR(1));
    mvwprintw(defendBox, 1, 1, "DEFENDER");
    wrefresh(defendBox);
    defendWin = newwin(17, 18, 5, 4);
    wbkgd(defendWin, COLOR_PAIR(2));
    mvwprintw(defendWin, 1, 1, "A new window");
    wrefresh(defendWin);

    attackBox = newwin(20, 20, 25, 3);
    box(attackBox, 0, 0);
    wattron(attackBox, COLOR_PAIR(1));
    mvwprintw(attackBox, 1, 1, "ATTACKER");
    wrefresh(attackBox);
    attackWin = newwin(17, 18, 27, 4);
    wbkgd(attackWin, COLOR_PAIR(2));
    mvwprintw(attackWin, 1, 1, "A new window");
    wrefresh(attackWin);

    statusWIn = newwin(10, 50, 10, 30);
    box(statusWIn, 0, 0);
    wattron(statusWIn, COLOR_PAIR(3));
    mvwprintw(statusWIn, 1, 1, "<STATUS>");
    mvwprintw(statusWIn, 2, 1, "TURN : 0");
    mvwprintw(statusWIn, 3, 1, "AIRCRAFT : AAAAA");
    mvwprintw(statusWIn, 4, 1, "BATTLESHIP : BBBB");
    mvwprintw(statusWIn, 5, 1, "CRUISER : CCC");
    mvwprintw(statusWIn, 6, 1, "DESTROYER : DD DD");
    mvwprintw(statusWIn, 8, 1, "INPUT TEST : ");
    wrefresh(statusWIn);

    inputWIn = newwin(10, 50, 25, 30);
    box(inputWIn, 0, 0);
    wattron(inputWIn, COLOR_PAIR(4));
    mvwprintw(inputWIn, 1, 1, "input position...(ex A3) ");
    mvwprintw(inputWIn, 2, 1, "input : ");
    wrefresh(inputWIn);

    while (isEnd == false)
    {
        wgetnstr(inputWIn, in, 2);

        if (in[0] == 'A' || in[0] == 'B' || in[0] == 'C' || in[0] == 'D' || in[0] == 'E' || in[0] == 'F' || in[0] == 'G' || in[0] == 'H')
        {
            if (in[1] == '1' || in[1] == '2' || in[1] == '3' || in[1] == '4' || in[1] == '5' || in[1] == '6' || in[1] == '7' || in[1] == '8')
            {
                mvwprintw(statusWIn, 8, 14, in);
                turn += 1;
                sprintf(turnStr, "%d", turn);
                mvwprintw(statusWIn, 2, 8, turnStr);
                wrefresh(statusWIn);
                wmove(inputWIn, 2, 9);
            }
            else
            {
                wmove(inputWIn, 2, 9);
            }
        }
        else
        {
            wmove(inputWIn, 2, 9);
        }
    }

    getch();
    getch();
    delwin(defendBox);
    endwin();
    return 0;
}
