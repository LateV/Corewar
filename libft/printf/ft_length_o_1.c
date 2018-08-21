/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_o_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:40:10 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:40:11 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_lengtho_nolen(t_printf **format, va_list argum, int base)
{
	unsigned int	out;
	char			*outc;

	out = va_arg(argum, unsigned int);
	outc = ft_itoa_base(out, base);
	(*format)->sign = 1;
	return (outc);
}

char	*ft_lengtho_j(t_printf **format, va_list argum, int base)
{
	uintmax_t		out;
	char			*outc;

	out = va_arg(argum, uintmax_t);
	outc = ft_itoa_base(out, base);
	(*format)->sign = 1;
	return (outc);
}

char	*ft_lengtho_z(t_printf **format, va_list argum, int base)
{
	size_t			out;
	char			*outc;

	out = va_arg(argum, size_t);
	outc = ft_itoa_base(out, base);
	(*format)->sign = 1;
	return (outc);
}
