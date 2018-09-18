#include "vm.h"

void print_proc(t_cor *cor)
{
	t_process *tmp;

	tmp = cor->process;
	while(tmp)
	{
		ft_printf("P % 5d is here and live == %d \n", tmp->count_num, tmp->live);
		tmp = tmp->next;
	}
}

void live_cheker(t_cor *cor)
{
	t_process *prev;
	t_process *tmp;
	int i;

	i = 0;
	if(cor->live_check == cor->curr_cycle_t_d)
	{
		tmp = cor->process;
		prev = NULL;
		if(tmp == NULL)
		{
			// ft_printf("list of proc is null ??? \n");
			if(cor->visu)
				if(cor->visu)
				gg_wp(cor);
			endwin();
			system("leaks -quiet corewar");
			exit(0);
		}
		i = 0;
		while(i < 4)// проверка на сумму криков жизнь процессов , порожденных 1 играком;
		{
			if(cor->player[i].live_curr >= NBR_LIVE)
			{
				cor->curr_cycle_t_d = cor->curr_cycle_t_d - CYCLE_DELTA;
				if(cor->visu == 0 && cor->dump == 0 && cor->s == 0 && (cor->mon == cor->cycles || cor->log == 1))
					ft_printf("Cycle to die is now %d\n", cor->curr_cycle_t_d);
				cor->curr_chechs = -1;
				cor->player[i].live_curr = 0;
				i = 0;
				while(i < 4)// обнуление всех крииков жизнь
				{
					cor->player[i].live_curr = 0;
					cor->player[i].live_summ = 0;
					i++;
				}
				break;
			}
			i++;
		}
		// Проверка всех процессов на "жизнь"
		// {{
		prev = NULL;
		while(tmp)
		{
			if(tmp->live == 0) // Если процесс не жив удаляем его из списка
			{
				if(prev == NULL) // Для случая , когда это первый елемент списка
				{
					tmp = cor->process->next;
					if(cor->visu == 1)
						cor->vizu->map[cor->process->pc].type = 0;
					free(cor->process);
					cor->process = tmp;
					if(!tmp) // Если это был единственный процесс 
					{
						if(cor->visu == 0)
							ft_printf("Contestant %d, \"%s\", has won !\n", cor->winner->num * (-1), cor->winner->prog_name);
						if(cor->visu)
							gg_wp(cor);
						endwin();
						system("leaks -quiet corewar");
						exit(0);
					}
					continue;
				}
				else
				{
					if(cor->cycles == 18576)
						ft_printf("live 5 %d\n", cor->process->live);
					prev->next = tmp->next;
					if(cor->visu == 1)
						cor->vizu->map[tmp->pc].type = 0;
					free(tmp);
					tmp = prev->next;
					continue;
				}
			}
			else
				tmp->live = 0;// Если процесс жив то жизнь тратится
			prev = tmp;
			if(tmp)
				tmp = tmp->next;
		}

		if(cor->cycles == 18576)
				print_proc(cor);
		if(!cor->process)
		{
			if(cor->visu == 0)
				ft_printf("Contestant %d, \"%s\", has won !\n", cor->winner->num * (-1), cor->winner->prog_name);
			if(cor->visu)
				gg_wp(cor);
			endwin();
			system("leaks -quiet corewar");
			exit(0);
		}
		// }}
		cor->curr_chechs++;
		if(cor->curr_chechs == MAX_CHECKS)
		{
			cor->curr_cycle_t_d = cor->curr_cycle_t_d - CYCLE_DELTA;
			if(cor->visu == 0 && cor->dump == 0 && cor->s == 0 && (cor->mon == cor->cycles || cor->log == 1))
				ft_printf("Cycle to die is now %d\n", cor->curr_cycle_t_d);
			cor->curr_chechs = 0;
		}
		cor->live_check = 1;
	}
	else
		cor->live_check++;
	if(cor->curr_cycle_t_d < 0)
	{
		if(cor->visu == 0)
			ft_printf("Contestant %d, \"%s\", has won !\n", cor->winner->num * (-1), cor->winner->prog_name);
		if(cor->visu)
				gg_wp(cor);
		endwin();
		system("leaks -quiet corewar");
		exit(0);
	}
}