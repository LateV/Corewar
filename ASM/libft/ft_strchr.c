/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:27:59 by oskulska          #+#    #+#             */
/*   Updated: 2017/11/02 17:24:27 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	a;
	int				pos;

	pos = 0;
	a = (unsigned char)c;
	while (s[pos] != c && s[pos] != '\0')
		pos++;
	if (s[pos] == c)
		return ((char*)&s[pos]);
	else
		return (NULL);
}
