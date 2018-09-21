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

static void	itit_color_pairs(void)
{
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_GREEN);
	init_pair(6, COLOR_BLACK, COLOR_BLUE);
	init_pair(7, COLOR_BLACK, COLOR_RED);
	init_pair(8, COLOR_BLACK, COLOR_CYAN);
	init_pair(9, 41, COLOR_BLACK);
	init_pair(10, 27, COLOR_BLACK);
	init_pair(11, 160, COLOR_BLACK);
	init_pair(12, 14, COLOR_BLACK);
	init_pair(13, COLOR_WHITE, COLOR_GREEN);
	init_pair(14, COLOR_WHITE, COLOR_BLUE);
	init_pair(15, COLOR_WHITE, COLOR_RED);
	init_pair(16, COLOR_WHITE, COLOR_CYAN);
	init_pair(22, 243, COLOR_BLACK);
	init_pair(23, COLOR_BLACK, 243);
}

void		initital_draw(t_cor *cor)
{
	if (cor->visu == 1)
	{
		box(cor->vizu->win1, 0, 0);
		box(cor->vizu->win2, 0, 0);
		if (cor->pause == 1)
			mvwprintw(cor->vizu->win2, 2, 2, "%-20s", "** PAUSED **");
		else
			mvwprintw(cor->vizu->win2, 2, 2, "%-20s", "** PLAY **");
		mvwprintw(cor->vizu->win2, 4, 2, "Cycles/second limit : %-9d",
		1000000 / cor->vizu->speed);
		mvwprintw(cor->vizu->win2, 7, 2, "Cycle : %-20d", (cor->cycles) - 1);
		mvwprintw(cor->vizu->win2, 9, 2, "Processes : %-20d",
		(cor->proc_num) - 1);
	}
}

void		draw_palyer_info(t_cor *cor, t_process *proc, int k)
{
	if (cor->visu == 1)
	{
		mvwprintw(cor->vizu->win2, 11 + (k * 4), 2, "Player %d : ",
		proc->player->num);
		wattron(cor->vizu->win2, COLOR_PAIR(k + 1));
		mvwprintw(cor->vizu->win2, 11 + (k * 4), 14, "%.40s",
		proc->player->prog_name);
		wattroff(cor->vizu->win2, COLOR_PAIR(k + 1));
		mvwprintw(cor->vizu->win2, 12 + (k * 4), 4, "Last live : %20d", 0);
		mvwprintw(cor->vizu->win2, 13 + (k * 4), 4,
		"Lives in current period : %6d", 0);
		cor->vizu->end_of_prs++;
	}
}

void		draw_info(t_cor *cor)
{
	int k;

	if (cor->visu == 1)
	{
		k = cor->vizu->end_of_prs;
		mvwprintw(cor->vizu->win2, 15 + ((k - 1) * 4), 2,
		"Live breakdown for current period :");
		mvwprintw(cor->vizu->win2, 16 + ((k - 1) * 4), 2,
		"[--------------------------------------------------]");
		mvwprintw(cor->vizu->win2, 18 + ((k - 1) * 4), 2,
		"Live breakdown for last period :");
		mvwprintw(cor->vizu->win2, 19 + ((k - 1) * 4), 2,
		"[--------------------------------------------------]");
		mvwprintw(cor->vizu->win2, 21 + ((cor->vizu->end_of_prs - 1) * 4), 2,
		"CYCLE_TO_DIE : %d", cor->curr_cycle_t_d);
		mvwprintw(cor->vizu->win2, 23 + ((k - 1) * 4), 2,
		"CYCLE_DELTA : %d", CYCLE_DELTA);
		mvwprintw(cor->vizu->win2, 25 + ((k - 1) * 4), 2,
		"NBR_LIVE : %d", NBR_LIVE);
		mvwprintw(cor->vizu->win2, 27 + ((k - 1) * 4), 2,
		"MAX_CHECKS : %d", MAX_CHECKS);
	}
}

void		init_window(t_cor *cor)
{
	t_vizu	*vizu;

	if (cor->visu == 1)
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
}
