#include "vm.h"

int arg_read(t_cor *cor, t_process *process)
{
	short ind;
	int s;
	unsigned char *tmp;

	s = 1;
	if(process->arg1 == 1)
		process->arg1 = cor->arena[process->pc + s++];
	else
		return(0);
	if(process->arg2 == 1)
	{
		process->arg2 = (short)process->registr[cor->arena[process->pc + s] - 1];
		s++;
	}
	else if(process->arg2 == 2)
	{
		tmp = (unsigned char*)&process->arg2;
		tmp[1] = cor->arena[process->pc + s++];
		tmp[0] = cor->arena[process->pc + s++];
		process->arg2 = (short)process->arg2;
	}
	else if(process->arg2 == 3)
	{
		tmp = (unsigned char*)&ind;
		tmp[1] = cor->arena[process->pc + s];
		tmp[0] = cor->arena[process->pc + s];
		tmp = (unsigned char*)&process->arg2;
		tmp[3] = cor->arena[process->pc + ind];
		tmp[2] = cor->arena[process->pc + ind + 1];
		tmp[1] = cor->arena[process->pc + ind + 2];
		tmp[0] = cor->arena[process->pc + ind + 3];
		process->arg2 = (short)process->arg2;
		s += 2;
	}
	else
		return(0);
	if(process->arg3 == 1)
	{
		process->arg3 = (short)process->registr[cor->arena[process->pc + s] - 1];
		s++;
	}
	else if(process->arg3 == 2)
	{
		tmp = (unsigned char*)&process->arg3;
		tmp[1] = cor->arena[process->pc + s++];
		tmp[0] = cor->arena[process->pc + s++];
		process->arg3 = (short)process->arg3;
	}
	else
		return(0);

	printf("arg1 = %d\n", process->arg1);
	printf("arg2 = %d\n", process->arg2);
	printf("arg3 = %d\n", process->arg3);
	return(1);
}		

void comm_sti(t_cor *cor, t_process *process)
{
	if (process->delay == -1)
		process->delay = 24;
	else if (process->delay > 0)
		process->delay--;
	else if (process->delay == 0)
	{
		process->label = 2;
		arg_identify(process, cor->arena[process->pc + 1]);
		if(arg_read(cor, process))
			load_from_reg(cor, process, process->pc + ((process->arg2 + process->arg3) % IDX_MOD), process->arg1);
		// cor->arena[process->pc + 1]
		// if(cor->arena[process->pc + 1] == 144)
		// {
		// 	load_data_to_reg(cor, process, 4, process->pc + 6);
		// 	printf("aaaaaa = %d\n", process->registr[process->pc + 6]);
		// 	process->pc =  process->pc + 7;
		// }
		// printf("x = %02x\n", cor->arena[process->pc]);
	}
	// printf("pos = %d\n", process->pc);
	// printf("%02x\n", cor->arena[process->pc]);
	// printf("%s\n", "sti");
	// printf("registr[0] = %x\n", process->registr[0]);	
}
