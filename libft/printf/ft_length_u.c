/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:39:54 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:39:55 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_lengthu_h(t_printf **format, va_list argum)
{
	unsigned short			out;
	char					*outc;

	out = va_arg(argum, int);
	outc = ft_itoa_base(out, 10);
	if (out < 0)
		(*format)->sign = -1;
	else
		(*format)->sign = 1;
	return (outc);
}

char	*ft_lengthu_hh(t_printf **format, va_list argum)
{
	unsigned char			out;
	char					*outc;

	out = va_arg(argum, int);
	outc = ft_itoa_base(out, 10);
	if (out < 0)
		(*format)->sign = -1;
	else
		(*format)->sign = 1;
	return (outc);
}

char	*ft_lengthu_l(t_printf **format, va_list argum)
{
	unsigned long int		out;
	char					*outc;

	out = va_arg(argum, unsigned long int);
	outc = ft_itoa_base(out, 10);
	(*format)->sign = 1;
	return (outc);
}

char	*ft_lengthu_ll(t_printf **format, va_list argum)
{
	unsigned long long int	out;
	char					*outc;

	out = va_arg(argum, unsigned long long int);
	outc = ft_itoa_base(out, 10);
	(*format)->sign = 1;
	return (outc);
}
