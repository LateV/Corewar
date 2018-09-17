/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:10:44 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/03/28 16:13:47 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			wstr_byte(wchar_t *str, t_format *p)
{
	int			len;
	int			res;
	int			byt;

	len = 0;
	res = 0;
	while (*str && p->precision >= len)
	{
		byt = ft_bytelen(*str++);
		if (len + byt <= p->precision)
		{
			len += byt;
			res++;
		}
	}
	p->width -= len;
	p->precision = res;
}

int				binary_size(unsigned int value)
{
	int			len;
	int			size;

	len = 0;
	size = 0;
	if (value == 0)
		len++;
	while (value != 0)
	{
		value = value / 2;
		len++;
	}
	if (len <= 7)
		size = 1;
	else if (len <= 11)
		size = 2;
	else if (len <= 16)
		size = 3;
	else
		size = 4;
	return (size);
}

int				ft_putwchar(wchar_t smb)
{
	int			size;

	size = binary_size(smb);
	if (size == 2 && MB_CUR_MAX > 1)
	{
		ft_putchar((smb >> 6) + 0b11000000);
		ft_putchar((smb & 0b111111) + 0b10000000);
	}
	else if (size == 3 && MB_CUR_MAX > 1)
	{
		ft_putchar((smb >> 12) + 0b11100000);
		ft_putchar(((smb >> 6) & 0b111111) + 0b10000000);
		ft_putchar((smb & 0b111111) + 0b10000000);
	}
	else if (size == 4 && MB_CUR_MAX > 1)
	{
		ft_putchar((smb >> 18) + 0b11110000);
		ft_putchar(((smb >> 12) & 0b111111) + 0b10000000);
		ft_putchar(((smb >> 6) & 0b111111) + 0b10000000);
		ft_putchar((smb & 0b111111) + 0b10000000);
	}
	else
		ft_putchar(smb);
	return (size);
}

int				ft_putwstr(wchar_t *s)
{
	size_t		i;
	int			ret;

	i = 0;
	ret = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			ret += ft_putwchar(s[i]);
			i++;
		}
	}
	return (ret);
}
