#include "vm.h"

void comm_live(t_cor *cor, t_process *process)
{
	int sk;
	int i;

	i = 0;
	if (process->delay < 0)
		process->delay = 9;
	else if (process->delay > 0)
		process->delay--;
	if (process->delay == 0)
	{
		process->label = 4;
		process->codage = 1;
		sk = t_dir(cor, process, &process->arg1, process->pc + 1);
		if(process->codage == 1)
		{
			ft_putstr("->live: ");
			ft_putnbr(process->arg1);
			ft_putstr("\n");
			process->live = 1;
			while(i < cor->p_num)
			{
				if(process->arg1 == cor->player[i].num)
					cor->player[i].live_summ++;
				i++;
			}
		}
		set_proc_pos(process, sk + 1);
		process->delay = -1;
		process->codage = 1;
		process->command = -1;
	}	
}
