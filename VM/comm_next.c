#include "vm.h"

void comm_next(t_cor *cor, t_process *process)
{
	printf("pos = %d\n", process->pc);
	 process->pc++;
	printf("%02x\n", cor->arena[process->pc]);
	printf("%s\n", "aff");
}