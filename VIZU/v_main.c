#include <curses.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	initscr();
	noecho();
	keypad(stdscr, true);
	curs_set(false);
	// timeout(0);

	// printw("Hello world!\n");  // Отображение приветствия в буфер
    write(1, "\e[8;60;200;t", 14);                

	WINDOW * win1 = newwin(60, 150, 0, 0);
	WINDOW * win2 = newwin(60, 50, 0, 150);
	refresh();
	box(win1, 0, 0);
	box(win2, 0, 0);
	mvwprintw(win1, 1, 2, "code side");
	mvwprintw(win2, 1, 2, "legend side");

	wrefresh(win1);
	wrefresh(win2);
	while(1)
		;
    // getch();
	endwin();
	return 0;
}

// gcc -lncurses v_main.c