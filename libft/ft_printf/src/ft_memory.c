/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:17:21 by oskulska          #+#    #+#             */
/*   Updated: 2017/11/14 18:17:22 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_memory(char *src)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	res = (char *)malloc(sizeof(*res) * (i + i / 2));
	while (j < i)
	{
		res[j] = src[j];
		j++;
	}
	return (res);
}
