/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:59:13 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/03/27 17:24:33 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		ret;
	va_list	argptr;
	char	*str;
	char	*p;

	ret = 0;
	va_start(argptr, format);
	str = ft_strdup(format);
	p = str;
	while (*str)
	{
		if (*str == '%')
			str += ft_notion(&argptr, &str, &ret);
		else
		{
			write(1, str, 1);
			ret++;
		}
		(*str) ? str += 1 : 0;
	}
	free(p);
	va_end(argptr);
	return (ret);
}
