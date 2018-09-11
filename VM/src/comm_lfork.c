#include "vm.h"

void comm_lfork(t_cor *cor, t_process *process)
{
	int sk;

	if (process->delay < 0)
		process->delay = 999;
	else if (process->delay > 0)
		process->delay--;
	if (process->delay == 0)
	{
		process->label = 2;
		process->codage = 1;
		sk = t_dir(cor, process, &process->arg1, process->pc + 1);
		if(cor->visu == 0)
		{
			ft_printf("P    %d | lfork %d (%d)\n",
				process->count_num, process->arg1, process->pc + process->arg1 );
		}
		add_proc(cor, process, process->pc + process->arg1);
		set_proc_pos(cor, process, sk + 1);
		process->delay = -1;
		process->codage = 1;
		process->command = -1;
	}
}