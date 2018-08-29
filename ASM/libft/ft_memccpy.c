/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 12:38:36 by oskulska          #+#    #+#             */
/*   Updated: 2017/10/27 12:38:39 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*b;
	unsigned char	*s;
	size_t			i;

	b = (unsigned char*)dst;
	s = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		b[i] = s[i];
		if (s[i] == (unsigned char)c)
		{
			return (b + i + 1);
		}
		i++;
	}
	return (NULL);
}
