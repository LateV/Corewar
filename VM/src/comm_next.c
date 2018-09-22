/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:41:57 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/20 20:41:58 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void comm_next(t_cor *cor, t_process *process)
{
	set_proc_pos(cor, process, 1);
	process->delay = -1;
	process->codage = 1;
	process->command = -1;
}
