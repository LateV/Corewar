/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:50:50 by rkhilenk          #+#    #+#             */
/*   Updated: 2018/09/20 20:46:41 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void itit_color_pairs(void)
{
		// standart players color
		init_pair(1, COLOR_GREEN, COLOR_BLACK);
		init_pair(2, COLOR_BLUE, COLOR_BLACK);
		init_pair(3, COLOR_RED, COLOR_BLACK);
		init_pair(4, COLOR_CYAN, COLOR_BLACK);
		// carret players color
		init_pair(5, COLOR_BLACK, COLOR_GREEN);
		init_pair(6, COLOR_BLACK, COLOR_BLUE);
		init_pair(7, COLOR_BLACK, COLOR_RED);
		init_pair(8, COLOR_BLACK, COLOR_CYAN);
		// player copy color
		init_pair(9, 41, COLOR_BLACK);
		init_pair(10, 27, COLOR_BLACK);
		init_pair(11, 160, COLOR_BLACK);
		init_pair(12, 14, COLOR_BLACK);
		// life scream
		init_pair(13, COLOR_WHITE, COLOR_GREEN);
		init_pair(14, COLOR_WHITE, COLOR_BLUE);
		init_pair(15, COLOR_WHITE, COLOR_RED);
		init_pair(16, COLOR_WHITE, COLOR_CYAN);
		// no players colors
		init_pair(22, 243, COLOR_BLACK);
		init_pair(23, COLOR_BLACK, 243);
}

void initital_draw(t_cor *cor)
{
	if(cor->visu == 1)
	{
		box(cor->vizu->win1, 0, 0);
		box(cor->vizu->win2, 0, 0);
		if (cor->pause == 1)
			mvwprintw(cor->vizu->win2, 2, 2, "%-20s", "** PAUSED **");
		else
			mvwprintw(cor->vizu->win2, 2, 2, "%-20s", "** PLAY **");
		mvwprintw(cor->vizu->win2, 4, 2, "Cycles/second limit : %-9d", 1000000 / cor->vizu->speed);
		mvwprintw(cor->vizu->win2, 7, 2, "Cycle : %-20d", (cor->cycles) - 1);
		mvwprintw(cor->vizu->win2, 9, 2, "Processes : %2d", cor->alive_cur);
		
		
	}
}

void draw_palyer_info(t_cor *cor, t_process *proc, int k)
{
	if(cor->visu == 1)
	{
		mvwprintw(cor->vizu->win2, 11 + (k * 4), 2, "Player %d : ", proc->player->num);
		wattron(cor->vizu->win2, COLOR_PAIR(k+1));
		mvwprintw(cor->vizu->win2, 11 + (k * 4), 14, "%.40s", proc->player->prog_name);
		wattroff(cor->vizu->win2, COLOR_PAIR(k+1));
		mvwprintw(cor->vizu->win2, 12 + (k * 4), 4, "Last live : %20d", 0);
		mvwprintw(cor->vizu->win2, 13 + (k * 4), 4, "Lives in current period : %6d", 0);
		cor->vizu->end_of_prs++;
	}
}

void draw_info(t_cor *cor)
{
	if(cor->visu == 1)
	{
		int k;

		k = cor->vizu->end_of_prs;
		mvwprintw(cor->vizu->win2, 15 + ((k-1) * 4), 2, "Live breakdown for current period :");
		mvwprintw(cor->vizu->win2, 16 + ((k-1) * 4), 2, "[--------------------------------------------------]");
		mvwprintw(cor->vizu->win2, 18 + ((k-1) * 4), 2, "Live breakdown for last period :");
		mvwprintw(cor->vizu->win2, 19 + ((k-1) * 4), 2, "[--------------------------------------------------]");
		// mvwprintw(cor->vizu->win2, 21 + ((k-1) * 4), 2, "CYCLE_TO_DIE : %d", cor->curr_cycle_t_d);
		mvwprintw(cor->vizu->win2, 21 + ((cor->vizu->end_of_prs-1) * 4), 2, "CYCLE_TO_DIE : %d", cor->curr_cycle_t_d);
		mvwprintw(cor->vizu->win2, 23 + ((k-1) * 4), 2, "CYCLE_DELTA : %d", CYCLE_DELTA);
		mvwprintw(cor->vizu->win2, 25 + ((k-1) * 4), 2, "NBR_LIVE : %d", NBR_LIVE);
		mvwprintw(cor->vizu->win2, 27 + ((k-1) * 4), 2, "MAX_CHECKS : %d", MAX_CHECKS);
	}
}

void put_com(t_cor *cor, int pos, unsigned char comm, int color)
{
	if(cor->visu == 1)
	{
		color = (color * (-1))-1;
		wattron(cor->vizu->win1, COLOR_PAIR(color+1));

		mvwprintw(cor->vizu->win1, (pos / 64) + 1, (pos % 64) * 3 + 2, "%02x", comm);

		wattroff(cor->vizu->win1, COLOR_PAIR(color+1));
	}
}

void put_car(t_cor *cor, int pos, unsigned char comm, int color)
{
	if(cor->visu == 1)
	{
		color = (color * (-1))-1;
		wattron(cor->vizu->win1, COLOR_PAIR(color+5));
		mvwprintw(cor->vizu->win1, (pos / 64) + 1, (pos % 64) * 3 + 2, "%02x", comm);
		wattroff(cor->vizu->win1, COLOR_PAIR(color+5));
	}
}

void init_window(t_cor *cor)
{
	t_vizu	*vizu;

	if(cor->visu == 1)
	{
		vizu = malloc(sizeof(t_vizu));
		cor->vizu = vizu;
		cor->vizu->end_of_prs = 0;
		cor->vizu->speed = 20000;
		initscr();
		start_color();
		noecho();
		keypad(stdscr, true);
		curs_set(false);
		timeout(0);
		write(1, "\e[8;66;252;t", 14);
		cor->vizu->win1 = newwin(66, 195, 0, 0);
		cor->vizu->win2 = newwin(66, 56, 0, 196);
		itit_color_pairs();

		init_map(cor);
		initital_draw(cor);
	}

	// mvwprintw(cor->vizu->win2, 9, 2, "qweqweqwe", 1);
	// wrefresh(cor->vizu->win2);

	// while (1)
	// {
	// 	getch();

	// 	wrefresh(cor->vizu->win1);
	// 	wrefresh(cor->vizu->win2);
	// }
}
// int main(void)
// {
// 	initscr();
// 	start_color();
// 	noecho();
// 	keypad(stdscr, true);
// 	curs_set(false);
// 	char arr[MEM_SIZE];

// 	timeout(0);
// 	arr[0] = 90;
// 	arr[1] = 123;
// 	arr[2] = 0;

// 	init_pair(1, COLOR_RED, COLOR_BLACK);
//     init_pair(2, COLOR_BLACK, COLOR_RED);
	
// 	// printf("%s\n", ft_itoa_base(int(arr[0]), 16));
// 	// printw("Hello world!\n");  // Отображение приветствия в буфер
//     write(1, "\e[8;60;200;t", 14);                

// 	WINDOW * win1 = newwin(60, 150, 0, 0);
// 	WINDOW * win2 = newwin(60, 50, 0, 150);
	
// 	box(win1, 0, 0);
// 	box(win2, 0, 0);

// 	wattron(win1, COLOR_PAIR(2));
// 	mvwprintw(win1, 1, 2, "%02x", arr[0]);
// 	wattroff(win1, COLOR_PAIR(2));


// 	wattron(win1, COLOR_PAIR(1));
// 	mvwprintw(win1, 1, 5, "%02x", arr[1]);
// 	mvwprintw(win1, 1, 8, "%02x", arr[2]);
// 	wattroff(win1, COLOR_PAIR(1));


// 	wattron(win2, COLOR_PAIR(1));
// 	mvwprintw(win2, 1, 2, "legend side");
// 	wattroff(win2, COLOR_PAIR(1));


// 	while (1)
// 	{
		// getch();

// 		wrefresh(win1);
// 		wrefresh(win2);
// 	}
	


// 	endwin();
// 	return 0;
// }


// gcc -lncurses v_main.c ../libft/libft.a
