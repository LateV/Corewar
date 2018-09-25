/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 16:37:03 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/25 16:37:04 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reverse_bits(void *a, size_t size)
{
	size_t	i;
	char	tmp;
	char	*bits;

	i = 0;
	if (!a)
		return ;
	bits = (char*)a;
	while (i != size - i)
	{
		tmp = bits[i];
		bits[i] = bits[size - 1 - i];
		bits[size - 1 - i] = tmp;
		i++;
	}
}
