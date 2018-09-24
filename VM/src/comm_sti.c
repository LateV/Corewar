/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:42:12 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/20 20:42:14 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	arg_read(t_cor *cor, t_process *process)
{
	int s;

	s = 2;
	if (process->arg1 != 1 || process->arg3 == 3)
		process->codage = 0;
	process->arg_type[0] = process->arg1;
	process->arg_type[1] = process->arg2;
	process->arg_type[2] = process->arg3;
	s = arg_handler(cor, process, &process->arg1, s);
	s = arg_handler(cor, process, &process->arg2, s);
	s = arg_handler(cor, process, &process->arg3, s);
	return (s);
}

static int	arg_val_hendler(t_process *process)
{
	if (process->arg_type[1] == 1)
	{
		if (process->arg2 <= 0 || process->arg2 > 16)
			return (0);
		process->arg2 = get_reg(process, process->arg2 - 1);
	}
	if (process->arg_type[2] == 1)
	{
		if (process->arg3 <= 0 || process->arg3 > 16)
			return (0);
		process->arg3 = get_reg(process, process->arg3 - 1);
	}
	return (1);
}

void		sti_reg_dir_dir(t_cor *cor, t_process *process)
{
	if (cor->visu == 0 && cor->dump == 0 && cor->s ==
	0 && (cor->mon == cor->cycles || cor->log == 1))
	{
		ft_printf("P% 5d | sti r%d %d %d\n       | -> store to %d + %d = %d (with pc and mod %d)\n",
			process->count_num, process->arg1, process->arg2, process->arg3,
			process->arg2, process->arg3, process->arg2 + process->arg3,
			process->pc + ((process->arg2 + process->arg3) % IDX_MOD));
	}
	load_from_reg(cor, process, process->pc +
	((process->arg2 + process->arg3) % IDX_MOD), process->arg1 - 1);
}

void		comm_sti(t_cor *cor, t_process *process)
{
	int sk;

	if (process->delay < 0)
		process->delay = 24;
	else if (process->delay > 0)
		process->delay--;
	if (process->delay == 0)
	{
		process->label = 2;
		codage_identify(process, get_char(cor, process->pc + 1));
		process->codage = 1;
		sk = arg_read(cor, process);
		if (process->codage == 1 && process->arg1 > 0 && process->arg1 < 17)
		{
			if (arg_val_hendler(process))
			{
				sti_reg_dir_dir(cor, process);
			}
		}
		set_proc_pos(cor, process, sk);
		process->delay = -1;
		process->command = -1;
	}
}
