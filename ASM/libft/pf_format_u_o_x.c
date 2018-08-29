/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_u_o_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:58:15 by oskulska          #+#    #+#             */
/*   Updated: 2018/03/13 10:58:20 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			add_pres_u_o_x(t_format *list, char *str)
{
	size_t			k;

	k = (size_t)list->prs;
	if ((list->spec == 'o' || list->spec == 'O') && list->hash)
		k--;
	if (list->prs > (int)ft_strlen(str))
	{
		while ((k - ft_strlen(str)) > 0)
		{
			ft_putchar('0');
			k--;
			list->lenout++;
		}
		list->zero = 0;
	}
}

static	void		add_width_u_o_x(t_format *list, size_t i)
{
	char			*s;

	s = ft_strnew(i);
	if (i != 0)
	{
		if (list->zero && !list->minus)
			ft_memset(s, '0', i);
		if (!list->zero || (list->zero && list->minus))
			ft_memset(s, ' ', i);
		pf_putstr(list, s);
	}
	ft_strdel(&s);
}

static int			new_width_u_o_x(t_format *list, char *str)
{
	size_t			len;

	len = ft_strlen(str);
	list->widt = pre_width_u_o_x(list, str);
	if ((int)len >= list->widt || list->widt <= list->prs)
		list->widt = 0;
	if (list->widt > (int)len
		&& list->widt > list->prs && list->prs < (int)len)
		list->widt = list->widt - (int)len;
	if (list->widt > (int)len
		&& list->widt > list->prs && list->prs >= (int)len)
		list->widt = list->widt - list->prs;
	return (list->widt);
}

static void			format_u_o_x(t_format *list, char *arg)
{
	int ret;

	if (list->minus)
	{
		pf_addpost(list, set_flag(list, arg));
		add_pres_u_o_x(list, arg);
		pf_putstr(list, pf_tolower(list, arg));
		add_width_u_o_x(list, (size_t)new_width_u_o_x(list, arg));
	}
	if (!list->minus)
	{
		if (list->minus || (list->widt > (int)ft_strlen(arg)
			&& list->prs < list->widt && list->prs != -1))
			list->zero = '\0';
		ret = pf_addpre(list, set_flag(list, arg));
		add_width_u_o_x(list, (size_t)new_width_u_o_x(list, arg));
		if (!ret)
			pf_addpost(list, set_flag(list, arg));
		add_pres_u_o_x(list, arg);
		pf_putstr(list, pf_tolower(list, arg));
	}
}

void				arg_to_uox_str(t_format *list, size_t ar)
{
	char			*str;

	str = NULL;
	if (list->spec == 'p')
		list->hash = 1;
	if (list->spec == 'o' || list->spec == 'O')
		str = ft_itoa_base(ar, 8);
	if (list->spec == 'u' || list->spec == 'U')
		str = ft_itoa_base(ar, 10);
	if (list->spec == 'x' || list->spec == 'X' || list->spec == 'p')
		str = ft_itoa_base(ar, 16);
	if (list->prs == 0 && ar == 0)
		str = ft_strdup("\0");
	format_u_o_x(list, str);
	ft_strdel(&str);
}
