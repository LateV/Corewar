/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:57:31 by oskulska          #+#    #+#             */
/*   Updated: 2018/03/13 10:57:37 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*pf_tolower(t_format *list, char *str)
{
	int			i;

	i = 0;
	if (list->spec == 'x' || list->spec == 'p')
	{
		while (str[i])
		{
			str[i] = ft_tolower(str[i]);
			i++;
		}
	}
	return (str);
}

int				pf_addpre(t_format *list, int k)
{
	if (list->hash && (list->spec == 'o' || list->spec == 'O')
		&& k == 0 && list->zero)
	{
		pf_putstr(list, "0");
		return (1);
	}
	if (list->spec == 'p' && !list->zero && list->widt < list->prs)
	{
		(list->spec == 'X') ? pf_putstr(list, "0X") : pf_putstr(list, "0x");
		return (1);
	}
	if (((list->spec == 'p' && list->zero) || (list->hash && k == 0 &&
		(list->spec == 'x' || list->spec == 'X'))) && list->zero)
	{
		(list->spec == 'X') ? pf_putstr(list, "0X") : pf_putstr(list, "0x");
		return (1);
	}
	return (0);
}

void			pf_addpost(t_format *list, int k)
{
	if (list->hash && (list->spec == 'o' || list->spec == 'O')
		&& k == 0 && !list->zero)
		pf_putstr(list, "0");
	if (list->spec == 'p' && !list->zero && list->prs <= 0)
		(list->spec == 'X') ? pf_putstr(list, "0X") : pf_putstr(list, "0x");
	if (((list->spec == 'p' && !list->zero) || (list->hash && k == 0
		&& (list->spec == 'x' || list->spec == 'X')))
		&& !list->zero && list->prs > 0)
		(list->spec == 'X') ? pf_putstr(list, "0X") : pf_putstr(list, "0x");
	if (((list->spec == 'x' || list->spec == 'X') && list->hash && k == 0)
		&& list->prs <= 0)
		(list->spec == 'X') ? pf_putstr(list, "0X") : pf_putstr(list, "0x");
}

static size_t	ft_itoa_len(ssize_t n)
{
	size_t		len;
	size_t		cpy;

	len = 1;
	cpy = n;
	if (n < 0)
	{
		cpy = -n;
		len++;
	}
	while (cpy > 9)
	{
		cpy /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoau(ssize_t n)
{
	char		*str;
	size_t		m;
	ssize_t		len;

	len = ft_itoa_len(n);
	str = (char*)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	m = n;
	if (n < 0)
	{
		m = -n;
		str[0] = '-';
	}
	str[len] = '\0';
	while (m > 9 && len > 0)
	{
		str[--len] = m % 10 + '0';
		m = m / 10;
	}
	str[len - 1] = m + '0';
	return (str);
}
