#include "vm.h"

static int arg_read(t_cor *cor, t_process *process, int *name)
{
	int s;

	s = 2;
	if(process->arg1 == 1)
		process->codage = 0;
	if (process->arg2 != 1)
		process->codage = 0;
	if (process->arg3 != 0)
		process->codage = 0;
	if (process->arg1 == 2)
		*name = 2;
	else if (process->arg1 == 3)
		*name = 3;
	s = arg_handler(cor, process, &process->arg1, s);
	s = arg_handler(cor, process, &process->arg2, s);
	s = arg_handler(cor, process, &process->arg3, s);
	return(s);
}		

void comm_ld(t_cor *cor, t_process *process)
{
	int sk;
	int name;

	name = 0;
	if (process->delay < 0)
		process->delay = 4;
	else if (process->delay > 0)
		process->delay--;
	if (process->delay == 0)
	{
		process->label = 4;
		codage_identify(process, get_char(cor, process->pc + 1));
		process->codage = 1;
		sk = arg_read(cor, process, &name);
		if(process->codage == 1)
		{
			if (name == 2)
			{
				process->registr[process->arg2 - 1] = process->arg1;
				ft_putstr("-> ld ");
				ft_putnbr(get_reg(process, process->arg2 - 1));
				ft_putstr(" r");
				ft_putnbr(process->arg2);
				ft_putstr("\n");
			}
			else if (name == 3)
			{

			}
		}
		set_proc_pos(process, sk);
		process->delay = -1;
		process->codage = 1;
		process->command = -1;
	}
}