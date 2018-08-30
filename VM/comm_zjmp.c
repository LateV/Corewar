#include "vm.h"

void comm_zjmp(t_cor *cor, t_process *process)
{
	printf("pos = %d\n", process->pc);
	printf("%02x\n", cor->arena[process->pc]);
	printf("%s\n", "zjmp");
	set_proc_pos(process, 1);
}
