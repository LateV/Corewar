/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:51:34 by oskulska          #+#    #+#             */
/*   Updated: 2017/10/31 17:51:37 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str_sub;
	int		index;

	index = 0;
	if (s == NULL)
		return (NULL);
	str_sub = (char*)malloc(sizeof(char) * len + 1);
	if (str_sub == NULL)
		return (NULL);
	while (s[start] != '\0' && len > 0)
	{
		str_sub[index] = s[start];
		start++;
		index++;
		len--;
	}
	str_sub[index] = '\0';
	return (str_sub);
}
