#include "vm.h"

void add_proc(t_cor *cor, t_process *process, int loc)
{
	t_process *new;
	int i;

	i = 0;
	if (cor->process)
	{
		new = ft_memalloc(sizeof(t_process));
		while(i < 17)
		{
			new->registr[i] = process->registr[i];
			i++;
		}
		new->next = cor->process;
		new->live = 0;
		new->pc = loc;
		new->carry = 1;
		new->delay = -1;
		new->arg1 = 0;
		new->arg2 = 0;
		new->arg3 = 0;
		new->label = 0;
		new->codage = 1;
		new->command = -1;
		new->ind_loc = -1;
		new->player = process->player;
		new->live = 0;
		new->count_num = cor->proc_num;
		cor->proc_num++;
		cor->process = new;
	}
}

void comm_fork(t_cor *cor, t_process *process)
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
		if(cor->visu == 0)
		{
			ft_printf("P%5d | fork %d (%d)\n",
				process->count_num, process->arg1, process->pc + (process->arg1 % IDX_MOD));
		}
		add_proc(cor, process, process->pc + (process->arg1 % IDX_MOD));
		set_proc_pos(cor, process, sk + 1);
		process->delay = -1;
		process->codage = 1;
		process->command = -1;
	}
}