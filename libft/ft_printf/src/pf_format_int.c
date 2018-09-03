/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:58:43 by oskulska          #+#    #+#             */
/*   Updated: 2018/03/13 10:58:46 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void		format_with_minus_int(t_format *list, char *arg, char *tmp)
{
	if (list->space && !list->plus && !list->numsign)
		pf_putchar(list, ' ');
	if (list->numsign)
		pf_putchar(list, '-');
	if (list->plus && !list->numsign)
		pf_putchar(list, '+');
	if (list->prs >= 0)
	{
		tmp = add_presicion(list, arg);
		pf_putstr(list, tmp);
		pf_putstr(list, arg);
		free(tmp);
	}
	if (list->prs == -1)
		pf_putstr(list, arg);
	if (list->widt)
	{
		tmp = (get_new_width(list, arg));
		pf_putstr(list, tmp);
		free(tmp);
	}
}

static void			format_nominus_int(t_format *list, char *arg, char *tmp)
{
	if (list->widt && !list->zero)
	{
		tmp = (get_new_width(list, arg));
		pf_putstr(list, tmp);
	}
	if (list->plus && !list->numsign)
		pf_putchar(list, '+');
	if (list->numsign)
		pf_putchar(list, '-');
	if (list->widt && list->zero)
	{
		tmp = get_new_width(list, arg);
		(tmp) ? pf_putstr(list, ft_memset(tmp, '0', ft_strlen(tmp)))
		: pf_putstr(list, tmp);
	}
	if (list->widt)
		free(tmp);
	if (list->prs >= -1)
	{
		tmp = add_presicion(list, arg);
		pf_putstr(list, tmp);
		pf_putstr(list, arg);
		free(tmp);
	}
}

static void			format_int(t_format *list, char *arg)
{
	char			*tmp;

	tmp = NULL;
	if (list->prs == 0 && ft_strcmp(arg, "0") == 0)
	{
		free(arg);
		arg = ft_strnew(0);
	}
	if (list->space && !list->plus && !list->numsign)
		pf_putchar(list, ' ');
	if (list->minus)
		format_with_minus_int(list, arg, tmp);
	if (!list->minus)
	{
		if (list->prs >= 0)
			list->zero = 0;
		format_nominus_int(list, arg, tmp);
	}
	free(arg);
}

void				get_arg_int(t_format *list, va_list ar)
{
	char			*arg;
	char			*str;

	arg = ft_itoau(get_len_int(list, ar));
	if (arg[0] == '-' ||
		(arg[0] == '0' && arg[1] != 'x' && ft_strlen(arg) != 1))
	{
		(arg[0] == '-') ? list->numsign = '-' : list->numsign;
		if ((arg[0] == '0' && arg[1] != 'x' && ft_strlen(arg) != 1))
		{
			free(arg);
			arg = ft_itoa_base(get_len_int(list, ar), 8);
		}
		str = ft_strsub(arg, 1, ft_strlen(arg) - 1);
		format_int(list, str);
		free(arg);
		return ;
	}
	if (arg[0] == '0' && arg[1] == 'x')
	{
		free(arg);
		arg = ft_itoa_base(get_len_int(list, ar), 16);
	}
	format_int(list, arg);
}

size_t				get_len_int(t_format *list, va_list arg)
{
	if (list->spec == 'D')
		list->lenght = 'l';
	if (list->lenght == 0)
		return ((int)va_arg(arg, int));
	if (list->lenght == 'h')
		return ((short int)va_arg(arg, int));
	if (list->lenght == 'H')
		return ((signed char)va_arg(arg, ssize_t));
	if (list->lenght == 'l')
		return (va_arg(arg, long int));
	if (list->lenght == 'L')
		return (va_arg(arg, long long int));
	if (list->lenght == 'j')
		return (va_arg(arg, intmax_t));
	if (list->lenght == 'z')
		return (va_arg(arg, size_t));
	return (0);
}
