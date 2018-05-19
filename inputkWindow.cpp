#include "inputkWindow.h"

inputkWindow::inputkWindow(/* args */)
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
inputkWindow::~inputkWindow()
{
    delwin(inputWIn);
}
WINDOW *inputkWindow::getWin()
{
    return inputWIn;
}
