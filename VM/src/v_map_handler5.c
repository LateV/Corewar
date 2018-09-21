/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_map_handler5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 16:17:50 by rkhilenk          #+#    #+#             */
/*   Updated: 2018/09/21 16:17:51 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	refresh_map3(t_cor *cor, int i)
{
	if (cor->vizu->map[i].life_time > 0)
	{
		wattron(cor->vizu->win1, COLOR_PAIR(cor->vizu->map[i].player + 8));
		mvwprintw(cor->vizu->win1, (i / 64) + 1, (i % 64) * 3 + 2,
		"%02x", cor->vizu->map[i].comm);
		wattroff(cor->vizu->win1, COLOR_PAIR(cor->vizu->map[i].player + 8));
	}
	else
	{
		wattron(cor->vizu->win1, COLOR_PAIR(cor->vizu->map[i].player));
		mvwprintw(cor->vizu->win1, (i / 64) + 1, (i % 64) * 3 + 2,
		"%02x", cor->vizu->map[i].comm);
		wattroff(cor->vizu->win1, COLOR_PAIR(cor->vizu->map[i].player));
	}
}

void		refresh_map2(t_cor *cor, int i)
{
	if (cor->vizu->map[i].life_scream > 0)
	{
		wattron(cor->vizu->win1, COLOR_PAIR(cor->vizu->map[i].car_player + 12));
		mvwprintw(cor->vizu->win1, (i / 64) + 1, (i % 64) * 3 + 2,
		"%02x", cor->vizu->map[i].comm);
		wattroff(cor->vizu->win1,
		COLOR_PAIR(cor->vizu->map[i].car_player + 12));
	}
	else if (cor->vizu->map[i].type == 1)
	{
		wattron(cor->vizu->win1, COLOR_PAIR(cor->vizu->map[i].player + 4));
		mvwprintw(cor->vizu->win1, (i / 64) + 1, (i % 64) * 3 + 2,
		"%02x", cor->vizu->map[i].comm);
		wattroff(cor->vizu->win1, COLOR_PAIR(cor->vizu->map[i].player + 4));
	}
	else
		refresh_map3(cor, i);
}

void		refresh_map(t_cor *cor)
{
	int i;

	i = -1;
	cor->stealth = 0;
	while (++i < 4096)
	{
		if (cor->vizu->map[i].player == -1 && cor->vizu->map[i].type == 1)
		{
			wattron(cor->vizu->win1, COLOR_PAIR(23));
			mvwprintw(cor->vizu->win1, (i / 64) + 1, (i % 64) * 3 + 2,
			"%02x", cor->vizu->map[i].comm);
			wattroff(cor->vizu->win1, COLOR_PAIR(23));
		}
		else if (cor->vizu->map[i].player == -1)
		{
			wattron(cor->vizu->win1, COLOR_PAIR(22));
			mvwprintw(cor->vizu->win1, (i / 64) + 1, (i % 64) * 3 + 2,
			"%02x", cor->vizu->map[i].comm);
			wattroff(cor->vizu->win1, COLOR_PAIR(22));
		}
		else
			refresh_map2(cor, i);
		if (cor->stealth == 1)
			cor->vizu->map[i].comm = 255;
	}
}
