/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:54:48 by oskulska          #+#    #+#             */
/*   Updated: 2017/11/06 14:00:52 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	j = 0;
	if (needle[k] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		j = i;
		k = 0;
		while (needle[k] != '\0' && haystack[j] == needle[k])
		{
			k++;
			j++;
		}
		if (k > 0 && needle[k] == '\0')
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
