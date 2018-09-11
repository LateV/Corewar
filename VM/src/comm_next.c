#include "vm.h"

void comm_next(t_cor *cor, t_process *process)
{
	printf("pos = %d\n", process->pc);
	set_proc_pos(cor, process, 1);
	printf("%02x\n", cor->arena[process->pc]);
	printf("%s\n", "aff");
}