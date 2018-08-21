/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:21:41 by vibondar          #+#    #+#             */
/*   Updated: 2017/10/26 11:21:43 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*i;
	size_t			j;

	i = (unsigned char *)b;
	j = 0;
	while (j < len)
	{
		i[j] = (unsigned char)c;
		j++;
	}
	return (b);
}
