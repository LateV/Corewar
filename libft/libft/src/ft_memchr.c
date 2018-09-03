/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 09:58:20 by vibondar          #+#    #+#             */
/*   Updated: 2017/10/27 09:58:21 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	p;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	p = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == p)
		{
			return (str + i);
		}
		i++;
	}
	return (NULL);
}
