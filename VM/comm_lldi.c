#include "vm.h"

void comm_lldi(t_cor *cor, t_process *process)
{
	printf("pos = %d\n", process->pc);
	printf("%02x\n", cor->arena[process->pc]);
	printf("%s\n", "lldi");
	set_proc_pos(process, 1);
}