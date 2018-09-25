/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasted_live.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 16:20:24 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/25 16:20:25 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				wasted_live1(t_cor *cor)
{
	int i;

	i = 0;
	while (i < 4)
	{
		cor->player[i].live_curr = 0;
		cor->player[i].live_summ = 0;
		cor->player[i].all_cur = 0;
		i++;
	}
}

void				end_game(t_cor *cor)
{
	if (cor->visu == 0)
		ft_printf("Contestant %d, \"%s\", has won !\n",
			cor->winner->num * (-1), cor->winner->prog_name);
	else
		gg_wp(cor);
	endwin();
	exit(0);
}

void				max_ch(t_cor *cor)
{
	cor->curr_chechs++;
	if (cor->curr_chechs == MAX_CHECKS)
	{
		cor->curr_cycle_t_d = cor->curr_cycle_t_d - CYCLE_DELTA;
		if (cor->visu == 0 && cor->dump == 0 && cor->s == 0 &&
			(cor->mon == cor->cycles || cor->log == 1))
			ft_printf("Cycle to die is now %d\n", cor->curr_cycle_t_d);
		cor->curr_chechs = 0;
	}
}

void				max_live(t_cor *cor)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (cor->player[i].all_cur >= NBR_LIVE)
		{
			cor->curr_cycle_t_d = cor->curr_cycle_t_d - CYCLE_DELTA;
			if (cor->visu == 0 && cor->dump == 0 && cor->s == 0 &&
				(cor->mon == cor->cycles || cor->log == 1))
				ft_printf("Cycle to die is now %d\n", cor->curr_cycle_t_d);
			cor->curr_chechs = cor->curr_chechs - 1;
			break ;
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		cor->player[i].live_curr = 0;
		cor->player[i].live_summ = 0;
		cor->player[i].all_cur = 0;
		i++;
	}
}

void				del_first(t_cor *cor)
{
	t_process *tmp;

	if (cor->visu == 1)
		cor->vizu->map[cor->process->pc].type = 0;
	tmp = cor->process->next;
	free(cor->process);
	cor->process = tmp;
	cor->alive_cur--;
	if (!tmp)
		end_game(cor);
}
