/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:40:07 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/25 15:40:23 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_process				*player_b(t_cor *cor, t_player *player, int k)
{
	t_process *new;

	new = ft_memalloc(sizeof(t_process));
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
	new->count_num = cor->proc_num;
	cor->proc_num++;
	cor->alive_cur++;
	cor->winner = &player[k];
	return (new);
}
