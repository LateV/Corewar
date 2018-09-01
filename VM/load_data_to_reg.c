#include "vm.h"

void load_data_to_reg(t_cor *cor, t_process *process, int size, int r_num)
{
	int pos;
	int i;
	char *tmp;

	i = 2;
	pos = process->pc;
	if(r_num < 0 || r_num > 15 || size < 0 || size > 4)
		return ;
	tmp = (char*)&process->registr[r_num];
	while(size > 0)
	{
		if( (pos + i) >= MEM_SIZE)
			pos = pos - MEM_SIZE;
		tmp[size - 1] = cor->arena[pos + i];
		size--;
		i++;
	}
} 


void load_to_reg(t_cor *cor, t_process *process, int loc, int r_num)
{
	int j;
	int i;
	char *tmp;

	i = 4;
	j = 0;
	if (r_num < 0 || r_num > 15)
		return ;
	tmp = (char*)&process->registr[r_num];
	while(i > 0)
	{	
		if( (loc + i) >= MEM_SIZE)
			loc = loc - MEM_SIZE;
		tmp[i] = loc[j];
		i--;
		j++;
	}
}
