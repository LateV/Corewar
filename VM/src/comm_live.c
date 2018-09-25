/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:41:32 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/20 20:41:33 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline static void		live_a_arg(t_cor *cor, t_process *process)
{
	int	i;

	i = 0;
	while (i < cor->p_num)
	{
		if (process->arg1 == cor->player[i].num)
		{
			cor->winner = &cor->player[i];
			cor->player[i].last_live = cor->cycles;
			cor->player[i].live_summ++;
			if (cor->visu == 1)
			{
				cor->vizu->map[process->pc].car_player =
				cor->player[i].num * (-1);
				cor->vizu->map[process->pc].life_scream = 100;
			}
		}
		if (cor->player[i].num == process->player->num)
			cor->player[i].live_curr++;
		i++;
	}
}

void					comm_live(t_cor *cor, t_process *process)
{
	int	sk;

	if (process->delay < 0)
		process->delay = 9;
	else if (process->delay > 0)
		process->delay--;
	if (process->delay == 0)
	{
		process->label = 4;
		sk = t_dir(cor, process, &process->arg1, process->pc + 1);
		if (cor->visu == 0 && cor->dump == 0 && cor->s == 0 &&
			(cor->mon == cor->cycles || cor->log == 1))
			ft_printf("P% 5d | live %d\n", process->count_num, process->arg1);
		process->live = 1;
		process->player->all_cur++;
		live_a_arg(cor, process);
		set_proc_pos(cor, process, sk + 1);
		process->delay = -1;
		process->codage = 1;
		process->command = -1;
	}
}
