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
	s = arg_handler(cor, process, &process->arg3, s);
	return(s);
}		


void sti_dir_reg(t_cor *cor, t_process *process)
{
	load_data_to_reg(cor, process, process->arg1, process->arg2 - 1);
	ft_printf("P    %d | ld %d r%d\n", process->count_num, process->arg1, process->arg2);
}

void sti_ind_reg(t_cor *cor, t_process *process)
{
	process->arg1 = process->arg1 % IDX_MOD;
	load_data_to_reg(cor, process, process->arg1 + process->pc, process->arg2 - 1);
	ft_printf("P    %d | ld %d r%d\n", process->count_num, process->arg1, process->arg2);
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
		if (process->codage == 1)
		{
			if (process->arg_type[0] == 2)
				sti_dir_reg(cor, process);
			else if (process->arg_type[0] == 3)
				sti_ind_reg(cor, process);
		}
		if (process->registr[process->arg2 - 1] == 0)
			process->carry = 1;
		else
			process->carry = 0;
		set_proc_pos(cor, process, sk);
		process->delay = -1;
		process->codage = 1;
		process->command = -1;
	}
}