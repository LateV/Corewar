/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:44:18 by oskulska          #+#    #+#             */
/*   Updated: 2017/10/31 17:44:21 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int len1;
	int len2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (ft_strncmp(s1, s2, n) == 0)
		return (1);
	return (0);
}
