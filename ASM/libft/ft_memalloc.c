/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:46:18 by oskulska          #+#    #+#             */
/*   Updated: 2017/10/30 18:46:21 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*buf;

	if (size > 0)
	{
		buf = (void*)malloc(sizeof(void) * size);
		if (buf == NULL)
			return (NULL);
		ft_bzero(buf, size);
		return (buf);
	}
	return (NULL);
}
