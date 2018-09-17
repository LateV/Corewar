/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_map_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:50:31 by rkhilenk          #+#    #+#             */
/*   Updated: 2018/09/10 15:50:33 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void refresh_map(t_cor *cor)
{
	int i;
	

	i = -1;
	cor->stealth = 0;

	while (++i < 4096)
	{
		if (cor->vizu->map[i].life_time > 0 && cor->pause == 0)
			cor->vizu->map[i].life_time--;
		if (cor->vizu->map[i].life_scream > 0 && cor->pause == 0)
			cor->vizu->map[i].life_scream--;

		if (cor->vizu->map[i].player == -1 && cor->vizu->map[i].type == 1)
		{
			wattron(cor->vizu->win1, COLOR_PAIR(23));
			mvwprintw(cor->vizu->win1, (i / 64) + 1, (i % 64) * 3 + 2, "%02x", cor->vizu->map[i].comm);
			wattroff(cor->vizu->win1, COLOR_PAIR(23));
		}
		else if (cor->vizu->map[i].player == -1)
		{
			wattron(cor->vizu->win1, COLOR_PAIR(22));
			mvwprintw(cor->vizu->win1, (i / 64) + 1, (i % 64) * 3 + 2, "%02x", cor->vizu->map[i].comm);
			wattroff(cor->vizu->win1, COLOR_PAIR(22));
		}
		else if (cor->vizu->map[i].life_scream > 0)
		{
			wattron(cor->vizu->win1, COLOR_PAIR(cor->vizu->map[i].player + 12));
			mvwprintw(cor->vizu->win1, (i / 64) + 1, (i % 64) * 3 + 2, "%02x", cor->vizu->map[i].comm);
			wattroff(cor->vizu->win1, COLOR_PAIR(cor->vizu->map[i].player + 12));
		}
		else if (cor->vizu->map[i].type == 1)
		{
			wattron(cor->vizu->win1, COLOR_PAIR(cor->vizu->map[i].player + 4));
			mvwprintw(cor->vizu->win1, (i / 64) + 1, (i % 64) * 3 + 2, "%02x", cor->vizu->map[i].comm);
			wattroff(cor->vizu->win1, COLOR_PAIR(cor->vizu->map[i].player + 4));
		}
		else if (cor->vizu->map[i].life_time > 0)
		{
			wattron(cor->vizu->win1, COLOR_PAIR(cor->vizu->map[i].player + 8));
			mvwprintw(cor->vizu->win1, (i / 64) + 1, (i % 64) * 3 + 2, "%02x", cor->vizu->map[i].comm);
			wattroff(cor->vizu->win1, COLOR_PAIR(cor->vizu->map[i].player + 8));
		}
		else
		{
			wattron(cor->vizu->win1, COLOR_PAIR(cor->vizu->map[i].player));
			mvwprintw(cor->vizu->win1, (i / 64) + 1, (i % 64) * 3 + 2, "%02x", cor->vizu->map[i].comm);
			wattroff(cor->vizu->win1, COLOR_PAIR(cor->vizu->map[i].player));
		}

		if (cor->stealth == 1)
			cor->vizu->map[i].comm = 255;
	}
	
}

void v_speed_test(t_cor *cor, char t)
{

	// speed 0 = 500 000 2
	// speed 1 = 100 000 10
	// speed 2 = 50 000  20
	// speed 3 = 20 000  50
	// speed 4 = 10 000  100
	// speed 5 = 1 000   1000

	if (t == '=' && cor->vizu->speed == 500000)
		cor->vizu->speed = 100000;
	else if (t == '=' && cor->vizu->speed == 100000)
		cor->vizu->speed = 50000;
	else if (t == '=' && cor->vizu->speed == 50000)
		cor->vizu->speed = 20000;
	else if (t == '=' && cor->vizu->speed == 20000)
		cor->vizu->speed = 10000;
	else if (t == '=' && cor->vizu->speed == 10000)
		cor->vizu->speed = 1000;

	if (t == '-' && cor->vizu->speed == 1000)
		cor->vizu->speed = 10000;
	else if (t == '-' && cor->vizu->speed == 10000)
		cor->vizu->speed = 20000;
	else if (t == '-' && cor->vizu->speed == 20000)
		cor->vizu->speed = 50000;
	else if (t == '-' && cor->vizu->speed == 50000)
		cor->vizu->speed = 100000;
	else if (t == '-' && cor->vizu->speed == 100000)
		cor->vizu->speed = 500000;

	if (cor->vizu->speed == 100000)
		mvwprintw(cor->vizu->win2, 30 + ((cor->vizu->end_of_prs-1) * 4), 2, "speed : >      ", cor->vizu->speed);
	else if (cor->vizu->speed == 50000)
		mvwprintw(cor->vizu->win2, 30 + ((cor->vizu->end_of_prs-1) * 4), 2, "speed : >>     ", cor->vizu->speed);
	else if (cor->vizu->speed == 20000)
		mvwprintw(cor->vizu->win2, 30 + ((cor->vizu->end_of_prs-1) * 4), 2, "speed : >>>    ", cor->vizu->speed);
	else if (cor->vizu->speed == 10000)
		mvwprintw(cor->vizu->win2, 30 + ((cor->vizu->end_of_prs-1) * 4), 2, "speed : >>>>   ", cor->vizu->speed);
	else if (cor->vizu->speed == 1000)
		mvwprintw(cor->vizu->win2, 30 + ((cor->vizu->end_of_prs-1) * 4), 2, "speed : max    ", cor->vizu->speed);
	else if (cor->vizu->speed == 500000)
		mvwprintw(cor->vizu->win2, 30 + ((cor->vizu->end_of_prs-1) * 4), 2, "speed : min    ", cor->vizu->speed);
}

void refresh_info(t_cor *cor)
{
	// mvwprintw(cor->vizu->win2, 7, 10, "%d", cor->cycles);
	mvwprintw(cor->vizu->win2, 21 + ((cor->vizu->end_of_prs-1) * 4), 2, "CYCLE_TO_DIE : %d", cor->curr_cycle_t_d);
}

void refresh_player(t_cor *cor)
{
	int i;

	i = 0;
	while(i < cor->p_num)
	{
		mvwprintw(cor->vizu->win2, 12 + (i * 4), 16, "%20d", cor->player[i].last_live);
		mvwprintw(cor->vizu->win2, 13 + (i * 4), 30, "%6d", cor->player[i].live_summ);
		i++;
	}
}

void off_rounder(t_cor *cor, int res_summ)
{
	int	max_score = 0;
	int max_player = 0;
	int i;

	i = -1;
	while (++i < cor->p_num)
	{
		if (cor->vizu->brakedown[i] > max_score)
		{
			max_score = cor->vizu->brakedown[i];
			max_player = i;
		}
	}
	cor->vizu->brakedown[max_player] += (50 - res_summ);
}

void break_printer(t_cor *cor)
{
	int carret = 0;
	int l_carret = 0;
	int i = -1;

	mvwprintw(cor->vizu->win2, 16 + ((cor->p_num-1) * 4), 2, "[--------------------------------------------------]");
	mvwprintw(cor->vizu->win2, 19 + ((cor->p_num-1) * 4), 2, "[--------------------------------------------------]");

	while (++i < cor->p_num)
	{
		if (cor->vizu->brakedown[i] > 0)
		{
			wattron(cor->vizu->win2, COLOR_PAIR(i + 1));
			mvwprintw(cor->vizu->win2, 16 + ((cor->p_num-1) * 4), 3 + carret, "%.*s", cor->vizu->brakedown[i] , "--------------------------------------------------");
			mvwprintw(cor->vizu->win2, 19 + ((cor->p_num-1) * 4), 3 + l_carret, "%.*s", cor->vizu->last_brakedown[i] , "--------------------------------------------------");
			wattroff(cor->vizu->win2, COLOR_PAIR(i + 1));
			carret += cor->vizu->brakedown[i];
			l_carret += cor->vizu->last_brakedown[i];
		}
	}

}


void breakdown(t_cor *cor)
{
	int i = -1;
	double summ = 0;
	int res_summ = 0;
	while (++i < cor->p_num)
		summ += cor->player[i].live_summ;
	i = -1;
	while (++i < cor->p_num)
	{
		if (cor->player[i].live_summ != 0)
		{
			cor->vizu->last_brakedown[i] = cor->vizu->brakedown[i];
			cor->vizu->brakedown[i] = (50 / summ) * cor->player[i].live_summ;
			res_summ += cor->vizu->brakedown[i];
		}
		else
			cor->vizu->brakedown[i] = 0;
	}
	if (res_summ != 0 && res_summ != 50)
		off_rounder(cor, res_summ);
	break_printer(cor);

}

void refresh_vizu(t_cor *cor)
{
	initital_draw(cor);
	
	refresh_info(cor);
	refresh_map(cor);
	refresh_player(cor);

	breakdown(cor);

	wrefresh(cor->vizu->win1);
	wrefresh(cor->vizu->win2);

	if (cor->pause == 0)
		usleep(cor->vizu->speed);
	else
		usleep(1000);

}

void					init_map(t_cor *cor)
{
	int i;

	cor->vizu->map = (t_map *)malloc(sizeof(t_map) * 4096);
	i = -1;
	while (++i < 4096)
	{
		cor->vizu->map[i].comm = 0;
		cor->vizu->map[i].type = 0;
		cor->vizu->map[i].player = -1;
		cor->vizu->map[i].life_time = 0;
		cor->vizu->map[i].life_scream = 0;
	}
	i = -1;
	while (++i < 4)
	{
		cor->vizu->brakedown[i] = 0;
		cor->vizu->last_brakedown[i] = 0;
	}
}


// static void		map_str_to_struct(t_storage **s, char *str)
// {
// 	char	**array;
// 	int		i;
// 	int		j;
// 	int		count;

// 	i = 0;
// 	count = 0;
// 	array = ft_strsplit(str, ' ');
// 	(*s)->map = (t_dot **)malloc(sizeof(t_dot) * ((*s)->height));
// 	while (i < (*s)->height)
// 	{
// 		j = 0;
// 		(*s)->map[i] = (t_dot *)malloc(sizeof(t_dot) * ((*s)->width));
// 		while (j < (*s)->width)
// 		{
// 			(*s)->map[i][j].x = j;
// 			(*s)->map[i][j].y = i;
// 			(*s)->map[i][j].z = ft_atoi(array[count]);
// 			(*s)->map[i][j].color = get_color(array[count]);
// 			count++;
// 			j++;
// 		}
// 		i++;
// 	}
// }

