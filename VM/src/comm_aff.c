/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:40:41 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/20 20:40:42 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		arg_read(t_cor *cor, t_process *process)
{
	int s;

	s = 2;
	if (process->arg1 != 1)
		process->codage = 0;
	codage_identify(process, get_char(cor, process->pc + 1));
	process->arg_type[0] = process->arg1;
	process->arg_type[1] = process->arg2;
	process->arg_type[2] = process->arg3;
	s = arg_handler(cor, process, &process->arg1, s);
	return (s);
}

static int		arg_val_hendler(t_process *process)
{
	if (process->arg_type[0] == 1)
	{
		if (process->arg1 <= 0 || process->arg1 > 16)
			return (0);
		process->arg1 = get_reg(process, process->arg1 - 1);
	}
	return (1);
}

void			comm_aff(t_cor *cor, t_process *process)
{
	int sk;

	if (process->delay < 0)
		process->delay = 1;
	else if (process->delay > 0)
		process->delay--;
	if (process->delay == 0)
	{
		process->label = 4;
		process->codage = 1;
		sk = arg_read(cor, process);
		if (process->codage == 1 && process->arg1 > 0 && process->arg1 < 17)
		{
			if (arg_val_hendler(process))
			{
				if (cor->a == 1 && cor->visu == 0 && cor->dump == 0 &&
					cor->s == 0 && (cor->mon == cor->cycles || cor->log == 1))
					ft_printf("P% 5d | Aff : %c \n",
						process->count_num, (process->arg1 % 256));
			}
		}
		set_proc_pos(cor, process, sk);
		process->delay = -1;
		process->command = -1;
	}
}
