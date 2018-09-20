/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_and_or_xor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:40:47 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/20 20:40:49 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int pair_arg(t_cor *cor, t_process *process, char *s1)
{
	int res;

	if(process->command == 5)
		res = process->arg1 & process->arg2;
	if(process->command == 6)
		res = process->arg1 | process->arg2;
	if(process->command == 7)
		res = process->arg1 ^ process->arg2;
	if(cor->visu == 0 && cor->dump == 0 && cor->s == 0 && (cor->mon == cor->cycles || cor->log == 1))
	{
		ft_printf("P% 5d | %s %d %d r%d\n",
		process->count_num, s1, process->arg1, process->arg2, process->arg3);
	}
	return(res);
}

static void hend_comm(t_cor *cor, t_process *process)
{
	int res;

	if(process->command == 5)
		res = pair_arg(cor, process, "and");
	if(process->command == 6)
		res = pair_arg(cor, process, "or");
	if(process->command == 7)
		res = pair_arg(cor, process, "xor");
	if(res == 0)
		process->carry = 1;
	else
		process->carry = 0;
	process->registr[process->arg3 - 1] = res;
}


static int arg_read(t_cor *cor, t_process *process)
{
	int s;

	s = 2;
	if(process->arg1 == 0 || process->arg2 == 0 || process->arg3 == 0)
		process->codage = 0;
	if(process->arg3 != 1)
		process->codage = 0;
	process->arg_type[0] = process->arg1;
	process->arg_type[1] = process->arg2;
	process->arg_type[2] = process->arg3;
	s = arg_handler(cor, process, &process->arg1, s);
	s = arg_handler(cor, process, &process->arg2, s);
	s = arg_handler(cor, process, &process->arg3, s);
	return(s);
}

static int arg_val_hendler(t_process *process)
{
	if(process->arg_type[0] == 1)
	{
		if(process->arg1 <= 0 || process->arg1 > 16)
			return(0);
		process->arg1 = get_reg(process, process->arg1 - 1);
	}
	if(process->arg_type[1] == 1)
	{
		if(process->arg2 <= 0 || process->arg2 > 16)
			return(0);
		process->arg2 = get_reg(process, process->arg2 - 1);
	}
	return(1);
}


void comm_and_or_xor(t_cor *cor, t_process *process)
{
	int sk;
	
	if (process->delay < 0)
		process->delay = 5;
	else if (process->delay > 0)
		process->delay--;
	if (process->delay == 0)
	{
		process->label = 4;
		codage_identify(process, get_char(cor, process->pc + 1));
		process->codage = 1;
		sk = arg_read(cor, process);
		if(process->codage == 1 && process->arg3 > 0 && process->arg3 < 17)
		{
			if(arg_val_hendler(process))
				hend_comm(cor, process);
		}
		set_proc_pos(cor, process, sk);
		process->delay = -1;
		process->codage = 1;
		process->command = -1;
	}
}
