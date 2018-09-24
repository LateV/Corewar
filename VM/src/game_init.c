/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:44:23 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/20 20:44:25 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	add_player(t_cor *cor, t_player *player, int k)
{
	t_process	*tmp;
	t_process	*new;

	tmp = cor->process;
	if (!tmp)
	{
		cor->process = ft_memalloc(sizeof(t_process));
		cor->process->next = NULL;
		cor->process->player = (player + k);
		cor->process->delay = -1;
		cor->process->player->num = cor->process->player->num * (-1);
		cor->process->registr[0] = cor->process->player->num;
		cor->process->player->live_summ = 0;
		cor->process->player->live_curr = 0;
		cor->process->player->last_live = 0;
		cor->process->player->all_cur = 0;
		cor->process->command = -1;
		cor->process->carry = 0;
		cor->process->live = 0;
		cor->alive_cur++;
		cor->process->count_num = cor->proc_num;
		cor->proc_num++;
		cor->winner = (player + k);
		draw_palyer_info(cor, cor->process, k);
		return ;
	}
	new = ft_memalloc(sizeof(t_process));
	new->next = cor->process;
	new->player = &player[k];
	new->delay = -1;
	new->player->num = new->player->num * (-1);
	new->registr[0] = new->player->num;
	new->player->live_summ = 0;
	new->player->live_curr = 0;
	new->player->last_live = 0;
	new->player->all_cur = 0;
	new->live = 0;
	new->command = -1;
	new->carry = 0;
	cor->process = new;
	cor->alive_cur++;
	new->count_num = cor->proc_num;
	cor->proc_num++;
	cor->winner = &player[k];
	draw_palyer_info(cor, new, k);
}

void	add_players(t_cor *cor)
{
	int k;

	k = 0;
	cor->def_num = 1;
	while (cor->def_num < 5)
	{
		while (k < cor->p_num)
		{
			if (cor->def_num == cor->player[k].num)
			{
				add_player(cor, cor->player, k);
				break ;
			}
			k++;
		}
		k = 0;
		cor->def_num++;
	}
}

void	data_to_arena(t_cor *cor, int pos, t_process *proc, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		cor->arena[pos + i] = proc->player->code[i];
		if (cor->visu == 1)
		{
			cor->vizu->map[pos + i].comm = proc->player->code[i];
			cor->vizu->map[pos + i].player = proc->player->num * (-1);
		}
		i++;
	}
	if (cor->visu == 1)
		cor->vizu->map[pos].type = 1;
}

void	game_init(t_cor *cor)
{
	int			pos;
	int			num_pl;
	t_process	*tmp;

	pos = 0;
	num_pl = -1;
	tmp = cor->process;
	if (cor->visu == 0)
		ft_putstr("Introducing contestants...\n");
	while (num_pl > -5)
	{
		tmp = cor->process;
		while (tmp)
		{
			if (num_pl == tmp->player->num)
			{
				data_to_arena(cor, pos, tmp, tmp->player->prog_size);
				if (cor->visu == 0)
					ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", tmp->player->num * (-1), tmp->player->prog_size, tmp->player->prog_name, tmp->player->comment);
				tmp->pc = pos;
				pos += MEM_SIZE / cor->p_num;
			}
			tmp = tmp->next;
		}
		num_pl--;
	}
}
