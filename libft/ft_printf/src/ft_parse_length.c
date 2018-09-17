/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:59:13 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/03/27 19:10:17 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

intmax_t		ft_parse_signed_length(t_format *p, va_list *argptr)
{
	intmax_t	arg;

	if (p->length_z == 1)
		arg = va_arg(*argptr, ssize_t);
	else if (p->length_j == 1)
		arg = va_arg(*argptr, intmax_t);
	else if (p->length_l > 1)
		arg = va_arg(*argptr, long long);
	else if (p->length_l == 1)
		arg = va_arg(*argptr, long);
	else if (p->length_h == 1)
		arg = (short int)va_arg(*argptr, int);
	else if (p->length_h > 1)
		arg = (signed char)va_arg(*argptr, int);
	else
		arg = va_arg(*argptr, int);
	return (arg);
}

uintmax_t		ft_parse_unsigned_length(t_format *p, va_list *argptr)
{
	uintmax_t	arg;

	if (p->length_z == 1)
		arg = va_arg(*argptr, size_t);
	else if (p->length_j == 1)
		arg = va_arg(*argptr, uintmax_t);
	else if (p->length_l > 1)
		arg = va_arg(*argptr, unsigned long long);
	else if (p->length_l == 1)
		arg = va_arg(*argptr, unsigned long);
	else if (p->length_h == 1)
		arg = (unsigned short)va_arg(*argptr, int);
	else if (p->length_h > 1)
		arg = (unsigned char)va_arg(*argptr, int);
	else
		arg = va_arg(*argptr, unsigned int);
	return (arg);
}

wint_t			ft_parse_chars_length(t_format *p, va_list *argptr)
{
	wint_t		arg;

	if (p->length_l == 1)
		arg = va_arg(*argptr, wint_t);
	else
		arg = va_arg(*argptr, int);
	return (arg);
}
