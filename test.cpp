
#include <ncurses.h>

using namespace std;

int main()
{
    initscr(); 
    printw("Hello World !!!"); 
    refresh();                 
    getch();                  
    endwin();
    return 0;
}
