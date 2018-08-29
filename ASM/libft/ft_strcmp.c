/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:46:52 by oskulska          #+#    #+#             */
/*   Updated: 2017/10/24 17:25:38 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	if (*str1 == '\0')
		return (-*str2);
	if (*str2 == '\0')
		return (*str1);
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (ft_strlen(s1) < ft_strlen(s2))
		return (*str1 - *str2);
	if (ft_strlen(s1) > ft_strlen(s2))
		return (*str1 - *str2);
	return (0);
}
