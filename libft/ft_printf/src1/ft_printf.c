/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:59:11 by oskulska          #+#    #+#             */
/*   Updated: 2018/03/13 10:59:13 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				reset_format(t_format *list)
{
	list->zero = 0;
	list->plus = 0;
	list->minus = 0;
	list->space = 0;
	list->hash = 0;
	list->widt = 0;
	list->prs = -1;
	list->prsflag = 0;
	list->lenght = 0;
	list->spec = 0;
	list->len = 0;
	list->lenout = 0;
	list->numsign = 0;
	list->percent = 0;
	list->out = ft_strnew(0);
}

static t_format			*ft_readformat(const char *format)
{
	t_format			*list;
	char				*str;

	list = (t_format *)malloc(sizeof(t_format));
	reset_format(list);
	str = get_specifier(format, list);
	len_to_skip(list, str);
	get_flag(str, list);
	get_width(str, list);
	get_precision(str, list);
	get_lenght(str, list);
	free(str);
	return (list);
}

static t_format			*ft_handler(va_list arg, const char *format)
{
	t_format			*list;

	list = ft_readformat(format);
	if (list->spec == 'c' || list->spec == 'C')
		char_to_str(list, arg);
	if (list->spec == 's' || list->spec == 'S')
		get_arg_str(list, arg);
	if (list->spec == 'd' || list->spec == 'i'
		|| list->spec == 'D')
		get_arg_int(list, arg);
	if (list->spec == 'o' || list->spec == 'O'
		|| list->spec == 'u' || list->spec == 'U'
		|| list->spec == 'x' || list->spec == 'X'
		|| list->spec == 'p')
		get_arg_u_o_x(list, arg);
	if (!list->percent && !list->spec && list->widt)
	{
		list->len = 0;
		list->prs = 0;
		format_no_spec(list, ft_strdup(format));
	}
	if (list->percent)
		format_str(list, "%");
	return (list);
}

static size_t			ft_printstart(va_list arg, const char *format)
{
	t_format			*list;
	size_t				len;

	len = 0;
	list = NULL;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			list = ft_handler(arg, format);
			format = format + list->len;
			len = len + list->lenout;
			free(list->out);
			free(list);
		}
		else if (*format != '%' && *format)
		{
			ft_putchar(*format);
			format++;
			len++;
		}
	}
	return (len);
}

int						ft_printf(const char *format, ...)
{
	va_list				arg;
	size_t				len;

	va_start(arg, format);
	len = ft_printstart(arg, format);
	va_end(arg);
	return (len);
}
