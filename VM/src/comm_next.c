#include "vm.h"

void comm_next(t_cor *cor, t_process *process)
{
	set_proc_pos(cor, process, 1);
	process->delay = -1;
	process->codage = 1;
	process->command = -1;
}