#include "vm.h"

void game(t_cor *cor)
{
	t_process *tmp;

	cor->cycles = 1;
	cor->start_from = 0;
	// cor->start_from = 0;
	while(69)
	{
		if(cor->visu == 1)
		{
			cor->vizu->key = getch();
			v_speed_test(cor, cor->vizu->key);

			if (cor->vizu->key == 32 && cor->pause == 1)
				cor->pause = 0;
			else if (cor->vizu->key == 32 && cor->pause == 0)
				cor->pause = 1;
			if (cor->cycles > cor->start_from)
			{
				refresh_vizu(cor);
				if (cor->pause == 1 && cor->vizu->key != 10)
					continue;
			}
		}
		else
		{
			if(cor->visu == 0)
				ft_printf("It is now cycle %d\n", cor->cycles);
		}
		// dump_mem();
		tmp = cor->process;
		while(tmp)
		{
			// if(cor->cycles == 8920)
			// {
			// 	// if(tmp->count_num == 213)
			// 	// {
			// 		ft_printf("p_n = %d\n pc = %d\n command = %d\n delay = %d\n", tmp->count_num, tmp->pc, tmp->command, tmp->delay);
			// 		print_map(cor);
			// 	// }
			// }
			if(tmp->command == -1)
			{
				if(cor->arena[tmp->pc] > 0 && cor->arena[tmp->pc] < 17)
				{
					tmp->command = cor->arena[tmp->pc] - 1;
					cor->instruct[tmp->command](cor, tmp);
				}
				else
					set_proc_pos(cor, tmp, 1);
			}
			else
				cor->instruct[tmp->command](cor, tmp);
			tmp = tmp->next;
		}
		cor->cycles++;
		live_cheker(cor);
	}
}