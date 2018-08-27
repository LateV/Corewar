#include <curses.h>
#include <unistd.h>
#include "../VM/vm.h"

int main(int argc, char const *argv[])
{
	initscr();
	start_color();
	noecho();
	keypad(stdscr, true);
	curs_set(false);
	char arr[MEM_SIZE];

	// timeout(0);
	arr[0] = 90;
	arr[1] = 123;
	arr[2] = 0;

	init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_RED);
	
	// printf("%s\n", ft_itoa_base(int(arr[0]), 16));
	// printw("Hello world!\n");  // Отображение приветствия в буфер
    write(1, "\e[8;60;200;t", 14);                

	WINDOW * win1 = newwin(60, 150, 0, 0);
	WINDOW * win2 = newwin(60, 50, 0, 150);
	
	box(win1, 0, 0);
	box(win2, 0, 0);

	wattron(win1, COLOR_PAIR(2));
	mvwprintw(win1, 1, 2, "%02x", arr[0]);
	wattroff(win1, COLOR_PAIR(2));


	wattron(win1, COLOR_PAIR(1));
	mvwprintw(win1, 1, 5, "%02x", arr[1]);
	mvwprintw(win1, 1, 8, "%02x", arr[2]);
	wattroff(win1, COLOR_PAIR(1));
	mvwprintw(win2, 1, 2, "legend side");

	

	
	while(1)
		wrefresh(win1);
		wrefresh(win2);
		getch();
		
		;

    // getch();
	endwin();
	return 0;
}

// gcc -lncurses v_main.c ../libft/libft.a