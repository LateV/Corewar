#include "vm.h"

void comm_sub(t_cor *cor, t_process *process)
{
	printf("pos = %d\n", process->pc);
	printf("%02x\n", cor->arena[process->pc]);
	printf("%s\n", "sub");
	set_proc_pos(process, 1);
}
