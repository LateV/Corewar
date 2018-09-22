/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:59:13 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/03/27 19:11:41 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_parse_conversions(t_format *p, va_list *argptr)
{
	int	ret;

	ret = 1;
	if (p->type == 'd' || p->type == 'i')
		ret = ft_manage_signed_numbers(argptr, p);
	else if (p->type == 'o' || p->type == 'u' || p->type == 'x' ||
			p->type == 'X')
		ret = ft_manage_unsigned_numbers(argptr, p);
	else if (p->type == 'p')
		ret = ft_manage_pointers(argptr, p);
	else if (p->type == 'c' || p->type == '%')
		ret = ft_manage_chars(argptr, p);
	else if (p->type == 's')
		ret = ft_manage_strings(argptr, p);
	return (ret);
}
