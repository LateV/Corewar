/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:59:13 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/03/27 19:50:53 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_print_space_zero(t_format *p, int *ret)
{
	while (p->width-- > 0)
	{
		(p->flag_minus > 0) ? ft_putchar(' ') : ft_putchar('0');
		*ret += 1;
	}
}

void	ft_parse_width(t_format *p, int len_arg)
{
	if (p->precision - len_arg > 0)
		p->width = p->width - len_arg - (p->precision - len_arg);
	else if (p->precision - len_arg <= 0)
		p->width = p->width - len_arg;
	if ((p->flag_plus > 0 || p->flag_space > 0) &&
		(p->type == 'd' || p->type == 'i'))
		p->width--;
}
