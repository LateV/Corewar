/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:29:17 by oskulska          #+#    #+#             */
/*   Updated: 2017/10/28 19:29:30 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int index;
	int maxindex;

	index = 0;
	maxindex = ft_strlen(s1);
	while (s2[index] != '\0')
	{
		s1[maxindex] = s2[index];
		index++;
		maxindex++;
	}
	s1[maxindex] = '\0';
	return (s1);
}
