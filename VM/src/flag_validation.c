/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:42:53 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/20 20:42:54 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline static void		ft_while_and_if(t_cor *cor, char *flag, char *value)
{
	int					i;

	i = 0;
	while (value[i] != '\0')
	{
		if (!ft_isdigit(value[i]))
		{
			ft_printf("Invalid format in flag ");
			ft_error(cor, flag);
		}
		i++;
	}
	if (i > 11)
	{
		ft_printf("Invalid format (overflow int) in flag ");
		ft_error(cor, flag);
	}
}

int						val_int(t_cor *cor, char *flag, char *value)
{
	unsigned long int	b;
	int					i;

	b = 0;
	i = 0;
	ft_while_and_if(cor, flag, value);
	if (value[i] == '-')
	{
		ft_printf("Value can not be negative in flag ");
		ft_error(cor, flag);
	}
	if (value[i] == '+' || value[i] == '-')
		i++;
	while (value[i] != '\0')
	{
		b = (b * 10) + (value[i] - '0');
		i++;
	}
	if (b > 2147483647)
	{
		ft_printf("Invalid format (over int value) in flag ");
		ft_error(cor, flag);
	}
	return ((int)b);
}
