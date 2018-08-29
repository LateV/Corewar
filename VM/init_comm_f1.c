#include "vm.h"

void load_data_to_reg(t_cor *cor, t_process *process, int size, int r_num)
{
	int i;
	char *tmp;

	i = 0;
	tmp = (char*)&process->registr[r_num];
	while(size > 0)
	{
		tmp[size - 1] = cor->arena[process->pc + 2 + i];
		size--;
		i++;
	}
}

void comm_live(t_cor *cor, t_process *process)
{
	printf("pos = %d\n", process->pc);
	printf("%02x\n", cor->arena[process->pc]);
	printf("%s\n", "live");	
}

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
			process->pc =  process->pc + 6;
		}
		printf("x = %d\n", cor->arena[process->pc + 1]);
	}
	// printf("pos = %d\n", process->pc);
	// printf("%02x\n", cor->arena[process->pc]);
	// printf("%s\n", "ld");	
}