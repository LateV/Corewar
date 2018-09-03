/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:58:33 by oskulska          #+#    #+#             */
/*   Updated: 2018/03/13 10:58:35 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_arg_str(t_format *list, va_list ar)
{
	char	*arg;
	int		k;

	k = 0;
	arg = va_arg(ar, char *);
	if (arg == NULL)
	{
		arg = ft_strdup("(null)");
		k = 1;
	}
	if (list->lenght == 0 && list->spec != 'S')
	{
		format_str(list, arg);
		(k == 1) ? ft_strdel(&arg) : arg;
	}
	if (list->lenght == 'l' || list->spec == 'S')
	{
		if (ft_strcmp("(null)", arg) == 0)
		{
			format_str(list, arg);
			ft_strdel(&arg);
		}
		else
			format_wchar_str((wchar_t *)arg, list);
	}
}

void		format_wchar_str(wchar_t *str, t_format *list)
{
	int		i;
	char	*byte;
	char	*s;
	char	*tmp;

	i = -1;
	tmp = ft_strdup("");
	while (str[++i])
	{
		byte = makewchar(list, str[i]);
		s = ft_strjoin(tmp, byte);
		if (ft_strlen(byte) + ft_strlen(s) > (size_t)list->prs)
		{
			free(byte);
			tmp = ft_strdup(s);
			break ;
		}
		free(tmp);
		tmp = ft_strdup(s);
		free(s);
		free(byte);
	}
	format_str(list, tmp);
	free(tmp);
}

char		*new_width_str(t_format *list, char *str)
{
	char	*add;
	size_t	len;

	len = ft_strlen(str);
	if (ft_strcmp(str, "(null)") == 0)
		len = ft_strlen(str);
	if (list->prs < (int)len &&
		(list->spec == 's' || list->spec == 'S') && list->prs != -1)
		len = (size_t)list->prs;
	if ((ft_strcmp(str, "\0") == 0) && (list->spec == 'c' || list->spec == 'C'))
		len++;
	if (list->prs < (int)len && list->spec != 's')
		list->prs = (int)len;
	if (list->widt > (int)len
		&& list->prs >= 0 && len != 0 && list->widt > list->prs)
		list->widt = list->prs == 0 ? (list->widt - 1)
									: (list->widt - list->prs);
	else if (list->widt > (int)ft_strlen(str) || len == 0)
		list->widt = list->widt - (int)len;
	else
		list->widt = 0;
	add = (ft_memset(ft_strnew(list->widt), ' ', list->widt));
	return (add);
}

void		pf_putstr(t_format *list, char *str)
{
	if (str == NULL)
		return ;
	if (ft_strcmp(str, "\0") == 0
		&& (list->spec == 'c' || list->spec == 'C'))
	{
		write(1, str, 1);
		list->lenout++;
	}
	else
	{
		ft_putstr(str);
		list->lenout = list->lenout + ft_strlen(str);
	}
}

void		pf_putchar(t_format *list, char s)
{
	write(1, &s, 1);
	list->lenout++;
}
