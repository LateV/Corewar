/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:42:41 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/20 20:42:42 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		zjmp_a_arg(t_cor *cor, t_process *process)
{
	int sk;

	sk = t_dir(cor, process, &process->arg1, process->pc + 1);
	if (process->carry == 1)
	{
		set_proc_pos(cor, process, process->arg1 % IDX_MOD);
		if (cor->visu == 0 && cor->dump == 0 && cor->s == 0 &&
			(cor->mon == cor->cycles || cor->log == 1))
			ft_printf("P% 5d | zjmp %d OK\n",
				process->count_num, process->arg1);
	}
	else
	{
		set_proc_pos(cor, process, sk + 1);
		if (cor->visu == 0 && cor->dump == 0 && cor->s == 0 &&
			(cor->mon == cor->cycles || cor->log == 1))
			ft_printf("P% 5d | zjmp %d FAILED\n",
				process->count_num, process->arg1);
	}
}

void		comm_zjmp(t_cor *cor, t_process *process)
{
	if (process->delay < 0)
		process->delay = 19;
	else if (process->delay > 0)
		process->delay--;
	if (process->delay == 0)
	{
		process->label = 2;
		process->codage = 1;
		zjmp_a_arg(cor, process);
		process->delay = -1;
		process->codage = 1;
		process->command = -1;
	}
}
