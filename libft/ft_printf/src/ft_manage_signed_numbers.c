/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_signed_numbers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:59:44 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/03/27 20:02:15 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	void	parse_flags2(intmax_t arg, t_format *p, int *ret)
{
	if (p->flag_space > 0 && p->flag_plus < 1)
	{
		arg >= 0 ? ft_putchar(' ') : 0;
		arg >= 0 ? *ret += 1 : 0;
	}
	if (((p->flag_minus == 0 && p->flag_zero == 0) ||
		(p->flag_minus == 0 && p->precision > -1)) && p->width > 0)
		while (p->width-- > 0)
		{
			ft_putchar(' ');
			*ret += 1;
		}
	if (p->flag_plus > 0 || arg < 0)
	{
		(arg >= 0) ? ft_putchar('+') : ft_putchar('-');
		*ret += 1;
	}
}

static	void	parse_flags(intmax_t arg, t_format *p, int len_arg, int *ret)
{
	char		*str;

	parse_flags2(arg, p, ret);
	arg < 0 ? arg *= -1 : 0;
	str = ft_itoa_ubase(arg, 10);
	if (p->flag_minus > 0)
	{
		ft_parse_precision(p, len_arg, ret);
		ft_putstr(str);
	}
	ft_print_space_zero(p, ret);
	if (p->precision > -1 && arg == 0)
	{
		ft_parse_precision(p, len_arg, ret);
		return ;
	}
	ft_parse_precision(p, len_arg, ret);
	if (p->flag_minus < 1)
		ft_putstr(str);
	free(str);
}

int				ft_manage_signed_numbers(va_list *argptr, t_format *p)
{
	intmax_t	arg;
	size_t		len_arg;
	int			ret;

	ret = 0;
	arg = ft_parse_signed_length(p, argptr);
	len_arg = ft_len_num(arg);
	(arg < 0 && p->flag_plus < 1) ? p->width-- : 0;
	(arg == 0 && p->precision > -1) ? len_arg = 0 : 0;
	ft_parse_width(p, len_arg);
	parse_flags(arg, p, len_arg, &ret);
	ret += len_arg;
	return (ret);
}
