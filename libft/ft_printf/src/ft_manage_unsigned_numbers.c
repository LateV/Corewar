/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:59:13 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/03/27 20:01:00 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	void	parse_flags2(char *str, t_format *p, int len_arg, int *ret)
{
	ft_parse_width(p, len_arg);
	if (((p->flag_minus == 0 && p->flag_zero == 0) ||
		(p->flag_minus == 0 && p->precision > -1)) && p->width > 0)
		while (p->width-- > 0)
		{
			ft_putchar(' ');
			*ret += 1;
		}
	if (p->flag_hash > 0)
	{
		if ((p->type == 'x' || p->type == 'X') && *str != '0')
		{
			ft_putchar('0');
			ft_putchar(p->type == 'x' ? 'x' : 'X');
		}
		else if (p->type == 'o' && *str == '0' && p->precision == -1)
			*ret -= 1;
		else if (p->type == 'o')
			ft_putchar('0');
		(p->type == 'x' || p->type == 'X') ?
		ft_parse_precision(p, len_arg - 2, ret) : 0;
		(p->type == 'o') ? ft_parse_precision(p, len_arg, ret) : 0;
	}
}

static	void	parse_flags(char *str, t_format *p, int len_arg, int *ret)
{
	(*str == '0' && p->precision == 0) ? len_arg -= 1 : 0;
	parse_flags2(str, p, len_arg, ret);
	ft_parse_precision(p, len_arg, ret);
	if (p->flag_minus > 0 || p->flag_zero > 0)
	{
		if (p->flag_minus > 0 && p->precision != 0)
			ft_putstr(str);
		while (p->width-- > 0)
		{
			(p->flag_minus > 0 || p->precision > -1) ?
			ft_putchar(' ') : ft_putchar('0');
			*ret += 1;
		}
	}
	if (*str == '0' && p->precision == 0)
	{
		*ret -= 1;
		return ;
	}
	if (p->flag_minus < 1)
		ft_putstr(str);
}

int				ft_manage_unsigned_numbers(va_list *argptr, t_format *p)
{
	uintmax_t	arg;
	int			len_arg;
	int			base;
	char		*str;

	base = 0;
	arg = ft_parse_unsigned_length(p, argptr);
	if (p->type == 'o')
		base = 8;
	else if (p->type == 'x' || p->type == 'X')
		base = 16;
	else if (p->type == 'u')
		base = 10;
	str = ft_itoa_ubase(arg, base);
	if (p->type == 'X')
		ft_uppercase(&str);
	len_arg = ft_strlen(str);
	if (p->flag_hash > 0 && *str != '0' && (p->type == 'x' || p->type == 'X'))
		len_arg += 2;
	else if (p->flag_hash > 0 && p->type == 'o')
		len_arg += 1;
	base = len_arg;
	parse_flags(str, p, len_arg, &base);
	free(str);
	return (base);
}
