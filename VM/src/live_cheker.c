/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_cheker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:44:56 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/20 20:44:58 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void max_ch(t_cor *cor)
{
	cor->curr_chechs++;
	if(cor->curr_chechs == MAX_CHECKS)
	{
		cor->curr_cycle_t_d = cor->curr_cycle_t_d - CYCLE_DELTA;
		if(cor->visu == 0 && cor->dump == 0 && cor->s == 0 && (cor->mon == cor->cycles || cor->log == 1))
			ft_printf("Cycle to die is now %d\n", cor->curr_cycle_t_d);
		cor->curr_chechs = 0;
	}
}

void cycle_end(t_cor *cor)
{

	if(cor->visu == 1)
	{
		cor->vizu->key = getch();
		v_speed_test(cor, cor->vizu->key);
		breakdown(cor);
		refresher(cor);
		if (cor->vizu->key == 32 && cor->pause == 1)
			cor->pause = 0;
		else if (cor->vizu->key == 32 && cor->pause == 0)
			cor->pause = 1;
		if (cor->cycles > cor->start_from)
			refresh_vizu(cor);
	}
	if(cor->visu == 0)
		ft_printf("Contestant %d, \"%s\", has won !\n", cor->winner->num * (-1), cor->winner->prog_name);
	if(cor->visu)
			gg_wp(cor);
	endwin();
	system("leaks -quiet corewar");
	exit(0);
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
		i = 0;
		while(i < 4)// проверка на сумму криков жизнь процессов , порожденных 1 играком;
		{
			if(cor->player[i].all_cur >= NBR_LIVE)
			{
				cor->curr_cycle_t_d = cor->curr_cycle_t_d - CYCLE_DELTA;
				if(cor->visu == 0 && cor->dump == 0 && cor->s == 0 && (cor->mon == cor->cycles || cor->log == 1))
					ft_printf("Cycle to die is now %d\n", cor->curr_cycle_t_d);
				cor->curr_chechs = cor->curr_chechs - 1;
				break;
			}
			i++;
		}
		i = 0;
		while(i < 4)// обнуление всех крииков жизнь
		{
			cor->player[i].live_curr = 0;
			cor->player[i].live_summ = 0;
			cor->player[i].all_cur = 0;
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
					cor->alive_cur--;
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
					prev->next = tmp->next;
					if(cor->visu == 1)
						cor->vizu->map[tmp->pc].type = 0;
					free(tmp);
					cor->alive_cur--;
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
		max_ch(cor);
		cor->live_check = 1;
	}
	else
		cor->live_check++;
	if(cor->curr_cycle_t_d < 0)
	{
		cor->cycles++;
		if(cor->visu == 0 && cor->dump == 0 && cor->s == 0 && (cor->mon == cor->cycles || cor->log == 1))
				ft_printf("It is now cycle %d\n", cor->cycles);
		process_activity(cor);
		flag_output(cor);
		if(cor->cycles == cor->mon && cor->log == 0 && cor->visu == 0)
			exit(0);
		cycle_end(cor);
	}
}
