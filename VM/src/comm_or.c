#include "vm.h"

static int arg_read(t_cor *cor, t_process *process)
{
	int s;

	s = 2;
	if(process->arg1 == 0 || process->arg2 == 0 || process->arg3 == 0)
		process->codage = 0;
	if(process->arg3 != 1)
		process->codage = 0;
	s = arg_handler(cor, process, &process->arg1, s);
	s = arg_handler(cor, process, &process->arg2, s);
	s = arg_handler(cor, process, &process->arg3, s);
	return(s);
}		

void comm_or(t_cor *cor, t_process *process)
{
	int res;
	int sk;
	
	if (process->delay < 0)
		process->delay = 5;
	else if (process->delay > 0)
		process->delay--;
	if (process->delay == 0)
	{
		process->label = 4;
		codage_identify(process, get_char(cor, process->pc + 1));
		process->codage = 1;
		sk = arg_read(cor, process);
		if(process->codage == 1)
		{
			res = process->arg1 | process->arg2;
			if(res == 0)
				process->carry = 0;
			else
				process->carry = 1;
			ft_putstr("->and: ");
			ft_putnbr(get_reg(process, process->arg1 - 1));
			ft_putstr(" ");
			ft_putnbr(process->arg2);
			ft_putstr(" r");
			ft_putnbr(process->arg3);
			ft_putstr("\n");
			load_data_to_reg(cor, process, 4, process->arg3 - 1);
		}
		set_proc_pos(cor, process, sk);
		process->delay = -1;
		process->codage = 1;
		process->command = -1;
	}
}
