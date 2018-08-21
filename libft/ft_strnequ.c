/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 16:08:15 by vibondar          #+#    #+#             */
/*   Updated: 2017/11/02 16:08:16 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (s1 && s2 && i < n)
	{
		if (s1[i] == s2[i])
		{
			if (i == n - 1)
				return (1);
		}
		else
			return (0);
		i++;
	}
	return (0);
}
