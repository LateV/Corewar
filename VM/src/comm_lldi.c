#include "vm.h"

static int arg_read(t_cor *cor, t_process *process, int *name)
{
	int s;

	s = 2;
	if(process->arg1 == 0)
		process->codage = 0;
	if (process->arg2 == 3 || process->arg2 == 0)
		process->codage = 0;
	if (process->arg3 != 1)
		process->codage = 0;
	if (process->arg1 == 3)
		*name = 3;
	s = arg_handler(cor, process, &process->arg1, s);
	s = arg_handler(cor, process, &process->arg2, s);
	s = arg_handler(cor, process, &process->arg3, s);
	return(s);
}		

void comm_lldi(t_cor *cor, t_process *process)
{
	int sk;
	int name;
	int first;

	name = 0;
	if (process->delay < 0)
		process->delay = 49;
	else if (process->delay > 0)
		process->delay--;
	if (process->delay == 0)
	{
		process->label = 2;
		codage_identify(process, get_char(cor, process->pc + 1));
		process->codage = 1;
		sk = arg_read(cor, process, &name);
		if(process->codage == 1)
		{
			first = process->arg1;
			if (name == 3)
				first = get_int(cor, (process->arg1 % IDX_MOD) + process->pc);
			// load_to_reg(cor, process, ((first + process->arg2) + process->pc), process->arg3 - 1);
			if(cor->visu == 0)
			{
				ft_putstr("->ldi: load from ");
				ft_putnbr(process->arg1);
				ft_putstr(" + ");
				ft_putnbr(process->arg2);
				ft_putstr(" r");
				ft_putnbr(process->arg3);
				ft_putstr("\n");
			}
			if (process->registr[process->arg3 - 1] == 0)
					process->carry = 1;
				else
					process->carry = 0;
		}
		set_proc_pos(cor, process, sk);
		process->delay = -1;
		process->codage = 1;
		process->command = -1;
	}
}