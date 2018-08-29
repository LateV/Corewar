/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:44:56 by oskulska          #+#    #+#             */
/*   Updated: 2017/10/28 19:46:18 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int index;
	int maxindex;

	index = 0;
	maxindex = ft_strlen(s1);
	while (s2[index] != '\0' && n > 0)
	{
		s1[maxindex] = s2[index];
		index++;
		maxindex++;
		n--;
	}
	s1[maxindex] = '\0';
	return (s1);
}
