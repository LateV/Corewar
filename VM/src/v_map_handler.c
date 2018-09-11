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
	
	while (++i < 4096)
	{
		
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
		else if (cor->vizu->map[i].type == 1)
		{
			wattron(cor->vizu->win1, COLOR_PAIR(cor->vizu->map[i].player + 4));
			mvwprintw(cor->vizu->win1, (i / 64) + 1, (i % 64) * 3 + 2, "%02x", cor->vizu->map[i].comm);
			wattroff(cor->vizu->win1, COLOR_PAIR(cor->vizu->map[i].player + 4));
		}
		else
		{
			wattron(cor->vizu->win1, COLOR_PAIR(cor->vizu->map[i].player));
			mvwprintw(cor->vizu->win1, (i / 64) + 1, (i % 64) * 3 + 2, "%02x", cor->vizu->map[i].comm);
			wattroff(cor->vizu->win1, COLOR_PAIR(cor->vizu->map[i].player));
		}
	}
	
}

void refresh_info(t_cor *cor)
{
	mvwprintw(cor->vizu->win2, 7, 10, "%d", cor->cycles);
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

void refresh_vizu(t_cor *cor)
{
	initital_draw(cor);

	refresh_info(cor);
	refresh_map(cor);
	refresh_player(cor);

	wrefresh(cor->vizu->win1);
	wrefresh(cor->vizu->win2);
	usleep(10000);
}

void					init_map(t_cor *cor)
{
	int i;

	cor->vizu->map = (t_map *)malloc(sizeof(t_map) * 4096);
	i = -1;
	while (i++ < 4096)
	{
		cor->vizu->map[i].comm = 0;
		cor->vizu->map[i].type = 0;
		cor->vizu->map[i].player = -1;
		cor->vizu->map[i].life_time = -1;

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

