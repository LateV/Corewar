/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:40:27 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:40:29 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_length_nolen(t_printf **format, va_list argum)
{
	int			out;
	char		*outc;

	out = va_arg(argum, int);
	outc = ft_pitoa(out);
	if (out < 0)
		(*format)->sign = -1;
	else
		(*format)->sign = 1;
	return (outc);
}

char	*ft_length_j(t_printf **format, va_list argum)
{
	intmax_t	out;
	char		*outc;

	out = va_arg(argum, intmax_t);
	outc = ft_pitoa(out);
	if (out < 0)
		(*format)->sign = -1;
	else
		(*format)->sign = 1;
	return (outc);
}

char	*ft_length_z(t_printf **format, va_list argum)
{
	size_t		out;
	char		*outc;

	out = va_arg(argum, size_t);
	outc = ft_pitoa(out);
	outc = ft_pitoa(out);
	(*format)->sign = 1;
	return (outc);
}
