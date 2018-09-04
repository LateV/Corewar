#include "vm.h"

static int arg_read(t_cor *cor, t_process *process)
{
	int s;

	s = 2;
	if(process->arg1 != 1 || process->arg2 != 1 || process->arg3 != 1)
		process->codage = 0;
	s = arg_handler(cor, process, &process->arg1, s);
	s = arg_handler(cor, process, &process->arg2, s);
	s = arg_handler(cor, process, &process->arg3, s);
	return(s);
}		

void comm_sub(t_cor *cor, t_process *process)
{
	int sk;
	int tmp;

	if (process->delay < 0)
		process->delay = 9;
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
			tmp = get_reg(process, process->arg1 - 1) - get_reg(process, process->arg2 - 1);
			process->registr[process->arg3 - 1] = tmp;
			ft_putstr("->sub r");
			ft_putnbr(process->arg1);
			ft_putstr(" + r");
			ft_putnbr(process->arg2);
			ft_putstr(" to ");
			ft_putnbr(process->arg3);
			ft_putstr("\n");
			if (tmp == 0)
				process->carry = 1;
			else
				process->carry = 0;
	
		}
		set_proc_pos(process, sk);
		process->delay = -1;
		process->codage = 1;
		process->command = -1;
	}
}