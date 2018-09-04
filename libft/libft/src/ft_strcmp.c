/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:08:06 by vibondar          #+#    #+#             */
/*   Updated: 2017/10/30 18:08:11 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (str1[i] == '\0' && str2[i] == '\0')
		return (0);
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] == str2[i])
		{
			if (str1[i + 1] == '\0' && str2[i + 1] == '\0')
				return (0);
		}
		else
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}
