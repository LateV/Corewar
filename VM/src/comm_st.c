#include "vm.h"

static int arg_read(t_cor *cor, t_process *process, int *ind)
{
	int s;

	s = 2;
	if(process->arg1 != 1 || process->arg3 != 0 || process->arg2 == 2)
		process->codage = 0;
	if(process->arg2 == 3)
		*ind = 1;
	else
		*ind = 0;
	s = arg_handler(cor, process, &process->arg1, s);
	s = arg_handler(cor, process, &process->arg2, s);
	return(s);
}	

void comm_st(t_cor *cor, t_process *process)
{
	int sk;
	int ind;

	if (process->delay < 0)
		process->delay = 4;
	else if (process->delay > 0)
		process->delay--;
	if (process->delay == 0)
	{
		process->label = 4;
		codage_identify(process, get_char(cor, process->pc + 1));
		process->codage = 1;
		process->ind_loc = -1;
		sk = arg_read(cor, process, &ind);
		if(process->codage == 1)
		{
			if(ind == 1)
			{
				if(cor->visu == 0)
					ft_printf("P    %d | st r%d %d\n", process->count_num, process->arg1, process->ind_loc);
				load_from_reg(cor, process, process->pc + (process->arg2 % IDX_MOD), process->arg1 - 1);
			}
			else
			{
				if(cor->visu == 0)
				{
					ft_printf("P    %d | st r%d to r%d\n",
						process->count_num, process->arg1, process->arg2);
				}
				process->registr[process->arg2 - 1] = process->registr[process->arg1 - 1];
			}
		}
		set_proc_pos(cor, process, sk);
		process->delay = -1;
		process->command = -1;
	}
}
