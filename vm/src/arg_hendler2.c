/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_hendler2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 18:28:15 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/22 18:28:18 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

// int t_dir(t_cor *cor, t_process *process, int *arg, int loc)
// {
// 	while(loc  >= MEM_SIZE)
// 		loc = loc  - MEM_SIZE;
// 	while(loc  < 0)
// 		loc = loc + MEM_SIZE;
// 	if(process->label == 2)
// 	{
// 		*arg = get_short(cor, loc);
// 		return (2);
// 	}
// 	else
// 	{
// 		*arg = get_int(cor, loc);
// 		return (4);
// 	}
// }

// int t_reg(t_cor *cor, int *arg, int loc)
// {
// 	while(loc  >= MEM_SIZE)
// 		loc = loc  - MEM_SIZE;
// 	while(loc  < 0)
// 		loc = loc + MEM_SIZE;
// 	*arg = get_int(cor, loc);
// 	return(4);
// }

// int t_ind(t_cor *cor, int *arg, int loc)
// {

// 	while (loc  >= MEM_SIZE)
// 		loc = loc  - MEM_SIZE;
// 	while (loc  < 0)
// 		loc = loc + MEM_SIZE;
// 	*arg = get_int(cor, loc);
// 	return (4);
// }
