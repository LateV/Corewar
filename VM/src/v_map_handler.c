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

void	refresh_player(t_cor *cor)
{
	int i;

	i = 0;
	while (i < cor->p_num)
	{
		mvwprintw(cor->vizu->win2, 12 + (i * 4),
		16, "%20d", cor->player[i].last_live);
		mvwprintw(cor->vizu->win2, 13 + (i * 4),
		30, "%6d", cor->player[i].live_summ);
		i++;
	}
}

void	refresh_vizu(t_cor *cor)
{
	initital_draw(cor);
	mvwprintw(cor->vizu->win2, 21 + ((cor->vizu->end_of_prs - 1) * 4),
	2, "CYCLE_TO_DIE : %-6d", cor->curr_cycle_t_d);
	refresh_map(cor);
	refresh_player(cor);
	break_printer(cor, cor->vizu->brakedown, 16);
	break_printer(cor, cor->vizu->last_brakedown, 19);
	wrefresh(cor->vizu->win1);
	wrefresh(cor->vizu->win2);
	if (cor->pause == 0)
		usleep(cor->vizu->speed);
	else
		usleep(1000);
}

void	init_map(t_cor *cor)
{
	int i;

	cor->vizu->map = (t_map *)malloc(sizeof(t_map) * 4096);
	i = -1;
	while (++i < 4096)
	{
		cor->vizu->map[i].comm = 0;
		cor->vizu->map[i].type = 0;
		cor->vizu->map[i].player = -1;
		cor->vizu->map[i].car_player = -1;
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
