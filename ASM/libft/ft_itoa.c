/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:04:57 by oskulska          #+#    #+#             */
/*   Updated: 2017/11/07 17:01:23 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_intlen(int *n, int *m)
{
	int	len;

	len = 1;
	*m = *n;
	if (*n < 0)
	{
		*n = -*n;
		len++;
	}
	while (*n > 9)
	{
		*n /= 10;
		len++;
	}
	*n = *m < 0 ? -*m : *m;
	return (len);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				m;
	long int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(&n, &m);
	str = (char*)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	if (m < 0)
		str[0] = '-';
	str[len] = '\0';
	while (n > 9)
	{
		str[--len] = n % 10 + '0';
		n = n / 10;
	}
	str[len - 1] = n + '0';
	return (str);
}
