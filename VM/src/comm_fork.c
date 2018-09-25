/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:40:54 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/20 20:40:55 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_process		*new_proc_init(t_cor *cor, t_process *process, int loc)
{
	t_process	*new;
	int			i;

	i = -1;
	if (cor->process)
	{
		new = ft_memalloc(sizeof(t_process));
		while (++i < 17)
			new->registr[i] = process->registr[i];
		new->next = cor->process;
		new->pc = loc;
		if (cor->visu == 1)
			cor->vizu->map[loc].type = 1;
		new->carry = process->carry;
		new->live = process->live;
		new->delay = -1;
		new->codage = 1;
		new->command = -1;
		new->ind_loc = -1;
		new->player = process->player;
		new->count_num = cor->proc_num;
		return (new);
	}
	else
		return (NULL);
}

void			add_proc(t_cor *cor, t_process *process, int loc)
{
	while (loc >= MEM_SIZE)
		loc = loc - MEM_SIZE;
	while (loc < 0)
		loc = loc + MEM_SIZE;
	if (cor->process)
	{
		cor->process = new_proc_init(cor, process, loc);
		cor->proc_num++;
		cor->alive_cur++;
	}
}

void			comm_fork(t_cor *cor, t_process *process)
{
	int sk;

	if (process->delay < 0)
		process->delay = 799;
	else if (process->delay > 0)
		process->delay--;
	if (process->delay == 0)
	{
		process->label = 2;
		process->codage = 1;
		sk = t_dir(cor, process, &process->arg1, process->pc + 1);
		if (cor->visu == 0 && cor->dump == 0 && cor->s == 0 &&
		(cor->mon == cor->cycles || cor->log == 1))
		{
			ft_printf("P% 5d | fork %d (%d)\n",
				process->count_num, process->arg1,
				process->pc + (process->arg1 % IDX_MOD));
		}
		add_proc(cor, process, process->pc + (process->arg1 % IDX_MOD));
		set_proc_pos(cor, process, sk + 1);
		process->delay = -1;
		process->codage = 1;
		process->command = -1;
	}
}
