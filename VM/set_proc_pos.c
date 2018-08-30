#include "vm.h"

void set_proc_pos(t_process *process, int shift)
{
	while(shift + process->pc >= MEM_SIZE)
		process->pc = process->pc - MEM_SIZE;
	process->pc = process->pc + shift;
}
