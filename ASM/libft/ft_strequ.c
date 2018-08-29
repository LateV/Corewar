/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:37:11 by oskulska          #+#    #+#             */
/*   Updated: 2017/10/31 17:37:13 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int len1;
	int len2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (ft_strcmp(s1, s2) == 0)
		return (1);
	return (0);
}
