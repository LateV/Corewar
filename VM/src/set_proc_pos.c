#include "vm.h"

void set_proc_pos(t_cor *cor, t_process *process, int shift)
{
	if( (shift + process->pc) >= 0)
	{
		if(cor->visu == 1)
			cor->vizu->map[process->pc].type = 0;
		while(shift + process->pc >= MEM_SIZE)
			process->pc = process->pc - MEM_SIZE;
		process->pc = process->pc + shift;
		if(cor->visu == 1)
			cor->vizu->map[process->pc].type = 1;

	}
	else
	{
		if(cor->visu == 1)
			cor->vizu->map[process->pc].type = 0;
		while(shift + process->pc < 0)
			process->pc = process->pc + MEM_SIZE;
		process->pc = process->pc + shift;
		if(cor->visu == 1)
			cor->vizu->map[process->pc].type = 1;
	}
}
