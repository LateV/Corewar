/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:27:59 by oskulska          #+#    #+#             */
/*   Updated: 2017/10/27 17:28:02 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*b;
	unsigned char	a;
	size_t			len;

	b = (char*)s;
	a = (unsigned char)c;
	len = ft_strlen(b);
	if (len == 0)
		return (NULL);
	while (b[len] != c && len > 0)
		len--;
	if (b[len] == c)
		return (&b[len]);
	else
		return (NULL);
}
