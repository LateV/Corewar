/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:44:32 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/20 20:44:35 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				get_reg(t_process *process, unsigned char reg)
{
	if (reg < 0 || reg > 15)
		return (0);
	return (process->registr[reg]);
}

char			get_char(t_cor *cor, int loc)
{
	while (loc >= MEM_SIZE)
		loc = loc - MEM_SIZE;
	while (loc < 0)
		loc = loc + MEM_SIZE;
	return (cor->arena[loc]);
}

short			get_short(t_cor *cor, int loc)
{
	int				i;
	unsigned char	*tmp;
	short			val;

	val = 0;
	i = 1;
	tmp = (unsigned char*)&val;
	while (i >= 0)
	{
		while (loc >= MEM_SIZE)
			loc = loc - MEM_SIZE;
		while (loc < 0)
			loc = loc + MEM_SIZE;
		tmp[i] = cor->arena[loc];
		i--;
		loc++;
	}
	return (val);
}

int				get_int(t_cor *cor, int loc)
{
	int				i;
	unsigned char	*tmp;
	int				val;

	val = 0;
	i = 3;
	tmp = (unsigned char*)&val;
	while (i >= 0)
	{
		while (loc >= MEM_SIZE)
			loc = loc - MEM_SIZE;
		while (loc < 0)
			loc = loc + MEM_SIZE;
		tmp[i] = cor->arena[loc];
		i--;
		loc++;
	}
	return (val);
}
