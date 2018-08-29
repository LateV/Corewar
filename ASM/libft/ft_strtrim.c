/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:29:35 by oskulska          #+#    #+#             */
/*   Updated: 2017/11/01 16:29:37 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_sub_string(char const *str1, int l, int i)
{
	char	*str2;
	int		index;

	index = 0;
	str2 = ft_strnew(l);
	if (str2 == NULL)
		return (NULL);
	while (index < l)
		str2[index++] = str1[i++];
	str2[index] = '\0';
	return (str2);
}

char			*ft_strtrim(char const *str1)
{
	int		i;
	int		l;
	char	*str2;

	i = 0;
	if (str1 == NULL)
		return (NULL);
	l = ft_strlen(str1);
	while (str1[i] == ' ' || str1[i] == '\t' || str1[i] == '\n')
		i++;
	if (l == i || l < 0)
	{
		str2 = ft_strnew(0);
		return ((char*)str2);
	}
	while (str1[l - 1] == ' ' || str1[l - 1] == '\t' || str1[l - 1] == '\n')
		l--;
	l = l - i;
	str2 = ft_sub_string(str1, l, i);
	if (str2 == NULL)
		return (NULL);
	return (str2);
}
