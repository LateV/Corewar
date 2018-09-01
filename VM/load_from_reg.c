#include "vm.h"

void load_from_reg(t_cor *cor, t_process *process, int loc, int r_num)
{
	int j;
	int i;
	char *tmp;

	i = 0;
	j = 0;
	if(r_num < 0 || r_num > 15)
		return ;
	tmp = (char*)&process->registr[r_num];
	while(i < 4)
	{
		while((loc + i) >= MEM_SIZE)
			loc = loc  - MEM_SIZE;
		cor->arena[loc + i] = tmp[j];
		i++;
		j++;
	}
}
