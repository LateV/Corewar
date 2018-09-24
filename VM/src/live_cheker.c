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

void wasted_live1(t_cor *cor)
{
	int i;

	i = 0;
	while(i < 4)
	{
		cor->player[i].live_curr = 0;
		cor->player[i].live_summ = 0;
		cor->player[i].all_cur = 0;
		i++;
	}
}

void end_game(t_cor *cor)
{
	if(cor->visu == 0)
		ft_printf("Contestant %d, \"%s\", has won !\n", cor->winner->num * (-1), cor->winner->prog_name);
	else
		gg_wp(cor);
	endwin();
	exit(0);
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
	wasted_live1(cor);
	end_game(cor);
}

void max_live(t_cor *cor)
{
	int i;

	i = 0;
	while(i < 4)
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
	while(i < 4)
	{
		cor->player[i].live_curr = 0;
		cor->player[i].live_summ = 0;
		cor->player[i].all_cur = 0;
		i++;
	}
}

void del_first(t_cor *cor)
{
	t_process *tmp;

	tmp = cor->process->next;
	free(cor->process);
	cor->process = tmp;
	if(!tmp)
		end_game(cor);
}

void wasted_live(t_cor *cor)
{
	t_process *tmp;

	tmp = cor->process;
	while(tmp)
	{
		tmp->live = 0;
		tmp = tmp->next;
	}
}

void search_and_delete(t_cor *cor)
{
	static t_process *prev = NULL;
	t_process *tmp;

	tmp = cor->process;
	while(tmp)
	{
		if(tmp->live == 0)
		{
			if(cor->visu == 1)
				cor->vizu->map[tmp->pc].type = 0;
			if(tmp == cor->process)
				del_first(cor);
			else
			{
				prev->next = tmp->next;
				free(tmp);
				tmp = prev->next;
			}
			tmp = cor->process;
			cor->alive_cur--;
			continue;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void live_cheker(t_cor *cor)
{
	if(cor->live_check == cor->curr_cycle_t_d)
	{
		max_live(cor);
		search_and_delete(cor);
		wasted_live(cor);
		if(!cor->process)
			end_game(cor);
		max_ch(cor);
		cor->live_check = 1;
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
	else
		cor->live_check++;
}