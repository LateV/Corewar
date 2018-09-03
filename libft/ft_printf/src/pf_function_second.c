/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_function_second.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:57:14 by oskulska          #+#    #+#             */
/*   Updated: 2018/03/13 10:57:18 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_handler(char c)
{
	char	*str;

	str = "cCsSpdiDoOpuUXxhljz0123456789 -.+#%";
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int			set_flag(t_format *list, char *arg)
{
	int		k;

	k = 0;
	if (ft_strcmp(arg, "0") == 0 && (list->spec == 'x' || list->spec == 'X'))
		k = 1;
	if ((list->prs <= 0 &&
		(ft_strcmp(arg, "0") == 0 || ft_strcmp(arg, "\0") == 0)))
	{
		if ((list->spec == 'o' || list->spec == 'O') && list->prs == 0)
			k = 0;
		else
			k = 1;
	}
	return (k);
}

int			get_arg_u_o_x(t_format *list, va_list arg)
{
	if (list->spec == 'U' || list->spec == 'O')
		list->lenght = 'l';
	if (list->lenght == 0 && list->spec != 'p')
		arg_to_uox_str(list, va_arg(arg, unsigned int));
	if (list->lenght == 'H' && list->spec != 'p')
		arg_to_uox_str(list, (unsigned char)va_arg(arg, int));
	if (list->lenght == 'h' && list->spec != 'p')
		arg_to_uox_str(list, (unsigned short)va_arg(arg, int));
	if (list->lenght == 'l' && list->spec != 'p')
		arg_to_uox_str(list, (unsigned long int)va_arg(arg, long int));
	if (list->lenght == 'L' && list->spec != 'p')
		arg_to_uox_str(list, (unsigned long long)va_arg(arg, long long int));
	if (list->lenght == 'j' && list->spec != 'p')
		arg_to_uox_str(list, (uintmax_t)va_arg(arg, uintmax_t));
	if (list->lenght == 'z' || list->spec == 'p')
		arg_to_uox_str(list, (size_t)va_arg(arg, size_t));
	return (1);
}

void		len_to_skip(t_format *list, char *format)
{
	if (list->spec || list->percent)
		list->len++;
	while (is_handler(*format))
	{
		list->len++;
		format++;
	}
}

int			pre_width_u_o_x(t_format *list, char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if ((list->hash && list->widt > 0
		&& (list->prs < (int)len || list->prs == -1) && list->spec != 'u')
		|| (len == 0 && list->spec == 'o' && list->hash))
		list->widt--;
	if (list->hash && list->widt > 0 && (list->prs > (int)len)
		&& (list->spec == 'x' || list->spec == 'X' || list->spec == 'p'))
		list->widt--;
	if (((ft_strcmp(str, "\0") == 0) && (list->spec == 'p'))
		|| (list->spec == 'p' && ft_strequ("0", str)))
		list->widt--;
	if (list->hash &&
		((list->spec == 'x' && !ft_strequ("\0", str))
		|| list->spec == 'X' || (list->spec == 'p' && !ft_strequ("0", str))))
		list->widt--;
	return (list->widt);
}
