/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pput_wchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:20:04 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/25 16:20:07 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int		ft_put_wchar2(wchar_t c)
{
	if (c <= 65535)
	{
		ft_putchar((c >> 12) + 0b11100000);
		ft_putchar(((c >> 6) & 0b111111) + 0b10000000);
		ft_putchar((c & 0b111111) + 0b10000000);
		return (3);
	}
	else if (c <= 1114111)
	{
		ft_putchar((c >> 18) + 0b11110000);
		ft_putchar(((c >> 12) & 0b111111) + 0b10000000);
		ft_putchar(((c >> 6) & 0b111111) + 0b10000000);
		ft_putchar((c & 0b111111) + 0b10000000);
		return (4);
	}
	else
		return (0);
}

static void		ft_putik(t_printf **format, wchar_t c)
{
	char	*str;
	int		r;

	if ((*format)->flag[0] == '-')
	{
		r = ft_put_wchar(c);
		(*format)->num = (*format)->num + r;
		ft_putstr(str = ft_genchar(' ', (*format)->width - r));
		(*format)->num = (*format)->num + ft_strlen(str);
	}
	else
	{
		r = ft_wchar_len(c);
		if ((*format)->flag[4] == '0')
			ft_putstr(str = ft_genchar('0', (*format)->width - r));
		else
			ft_putstr(str = ft_genchar(' ', (*format)->width - r));
		(*format)->num = (*format)->num + ft_put_wchar(c);
		(*format)->num = (*format)->num + ft_strlen(str);
	}
	free(str);
}

int				ft_put_wchar(wchar_t c)
{
	if (c <= 127)
	{
		ft_putchar(c);
		return (1);
	}
	else if (c <= 2047)
	{
		ft_putchar((c >> 6) + 0b11000000);
		ft_putchar((c & 0b111111) + 0b10000000);
		return (2);
	}
	else
		return (ft_put_wchar2(c));
}

void			ft_pput_wchar(t_printf **format, va_list argum)
{
	wchar_t	c;

	c = va_arg(argum, wchar_t);
	if ((*format)->width < 0)
		(*format)->width = 0;
	(*format)->num = (*format)->num + ft_strlen((*format)->buf);
	write(1, (*format)->buf, ft_strlen((*format)->buf));
	free((*format)->buf);
	(*format)->buf = ft_strdup("");
	ft_putik(format, c);
}
