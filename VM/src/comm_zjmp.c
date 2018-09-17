#include "vm.h"

void comm_zjmp(t_cor *cor, t_process *process)
{
	int sk;

	if (process->delay < 0)
		process->delay = 19;
	else if (process->delay > 0)
		process->delay--;
	if (process->delay == 0)
	{
		process->label = 2;
		process->codage = 1;
		sk = t_dir(cor, process, &process->arg1, process->pc + 1);
		if (process->carry == 1)
		{
			set_proc_pos(cor, process, process->arg1);
			if(cor->visu == 0 && cor->dump == 0 && (cor->mon == cor->cycles || cor->mon == 0))
				ft_printf("P% 5d | zjmp %d OK\n", process->count_num, process->arg1);

		}
		else
		{
			set_proc_pos(cor, process, sk + 1);
			if(cor->visu == 0 && cor->dump == 0 && (cor->mon == cor->cycles || cor->mon == 0))
				ft_printf("P% 5d | zjmp %d FAILED\n", process->count_num, process->arg1) ;
		}
		process->delay = -1;
		process->codage = 1;
		process->command = -1;
	}
}
