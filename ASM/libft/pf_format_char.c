/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:58:53 by oskulska          #+#    #+#             */
/*   Updated: 2018/03/13 10:58:55 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			get_pres_char(t_format *list, char *str)
{
	if (list->prs >= 0 &&
		((size_t)list->prs < ft_strlen(str)) && !list->percent)
	{
		while (list->prs--)
		{
			pf_putchar(list, *str);
			str++;
		}
	}
	else
	{
		if (ft_strlen(str) > 0 && list->prs >= 0
			&& list->prs > (int)ft_strlen(str) && list->prs < list->widt
			&& !list->minus)
		{
			while (list->prs - ft_strlen(str) > 0)
			{
				list->zero == '0' ? ft_putchar('0') : ft_putchar(' ');
				list->lenout++;
				list->prs--;
			}
		}
		pf_putstr(list, str);
	}
}

static	void		format_minus(t_format *list, char *arg)
{
	char			*tmp;
	int				p;

	p = list->prs;
	if (list->prs == 0 && !list->prsflag && list->spec != 's')
		pf_putstr(list, arg);
	get_pres_char(list, arg);
	list->prs = p;
	if (list->widt)
	{
		tmp = new_width_str(list, arg);
		pf_putstr(list, tmp);
		free(tmp);
	}
}

static	void		format_no_minus(t_format *list, char *arg)
{
	char			*tmp;
	int				w;

	w = list->widt;
	if (list->widt && !list->zero)
	{
		tmp = new_width_str(list, arg);
		pf_putstr(list, tmp);
		free(tmp);
	}
	list->widt = w;
	if (list->widt && list->zero)
	{
		tmp = new_width_str(list, arg);
		ft_memset(tmp, '0', ft_strlen(tmp));
		pf_putstr(list, tmp);
		free(tmp);
	}
	list->widt = w;
	get_pres_char(list, arg);
}

void				char_to_str(t_format *list, va_list arg)
{
	char			str[2];
	char			*s;

	if (list->lenght == 0 && list->spec != 'C')
	{
		str[1] = '\0';
		str[0] = (char)va_arg(arg, int);
		format_str(list, str);
	}
	if (list->lenght == 'l' || list->spec == 'C')
	{
		s = makewchar(list, (wint_t)va_arg(arg, int));
		free(s);
	}
}

void				format_str(t_format *list, char *arg)
{
	if (list->prs > (int)ft_strlen(arg) && (list->spec == 'S'))
		list->prs = (int)ft_strlen(arg);
	if (list->minus)
		format_minus(list, arg);
	if (!list->minus)
		format_no_minus(list, arg);
}
