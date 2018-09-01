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
		new->carry = process->carry;
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
		ft_putstr("->fork: ");
		ft_putnbr(process->arg1);
		ft_putstr(" (");
		ft_putnbr(process->pc + (process->arg1 % IDX_MOD));
		ft_putstr(")");
		ft_putstr("\n");
		add_proc(cor, process, process->pc + (process->arg1 % IDX_MOD));
		process->delay = -1;
		process->codage = 1;
		process->command = -1;
	}
}