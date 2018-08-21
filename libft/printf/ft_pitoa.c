/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:24:16 by vibondar          #+#    #+#             */
/*   Updated: 2017/11/07 19:31:46 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_size(int n)
{
	int i;

	i = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

static char	*neg_int(uintmax_t nu, int size, uintmax_t a)
{
	char	*r;
	int		i;

	i = 0;
	if ((r = (char *)ft_memalloc(sizeof(char) * (size + 2))))
	{
		r[i++] = '-';
		while (nu / (10 * a) >= 1 && a != 1000000000000000000)
			a = a * 10;
		while (a >= 1)
		{
			r[i++] = '0' + nu / a;
			nu = nu % a;
			a = a / 10;
		}
		r[i] = '\0';
		return (r);
	}
	return (NULL);
}

static char	*pos_int(uintmax_t nu, int size, uintmax_t a)
{
	char	*r;
	int		i;

	i = 0;
	if ((r = (char *)ft_memalloc(sizeof(char) * (size + 1))))
	{
		while (nu / (10 * a) >= 1 && a != 1000000000000000000)
			a = a * 10;
		while (a >= 1)
		{
			r[i++] = '0' + nu / a;
			nu = nu % a;
			a = a / 10;
		}
		r[i] = '\0';
		return (r);
	}
	return (NULL);
}

char		*ft_pitoa(intmax_t n)
{
	uintmax_t k;

	if (n < 0)
	{
		k = n * -1;
		return (neg_int(k, ft_size(k), 1));
	}
	else
	{
		k = n;
		return (pos_int(k, ft_size(k), 1));
	}
}
