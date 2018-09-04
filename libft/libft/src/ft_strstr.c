/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:41:16 by vibondar          #+#    #+#             */
/*   Updated: 2017/10/30 17:41:18 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)&haystack[i - j]);
	while (haystack[i])
	{
		if (haystack[i] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i - j]);
			j++;
		}
		else
		{
			i = i - j;
			j = 0;
		}
		i++;
	}
	return (0);
}
