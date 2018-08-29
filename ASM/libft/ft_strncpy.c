/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:09:58 by oskulska          #+#    #+#             */
/*   Updated: 2017/10/28 17:10:08 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	index;

	index = 0;
	while (src[index] != '\0' && len > 0)
	{
		dst[index] = src[index];
		index++;
		len--;
	}
	while (len > 0)
	{
		dst[index] = '\0';
		len--;
		index++;
	}
	return (dst);
}
