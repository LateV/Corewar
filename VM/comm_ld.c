#include "vm.h"

void comm_ld(t_cor *cor, t_process *process)
{
	if (process->delay == -1)
		process->delay = 5;
	else if (process->delay > 0)
		process->delay--;
	else if (process->delay == 0)
	{
		if(cor->arena[process->pc + 1] == 144)
		{
			load_data_to_reg(cor, process, 4, process->pc + 6);
			printf("aaaaaa = %d\n", process->registr[process->pc + 6]);
			process->pc =  process->pc + 7;
		}
		printf("x = %02x\n", cor->arena[process->pc]);
	}
	// printf("pos = %d\n", process->pc);
	// printf("%02x\n", cor->arena[process->pc]);
	// printf("%s\n", "ld");	
}