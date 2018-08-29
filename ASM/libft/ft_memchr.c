/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:27:59 by oskulska          #+#    #+#             */
/*   Updated: 2017/11/05 19:40:40 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*b;
	size_t			i;
	unsigned char	a;

	a = (unsigned char)c;
	b = (unsigned char*)s;
	i = 0;
	while (n > 0)
	{
		if (b[i] == a)
		{
			return ((void *)(s + i));
		}
		i++;
		n--;
	}
	return (NULL);
}
