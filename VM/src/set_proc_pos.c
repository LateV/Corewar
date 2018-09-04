#include "vm.h"

void set_proc_pos(t_process *process, int shift)
{
	if( (shift + process->pc) >= 0)
	{
		while(shift + process->pc >= MEM_SIZE)
			process->pc = process->pc - MEM_SIZE;
		process->pc = process->pc + shift;
	}
	else
	{
		while(shift + process->pc < 0)
			process->pc = process->pc + MEM_SIZE;
		process->pc = process->pc + shift;
	}
}
