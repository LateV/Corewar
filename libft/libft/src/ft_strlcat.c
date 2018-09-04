/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:30:47 by vibondar          #+#    #+#             */
/*   Updated: 2017/10/27 14:30:48 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		a;
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	a = size - d_len;
	if (a <= 0)
		return (s_len + size);
	else
	{
		ft_strncat(dst, src, size - d_len - 1);
		return (s_len + d_len);
	}
}
