/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_pointers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:59:28 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/03/27 20:03:36 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	void	parse_flags2(t_format *p, int *ret)
{
	if (((p->flag_minus == 0 && p->flag_zero == 0) ||
		(p->flag_minus == 0 && p->precision > -1)) && p->width > 0)
		while (p->width-- > 0)
		{
			ft_putchar(' ');
			*ret += 1;
		}
	if (p->flag_hash > 0)
	{
		ft_putchar('0');
		ft_putchar('x');
	}
}

static	void	parse_flags(char *str, t_format *p, int len_arg, int *ret)
{
	parse_flags2(p, ret);
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
	if (p->flag_minus < 1 && len_arg != 0)
		ft_putstr(str);
}

int				ft_manage_pointers(va_list *argptr, t_format *p)
{
	uintmax_t	arg;
	size_t		len_arg;
	int			ret;
	char		*str;

	ret = 0;
	arg = va_arg(*argptr, uintmax_t);
	str = ft_itoa_ubase(arg, 16);
	len_arg = ft_strlen(str);
	(arg == 0 && p->precision == 0) ? len_arg = 0 : 0;
	p->flag_hash = 1;
	ret += len_arg + 2;
	p->width -= 2;
	ft_parse_width(p, len_arg);
	parse_flags(str, p, len_arg, &ret);
	free(str);
	return (ret);
}
