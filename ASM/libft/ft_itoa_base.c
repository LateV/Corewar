/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:16:34 by oskulska          #+#    #+#             */
/*   Updated: 2018/03/13 19:16:36 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_intlen(size_t *n, size_t *m, size_t base)
{
	int		len;

	len = 0;
	*m = *n;
	if (*n == 0)
		len = 1;
	while (*n != 0)
	{
		*n /= base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(size_t n, size_t base)
{
	char	*str;
	size_t	m;
	int		len;

	len = ft_intlen(&n, &m, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (m == 0)
		str[len - 1] = m + '0';
	while (m != 0)
	{
		if (base > 9)
		{
			if (m % base < 10)
				str[--len] = m % base + 48;
			else
				str[--len] = m % base + 55;
		}
		else
			str[--len] = m % base + '0';
		m = m / base;
	}
	return (str);
}
