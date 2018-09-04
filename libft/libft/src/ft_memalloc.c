/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 13:15:37 by vibondar          #+#    #+#             */
/*   Updated: 2017/11/01 13:17:34 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *r;

	r = (unsigned char *)malloc(sizeof(char) * size);
	if (!r)
		return (NULL);
	ft_bzero(r, size);
	return ((void *)r);
}
