/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:40:05 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:40:06 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_lengtho_h(t_printf **format, va_list argum, int base)
{
	unsigned short			out;
	char					*outc;

	out = va_arg(argum, unsigned int);
	outc = ft_itoa_base(out, base);
	(*format)->sign = 1;
	return (outc);
}

char	*ft_lengtho_hh(t_printf **format, va_list argum, int base)
{
	unsigned char			out;
	char					*outc;

	out = va_arg(argum, unsigned int);
	outc = ft_itoa_base(out, base);
	(*format)->sign = 1;
	return (outc);
}

char	*ft_lengtho_l(t_printf **format, va_list argum, int base)
{
	unsigned long int		out;
	char					*outc;

	out = va_arg(argum, unsigned long int);
	outc = ft_itoa_base(out, base);
	(*format)->sign = 1;
	return (outc);
}

char	*ft_lengtho_ll(t_printf **format, va_list argum, int base)
{
	unsigned long long int	out;
	char					*outc;

	out = va_arg(argum, unsigned long long int);
	outc = ft_itoa_base(out, base);
	(*format)->sign = 1;
	return (outc);
}
