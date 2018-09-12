#include "vm.h"

static int arg_read(t_cor *cor, t_process *process)
{
	int s;

	s = 2;
	if(process->arg1 == 1)
		process->codage = 0;
	if (process->arg2 != 1)
		process->codage = 0;
	if (process->arg3 != 0)
		process->codage = 0;
	process->arg_type[0] = process->arg1;
	process->arg_type[1] = process->arg2;
	process->arg_type[2] = process->arg3;
	s = arg_handler(cor, process, &process->arg1, s);
	s = arg_handler(cor, process, &process->arg2, s);
	return(s);
}		


void comm_ld(t_cor *cor, t_process *process)
{
	int sk;

	sk = 0;
	if (process->delay < 0)
		process->delay = 4;
	else if (process->delay > 0)
		process->delay--;
	if (process->delay == 0)
	{
		process->label = 4;
		codage_identify(process, get_char(cor, process->pc + 1));
		process->codage = 1;
		sk = arg_read(cor, process);
		if(process->codage == 1 && process->arg2 > 0 && process->arg2 < 17)
		{
			if(process->arg_type[0] == 2)
			{
				process->registr[process->arg2 - 1] = process->arg1;
				if(cor->visu == 0)
				{
					ft_printf("P%5d | ld %d r%d\n",
						process->count_num, get_reg(process, process->arg2 - 1), process->arg2);
				}
				if (process->registr[process->arg2 - 1] == 0)
					process->carry = 1;
				else
					process->carry = 0;
			}
			else
			{
				process->arg1 = process->arg1 % IDX_MOD;
				load_data_to_reg(cor, process, process->pc + process->arg1, process->arg2 - 1);
			}
		}
		set_proc_pos(cor, process, sk);
		process->delay = -1;
		process->codage = 1;
		process->command = -1;
	}
}