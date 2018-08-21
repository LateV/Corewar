/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:12:14 by vibondar          #+#    #+#             */
/*   Updated: 2017/10/30 18:12:17 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (str1[i] == '\0' && str2[i] == '\0')
		return (0);
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
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
	return (0);
}
