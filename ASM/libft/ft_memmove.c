/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:46:19 by oskulska          #+#    #+#             */
/*   Updated: 2017/10/27 14:46:22 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ddst;
	unsigned char	*ssrc;
	size_t			i;

	i = 0;
	ssrc = (unsigned char*)src;
	ddst = (unsigned char*)dst;
	if (ddst <= ssrc)
	{
		while (len > i && ssrc)
		{
			ddst[i] = ssrc[i];
			i++;
		}
	}
	else
	{
		while (i != len && ddst)
		{
			ddst[len - 1 - i] = ssrc[len - 1 - i];
			i++;
		}
	}
	return (dst);
}
