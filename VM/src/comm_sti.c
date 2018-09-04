#include "vm.h"

static int arg_read(t_cor *cor, t_process *process)
{
	int s;

	s = 2;
	if(process->arg1 != 1 || process->arg3 == 3)
		process->codage = 0;
	process->arg_type[0] = process->arg1;
	process->arg_type[1] = process->arg2;
	process->arg_type[2] = process->arg3;
	s = arg_handler(cor, process, &process->arg1, s);
	s = arg_handler(cor, process, &process->arg2, s);
	s = arg_handler(cor, process, &process->arg3, s);
	return(s);
}		

void sti_reg_dir_dir(t_cor *cor, t_process *process)
{
	ft_printf("P    %d | sti r%d %d %d\n       | -> store to %d + %d = %d (with pc and mod %d)",
		process->count_num, process->arg1, process->arg2, process->arg3, process->arg2,
		process->arg3, process->arg2 + process->arg3, process->arg2 + process->arg3);
	ft_putstr("->sti: store to ");
	ft_putnbr(process->arg2);
	ft_putstr(" + ");
	ft_putnbr(process->arg3);
	ft_putstr(" = ");
	ft_putnbr(process->arg2 + process->arg3);
	ft_putstr("\n");
	load_from_reg(cor, process, process->pc + ((process->arg2 + process->arg3) % IDX_MOD), process->arg1 - 1);
}

void comm_sti(t_cor *cor, t_process *process)
{
	int sk;

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
			if(process->arg_type[0] == 1 && process->arg_type[1] == 2 && process->arg_type[2] == 2)
				sti_reg_dir_dir(cor, process);
		}
		set_proc_pos(process, sk);
		process->delay = -1;
		process->command = -1;
	}	
}
