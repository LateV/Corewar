#include <curses.h>
#include <unistd.h>
#include "../VM/vm.h"

int main(int argc, char const *argv[])
{
	initscr();
	noecho();
	keypad(stdscr, true);
	curs_set(false);
	char arr[MEM_SIZE];

	// timeout(0);
	arr[0] = 90;
	arr[1] = 123;
	arr[2] = 44;
	
	// printf("%s\n", ft_itoa_base(int(arr[0]), 16));
	// printw("Hello world!\n");  // Отображение приветствия в буфер
    write(1, "\e[8;60;200;t", 14);                

	WINDOW * win1 = newwin(60, 150, 0, 0);
	WINDOW * win2 = newwin(60, 50, 0, 150);
	refresh();
	box(win1, 0, 0);
	box(win2, 0, 0);
	mvwprintw(win1, 1, 2, ft_itoa_base((int)arr[0], 16));
	mvwprintw(win1, 1, 5, ft_itoa_base((int)arr[1], 16));
	mvwprintw(win1, 1, 8, ft_itoa_base((int)arr[2], 16));
	mvwprintw(win2, 1, 2, "legend side");

	wrefresh(win1);
	wrefresh(win2);
	while(1)
		;
    // getch();
	endwin();
	return 0;
}

// gcc -lncurses v_main.c ../libft/libft.a