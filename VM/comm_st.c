#include "vm.h"

void comm_st(t_cor *cor, t_process *process)
{
	printf("pos = %d\n", process->pc);
	printf("%02x\n", cor->arena[process->pc]);
	printf("%s\n", "st");
	set_proc_pos(process, 1);
}
