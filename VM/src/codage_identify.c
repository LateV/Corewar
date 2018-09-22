/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codage_identify.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:40:20 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/20 20:40:22 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void codage_identify(t_process *process, unsigned char args)
{
	if((args & 192) == 64)
		process->arg1 = 1;
	else if((args & 192) == 192)
		process->arg1 = 3;
	else if((args & 192) == 128)
		process->arg1 = 2;
	else
		process->arg1 = 0;
	if((args & 48) == 32)
		process->arg2 = 2;
	else if((args & 48) == 48)
		process->arg2 = 3;
	else if((args & 48) == 16)
		process->arg2 = 1;
	else
		process->arg2 = 0;
	if((args & 12) == 8)
		process->arg3 = 2;
	else if((args & 12) == 12)
		process->arg3 = 3;
	else if((args & 12) == 4)
		process->arg3 = 1;
	else
		process->arg3 = 0;
}
