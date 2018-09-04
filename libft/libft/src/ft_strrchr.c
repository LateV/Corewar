/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 12:02:49 by vibondar          #+#    #+#             */
/*   Updated: 2017/11/01 12:02:51 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	*str;

	len = (int)ft_strlen((char*)s);
	str = (unsigned char*)s;
	while (len >= 0 || c == '\0')
	{
		if (str[len--] == c)
			return ((char *)&str[len + 1]);
	}
	return (0);
}
