/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:22:22 by oskulska          #+#    #+#             */
/*   Updated: 2017/10/26 17:26:10 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*b;
	unsigned char	*s;
	size_t			i;

	i = 0;
	b = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (dst == NULL && src == NULL && n)
		return (NULL);
	while (i < n)
	{
		b[i] = s[i];
		i++;
	}
	return (dst);
}
