#include "vm.h"

void comm_live(t_cor *cor, t_process *process)
{
	int sk;
	int i;

	i = 0;
	if (process->delay < 0)
		process->delay = 9;
	else if (process->delay > 0)
		process->delay--;
	if (process->delay == 0)
	{
		process->label = 4;
		sk = t_dir(cor, process, &process->arg1, process->pc + 1);
		if(cor->visu == 0 && cor->dump == 0 && (cor->mon == cor->cycles || cor->mon == 0))
			ft_printf("P% 5d | live %d\n", process->count_num, process->arg1);
		process->live = 1;
		process->player->live_curr++;
		while(i < cor->p_num)
		{
			if(process->arg1 == cor->player[i].num)
			{
				cor->winner = &cor->player[i];
				cor->player[i].last_live = cor->cycles;
				cor->player[i].live_summ++;
			}
			i++;
		}
		if(cor->visu == 1)
			cor->vizu->map[process->pc].life_scream = 100;
		set_proc_pos(cor, process, sk + 1);
		process->delay = -1;
		process->codage = 1;
		process->command = -1;
	}	
}
