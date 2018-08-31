#include "vm.h"

static int arg_read(t_cor *cor, t_process *process)
{
	int s;

	s = 2;
	if(process->arg1 != 1 || process->arg3 == 3)
		process->codage = 0;
	s = arg_handler(cor, process, &process->arg1, s);
	s = arg_handler(cor, process, &process->arg2, s);
	s = arg_handler(cor, process, &process->arg3, s);
	return(s);
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
			ft_putstr("->sti: store to ");
			ft_putnbr(process->arg2);
			ft_putstr(" + ");
			ft_putnbr(process->arg3);
			ft_putstr(" = ");
			ft_putnbr(process->arg2 + process->arg3);
			ft_putstr("\n");
			load_from_reg(cor, process, process->pc + ((process->arg2 + process->arg3) % IDX_MOD), process->arg1 - 1);
		}
		set_proc_pos(process, sk);
		process->delay = -1;
		process->codage = 1;
		process->command = -1;
	}	
}
