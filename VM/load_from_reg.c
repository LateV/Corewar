#include "vm.h"

void load_from_reg(t_cor *cor, t_process *process, int loc, int r_num)
{
	int i;
	char *tmp;

	i = 0;
	tmp = (char*)&process->registr[r_num];
	while(i < 4)
	{
		cor->arena[loc + i] = tmp[i];
		i++;
	}
}
