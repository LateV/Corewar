#include "vm.h"

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
		*arg = get_int(cor, ind);
		s += 2;
	}
	else
		*arg = 0;
	return(s);
}