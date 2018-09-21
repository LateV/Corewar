/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_map_handler4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 16:17:43 by rkhilenk          #+#    #+#             */
/*   Updated: 2018/09/21 16:17:44 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		off_rounder(t_cor *cor, int res_summ)
{
	int	max_score;
	int max_player;
	int i;

	max_score = 0;
	max_player = 0;
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

void		break_printer(t_cor *cor, int array[4], int line)
{
	int carret;
	int i;

	carret = 0;
	i = -1;
	mvwprintw(cor->vizu->win2, line + ((cor->p_num - 1) * 4),
	2, "%s", "[--------------------------------------------------]");
	while (++i < cor->p_num)
	{
		if (array[i] != 0)
		{
			wattron(cor->vizu->win2, COLOR_PAIR(i + 1));
			mvwprintw(cor->vizu->win2, line + ((cor->p_num - 1)
			* 4), 3 + carret, "%.*s", array[i],
			"--------------------------------------------------");
			wattroff(cor->vizu->win2, COLOR_PAIR(i + 1));
			carret += array[i];
		}
	}
}

void		breakdown_cpy(t_cor *cor)
{
	int i;

	i = -1;
	while (++i < cor->p_num)
		cor->vizu->last_brakedown[i] = cor->vizu->brakedown[i];
}

static int	brakedown2(t_cor *cor, int i, int res_summ, double summ)
{
	while (++i < cor->p_num)
	{
		if (cor->player[i].live_summ != 0)
		{
			cor->vizu->brakedown[i] = (50 / summ) * cor->player[i].live_summ;
			res_summ += cor->vizu->brakedown[i];
		}
		else
			cor->vizu->brakedown[i] = 0;
	}
	return (res_summ);
}

void		breakdown(t_cor *cor)
{
	int		i;
	double	summ;
	int		res_summ;

	i = -1;
	res_summ = 0;
	summ = 0;
	while (++i < cor->p_num)
		summ += cor->player[i].live_summ;
	i = -1;
	if (cor->live_check == cor->curr_cycle_t_d)
	{
		breakdown_cpy(cor);
		system("afplay ./sound.mp3&");
	}
	res_summ = brakedown2(cor, i, res_summ, summ);
	if (res_summ != 0 && res_summ != 50)
		off_rounder(cor, res_summ);
}
