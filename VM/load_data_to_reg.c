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
