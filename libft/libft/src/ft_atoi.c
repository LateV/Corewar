/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:18:09 by vibondar          #+#    #+#             */
/*   Updated: 2017/10/30 18:18:14 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space_ch(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
		c == '\v' || c == '\f' || c == '\r');
}

int			ft_atoi(const char *str)
{
	unsigned long int	b;
	int					c;
	int					i;

	b = 0;
	c = 0;
	i = 0;
	while (ft_space_ch(str[i]))
		i++;
	if (str[i] == '-')
		c = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] != '\0') && ft_isdigit(str[i]))
	{
		if ((b > 922337203685477580 || (b == 922337203685477580
			&& (str[i] - '0') > 7)) && c == 0)
			return (-1);
		else if ((b > 922337203685477580 || (b == 922337203685477580
			&& (str[i] - '0') > 8)) && c == 1)
			return (0);
		b = (b * 10) + (str[i] - '0');
		i++;
	}
	return (c ? (int)-b : (int)b);
}
