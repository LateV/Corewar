/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:59:13 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/03/27 17:15:13 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_define_conversion(va_list *argptr, t_format *p, char str)
{
	int ret;

	ret = 0;
	if (str == 'D' || str == 'O' || str == 'U' || str == 'C' || str == 'S')
		p->length_l = 1;
	p->type = ft_loweret(str);
	(str == 'X') ? p->type = 'X' : 0;
	ret = ft_parse_conversions(p, argptr);
	return (ret);
}

void	ft_check_flags(t_format *p, char sym)
{
	sym == '#' ? p->flag_hash++ : 0;
	sym == '-' ? p->flag_minus++ : 0;
	sym == '+' ? p->flag_plus++ : 0;
	sym == ' ' ? p->flag_space++ : 0;
	sym == '0' ? p->flag_zero++ : 0;
	sym == 'h' ? p->length_h++ : 0;
	sym == 'l' ? p->length_l++ : 0;
	sym == 'j' ? p->length_j++ : 0;
	sym == 'z' ? p->length_z++ : 0;
}

void	ft_define_wp(t_format *p, char *str, int *pos)
{
	char	*tmp;
	int		len;
	int		flag;

	len = 0;
	flag = 0;
	if (str[len] == '.')
	{
		flag = 1;
		p->precision = 0;
		len++;
	}
	if (ft_isdigit(str[len]) != 1)
		return ;
	while (ft_isdigit(str[len]) == 1)
		len++;
	if (p->precision == 0)
		tmp = ft_strndup(str + 1, len - 1);
	else
		tmp = ft_strndup(str, len);
	*pos += len - 1;
	flag == 0 ? p->width = ft_atoi(tmp) : 0;
	flag == 1 ? p->precision = ft_atoi(tmp) : 0;
	free(tmp);
}

int		ft_not2(va_list *argptr, char **str, int *ret, t_format *p)
{
	int pos;

	pos = 0;
	while (*(*str + pos))
	{
		if (ft_strchr(FLAGS, *(*str + pos)) != NULL)
			ft_check_flags(p, *(*str + pos));
		if (ft_strchr(DIGITS, *(*str + pos)) != NULL && *(*str + pos) != '0')
			ft_define_wp(p, *str + pos, &pos);
		if (ft_strchr(CONV, *(*str + pos)) != NULL)
		{
			*ret += ft_define_conversion(argptr, p, *(*str + pos));
			break ;
		}
		if (ft_isascii(*(*str + pos)) != 0)
			if ((ft_strchr(FLAGS, *(*str + pos)) == NULL) &&
				(ft_strchr(DIGITS, *(*str + pos)) == NULL))
			{
				*ret += ft_manage_nonvalid(p, *(*str + pos));
				break ;
			}
		pos++;
	}
	return (pos);
}

int		ft_notion(va_list *argptr, char **str, int *ret)
{
	t_format	*p;
	int			pos;

	pos = 0;
	*str += 1;
	if (**str == '%')
	{
		ft_putchar('%');
		*ret += 1;
		return (0);
	}
	p = ft_creatstrctr();
	pos = ft_not2(argptr, str, ret, p);
	free(p);
	return (pos);
}
