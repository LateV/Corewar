#include "vm.h"

static int arg_read(t_cor *cor, t_process *process)
{
	int s;

	s = 2;
	if(process->arg1 == 0)
		process->codage = 0;
	if (process->arg2 == 3 || process->arg2 == 0)
		process->codage = 0;
	if (process->arg3 != 1)
		process->codage = 0;
	process->arg_type[0] = process->arg1;
	process->arg_type[1] = process->arg2;
	process->arg_type[2] = process->arg3;
	s = arg_handler(cor, process, &process->arg1, s);
	s = arg_handler(cor, process, &process->arg2, s);
	s = arg_handler(cor, process, &process->arg3, s);
	return(s);
}		


void comm_ldi(t_cor *cor, t_process *process)
{
	int sk;
	int first;

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
		if(process->codage == 1)
		{
			first = process->arg1;
			if (process->arg1 == 3)
				first = get_int(cor, (process->arg1 % IDX_MOD) + process->pc);
			load_to_reg(cor, process, (((first + process->arg2) % IDX_MOD) + process->pc), process->arg3 - 1);
			if(cor->visu == 0)
			{
				ft_printf("P%5d | ldi: load from %d + %d r%d\n",
					process->count_num, process->arg1, process->arg2, process->arg3);
			}
		}
		set_proc_pos(cor, process, sk);
		process->delay = -1;
		process->codage = 1;
		process->command = -1;
	}
}
