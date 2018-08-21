/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 12:23:25 by vibondar          #+#    #+#             */
/*   Updated: 2017/11/03 12:23:27 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned char	*r;

	i = 0;
	r = (unsigned char *)ft_memalloc(sizeof(unsigned char) * (len + 1));
	if (!r)
		return (0);
	while (s && i <= len)
	{
		if (i == len)
		{
			r[i] = '\0';
			return ((char *)r);
		}
		r[i] = s[start + i];
		i++;
	}
	return (0);
}
