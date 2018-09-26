/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usadge.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:46:21 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/20 20:46:22 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	usadge(char *name)
{
	ft_printf("Usage: %s [-dump N] [-s N] [-a] [-log] [-mon]\
[-v [-force --stealth]] <champion1.cor> <...> \n", name);
	ft_printf("~~~*** TEXT OUTPUT MODE MODE ***~~~~\n");
	ft_printf("-a      : Prints output from \"aff\" (Default is to hide it)\n");
	ft_printf("-dump N : Dumps memory after N cycles then exits\n");
	ft_printf("-s N    : Runs N cycles,dumps memory, pauses, then repeats\n");
	ft_printf("-log    : Show operations\n");
	ft_printf("-mon N  : Show operations on N-th cycle only\n");
	ft_printf("~~~*** NCURSES OUTPUT MODE ***~~~~\n");
	ft_printf("-v      : Ncurses output mode\n");
	ft_printf("--stealth: Hides the real contents of the memory\n");
	ft_printf("-force  : Start game from the N-th cycle\n");
	exit(0);
}
