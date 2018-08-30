#include "vm.h"

static int arg_read(t_cor *cor, t_process *process)
{
	int s;

	s = 2;
	if(process->arg3 != 1 || process->arg1 < 1 || process->arg1 > 3
		|| process->arg2 < 1 || process->arg2 > 3)
		return(0);
	s = arg_handler(cor, process, &process->arg1, s);
	s = arg_handler(cor, process, &process->arg2, s);
	s = arg_handler(cor, process, &process->arg3, s);
	return(s);
}		

void comm_and(t_cor *cor, t_process *process)
{
	int sk;

	if (process->delay < 0)
		process->delay = 5;
	else if (process->delay > 1)
		process->delay--;
	else if (process->delay == 1)
	{
		process->label = 4;
		codage_identify(process, get_char(cor, process->pc + 1));
		sk = arg_read(cor, process);
		if(sk > 0)
		{
			// load_from_reg(cor, process, process->pc + ((process->arg2 + process->arg3) % IDX_MOD), process->arg1 - 1);
			ft_putstr("->and: ");
			ft_putnbr(process->arg2);
			ft_putstr(" + ");
			ft_putnbr(process->arg3);
			ft_putstr(" = ");
			ft_putnbr(process->arg2 + process->arg2);
			ft_putstr("\n");
			set_proc_pos(process, sk);
			process->delay = -1;
		}
	}
	ft_printf("process->delay = %d\n", process->delay);
	// printf("pos = %d\n", process->pc);
	// printf("%02x\n", cor->arena[process->pc]);
	// printf("%s\n", "and");
	// set_proc_pos(process, 1);
}
