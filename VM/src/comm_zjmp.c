#include "vm.h"

void comm_zjmp(t_cor *cor, t_process *process)
{
	int sk;

	if (process->delay < 0)
		process->delay = 19;
	else if (process->delay > 0)
		process->delay--;
	if (process->delay == 0)
	{
		process->label = 2;
		process->codage = 1;
		sk = t_dir(cor, process, &process->arg1, process->pc + 1);
		ft_putstr("pc = ");
		ft_putnbr(process->pc + process->arg1);
		ft_putstr("\n");
		ft_putstr("->zjmp: ");
		ft_putnbr(process->arg1);
		if(process->carry == 1)
		{
			set_proc_pos(process, process->arg1);
			ft_putstr(" OK\n");
		}
		else
		{
			set_proc_pos(process, sk + 1);
			ft_putstr(" FAIL\n");
		}
		process->delay = -1;
		process->codage = 1;
		process->command = -1;
	}
}