#include "vm.h"

void init_comand_function(t_cor *cor)
{
	cor->instruct[0] = comm_live;
	cor->instruct[1] = comm_ld;
	cor->instruct[2] = comm_st;
	cor->instruct[3] = comm_add;
	cor->instruct[4] = comm_sub;
	cor->instruct[5] = comm_and_or_xor;
	cor->instruct[6] = comm_and_or_xor;
	cor->instruct[7] = comm_and_or_xor;
	cor->instruct[8] = comm_zjmp;
	cor->instruct[9] = comm_ldi;
	cor->instruct[10] = comm_sti;
	cor->instruct[11] = comm_fork;
	cor->instruct[12] = comm_lld;
	cor->instruct[13] = comm_lldi;
	cor->instruct[14] = comm_lfork;
	cor->instruct[15] = comm_aff;
	cor->instruct[16] = comm_next;
}