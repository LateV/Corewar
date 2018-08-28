#include "vm.h"

void comm_st(t_cor *cor, t_process *process)
{
	printf("pos = %d\n", process->pc);
	printf("%02x\n", cor->arena[process->pc]);
	printf("%s\n", "st");	
}

void comm_add(t_cor *cor, t_process *process)
{
	printf("pos = %d\n", process->pc);
	printf("%02x\n", cor->arena[process->pc]);
	printf("%s\n", "add");
}

void comm_sub(t_cor *cor, t_process *process)
{
	printf("pos = %d\n", process->pc);
	printf("%02x\n", cor->arena[process->pc]);
	printf("%s\n", "sub");	
}

void comm_and(t_cor *cor, t_process *process)
{
	printf("pos = %d\n", process->pc);
	printf("%02x\n", cor->arena[process->pc]);
	printf("%s\n", "and");	
}


void comm_next(t_cor *cor, t_process *process)
{
	printf("pos = %d\n", process->pc);
	 process->pc++;
	printf("%02x\n", cor->arena[process->pc]);
	printf("%s\n", "aff");
}