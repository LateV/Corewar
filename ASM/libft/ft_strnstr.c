/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:56:31 by oskulska          #+#    #+#             */
/*   Updated: 2017/11/10 17:47:21 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	l = 0;
	if (needle[l] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0' && len > 0)
	{
		j = i;
		l = len;
		k = 0;
		while (needle[k] != '\0' && haystack[j] == needle[k] && l-- > 0)
		{
			k++;
			j++;
		}
		if (k > 0 && needle[k] == '\0')
			return ((char*)&haystack[i]);
		len--;
		i++;
	}
	return (NULL);
}
