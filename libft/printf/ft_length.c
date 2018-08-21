/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:40:21 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:40:23 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_length_h(t_printf **format, va_list argum)
{
	short		out;
	char		*outc;

	out = va_arg(argum, int);
	outc = ft_pitoa(out);
	if (out < 0)
		(*format)->sign = -1;
	else
		(*format)->sign = 1;
	return (outc);
}

char	*ft_length_hh(t_printf **format, va_list argum)
{
	char			out;
	char			*outc;

	out = va_arg(argum, int);
	outc = ft_pitoa(out);
	if (out < 0)
		(*format)->sign = -1;
	else
		(*format)->sign = 1;
	return (outc);
}

char	*ft_length_l(t_printf **format, va_list argum)
{
	long int		out;
	char			*outc;

	out = va_arg(argum, long int);
	outc = ft_pitoa(out);
	if (out < 0)
		(*format)->sign = -1;
	else
		(*format)->sign = 1;
	return (outc);
}

char	*ft_length_ll(t_printf **format, va_list argum)
{
	long long int	out;
	char			*outc;

	out = va_arg(argum, long long int);
	outc = ft_pitoa(out);
	if (out < 0)
		(*format)->sign = -1;
	else
		(*format)->sign = 1;
	return (outc);
}
