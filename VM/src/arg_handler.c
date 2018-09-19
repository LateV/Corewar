#include "vm.h"

int t_dir(t_cor *cor, t_process *process, int *arg, int loc)
{
	while(loc  >= MEM_SIZE)
		loc = loc  - MEM_SIZE;
	while(loc  < 0)
		loc = loc + MEM_SIZE;
	if(process->label == 2)
	{
		*arg = get_short(cor, loc);
		return (2);
	}
	else
	{
		*arg = get_int(cor, loc);
		return (4);
	}
}

int t_reg(t_cor *cor, int *arg, int loc)
{
	while(loc  >= MEM_SIZE)
		loc = loc  - MEM_SIZE;
	while(loc  < 0)
		loc = loc + MEM_SIZE;
	*arg = get_int(cor, loc);
	return(4);
}

int t_ind(t_cor *cor, int *arg, int loc)
{

	while (loc  >= MEM_SIZE)
		loc = loc  - MEM_SIZE;
	while (loc  < 0)
		loc = loc + MEM_SIZE;
	*arg = get_int(cor, loc);
	return (4);
}


int arg_handler(t_cor *cor, t_process *process, int *arg, int s)
{
	int ind;
	
	if(*arg == 1)
	{
		*arg = get_char(cor, process->pc + s);
		s++;
	}
	else if(*arg == 2)
	{
		if(process->label == 2)
		{
			*arg = get_short(cor, process->pc + s);
			s += 2;
		}
		else
		{
			*arg = get_int(cor, process->pc + s);
			s += 4;
		}
	}
	else if(*arg == 3)
	{
		ind = get_short(cor , process->pc + s);
		if(process->command == 12)
			*arg = get_int(cor, process->pc + ind);
		else if(process->command == 1 || process->command == 10)
		{
			ind = ind % IDX_MOD;
			*arg = get_int(cor, process->pc + ind);
		}
		else
		{
			*arg = get_int(cor, ind % IDX_MOD);
		}
		process->ind_loc = ind;
		s += 2;
	}
	else
		*arg = 0;
	return(s);
}