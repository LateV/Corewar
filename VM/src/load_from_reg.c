#include "vm.h"

void load_from_reg(t_cor *cor, t_process *process, int loc, int r_num)
{
	int j;
	int i;
	char *tmp;

	i = 0;
	j = 3;
	if(r_num < 0 || r_num > 15)
		return ;
	tmp = (char*)&process->registr[r_num];
	while(i < 4)
	{
		while((loc + i) >= MEM_SIZE)
			loc = loc  - MEM_SIZE;
		while((loc + i) < 0)
			loc = loc + MEM_SIZE;
		cor->arena[loc + i] = tmp[j];
		if(cor->visu == 1) 
		{
			cor->vizu->map[loc + i].comm = tmp[j];
			cor->vizu->map[loc + i].player = process->player->num * (-1);
			cor->vizu->map[loc + i].life_time = 100;
		}
		i++;
		j--;
	}
}