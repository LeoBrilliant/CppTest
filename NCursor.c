#include <ncurses.h>

// int main()
int test()
{
    initscr();
    printw("Hello World !!!");
    refresh();
    getch();
    endwin();

    return 0;
}
