/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:59:13 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/03/27 19:58:12 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	void	parse_wflags2(wchar_t *str, t_format *p, int len_arg, int *ret)
{
	if (p->flag_minus > 0 || p->flag_zero > 0)
	{
		if (p->flag_minus > 0)
		{
			if (p->precision >= 0 && p->precision - len_arg < 0)
				while (p->precision-- > 0)
					ret += ft_putwchar(*str++);
			else
				*ret += ft_putwstr(str);
		}
		ft_print_space_zero(p, ret);
	}
}

static	void	parse_wflags(wchar_t *str, t_format *p, int len_arg, int *ret)
{
	if (p->precision >= 0 && p->precision - len_arg <= 0)
		wstr_byte(str, p);
	else
		p->width -= len_arg;
	if (p->flag_minus == 0 && p->flag_zero == 0 && p->width > 0)
	{
		while (p->width-- > 0)
		{
			ft_putchar(' ');
			*ret += 1;
		}
	}
	parse_wflags2(str, p, len_arg, ret);
	if (p->flag_minus < 1)
	{
		if (p->precision >= 0 && p->precision - len_arg < 0)
			while (p->precision-- > 0)
			{
				*ret += ft_putwchar(*str++);
			}
		else
			*ret += ft_putwstr(str);
	}
}

static	void	parse_flags2(char *str, t_format *p, int len_arg, int *ret)
{
	if (p->flag_minus > 0 || p->flag_zero > 0)
	{
		if (p->flag_minus > 0)
		{
			if (p->precision >= 0 && p->precision - len_arg < 0)
				while (p->precision-- > 0)
				{
					ft_putchar(*str++);
					*ret += 1;
				}
			else
			{
				ft_putstr(str);
				*ret += len_arg;
			}
		}
		ft_print_space_zero(p, ret);
	}
}

static	void	parse_flags(char *str, t_format *p, int len_arg, int *ret)
{
	if (p->precision - len_arg >= 0 || p->precision < 0)
		p->width = p->width - len_arg;
	else if (p->precision - len_arg < 0)
		p->width = p->width - p->precision;
	if (p->flag_minus == 0 && p->flag_zero == 0 && p->width > 0)
		while (p->width-- > 0)
		{
			ft_putchar(' ');
			*ret += 1;
		}
	parse_flags2(str, p, len_arg, ret);
	if (p->flag_minus < 1)
	{
		if (p->precision >= 0 && p->precision - len_arg < 0)
			while (p->precision-- > 0)
			{
				ft_putchar(*str++);
				*ret += 1;
			}
		else
		{
			ft_putstr(str);
			*ret += len_arg;
		}
	}
}

int				ft_manage_strings(va_list *argptr, t_format *p)
{
	char	*str;
	wchar_t	*wstr;
	int		len_str;
	int		len_wstr;
	int		ret;

	ret = 0;
	str = NULL;
	wstr = NULL;
	if (p->type == 's' && p->length_l == 0)
	{
		str = va_arg(*argptr, char *);
		str == NULL ? str = "(null)" : 0;
		len_str = ft_strlen(str);
		parse_flags(str, p, len_str, &ret);
	}
	else if (p->type == 's' && p->length_l > 0)
	{
		wstr = va_arg(*argptr, wchar_t*);
		wstr == NULL ? wstr = L"(null)" : 0;
		len_wstr = ft_wstrlen(wstr);
		parse_wflags(wstr, p, len_wstr, &ret);
	}
	return (ret);
}
