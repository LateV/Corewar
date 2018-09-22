/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flags2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:45:44 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/20 20:45:45 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		simple_flag(int i, int *flag)
{
	*flag = 1;
	return (i);
}

int		flag_force(t_cor *cor, char **argv, int i)
{
	int	num;

	if (argv[i + 1] == NULL)
		ft_error(cor, "Invalid format in flag -force");
	num = val_int(cor, argv[i], argv[i + 1]);
	cor->start_from = num;
	return (i + 1);
}
