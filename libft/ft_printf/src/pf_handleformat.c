/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handleformat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:56:53 by oskulska          #+#    #+#             */
/*   Updated: 2018/03/13 10:57:00 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flag(char *str, t_format *list)
{
	int	i;
	int	k;

	k = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '#')
			list->hash = str[i];
		if (str[i] == '0' && ((!str[i - 1]
			|| !ft_isdigit(str[i - 1])) && str[i - 1] != '.') && k == 0)
		{
			list->zero = '0';
			k = 1;
		}
		if (str[i] == '+')
			list->plus = '+';
		if (str[i] == '-')
			list->minus = '-';
		if (str[i] == ' ')
			list->space = str[i];
		if (!is_handler(str[i]) && (list->hash || list->minus
			|| list->plus || list->zero || list->space))
			break ;
	}
}

void	get_width(char *str, t_format *list)
{
	int i;
	int is_ok;

	i = 0;
	is_ok = 0;
	while (str[i] && str[i] != '%')
	{
		while (ft_isdigit(str[i]) && !is_ok)
		{
			list->widt = list->widt * 10 + (str[i] - '0');
			i++;
			if (str[i] && !ft_isdigit(str[i]))
				is_ok = 1;
		}
		if (ft_isdigit(str[i]) && is_ok && str[i] != '0')
		{
			is_ok = 0;
			list->widt = str[i] - '0';
		}
		if (str[i] == '.')
			break ;
		i++;
	}
}

void	get_precision(char *str, t_format *list)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.' && ft_isdigit(str[i + 1]))
		{
			list->prs = 0;
			i++;
			while (ft_isdigit(str[i]) && str[i])
			{
				list->prs = list->prs * 10 + (str[i] - '0');
				i++;
			}
		}
		if (str[i] == '.' && !ft_isdigit(str[i + 1]))
		{
			list->prsflag = 1;
			list->prs = 0;
		}
		i++;
	}
}

void	get_lenght(char *str, t_format *list)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == 'h' && str[i + 1] == 'h') ||
			(str[i] == 'l' && str[i + 1] == 'l'))
		{
			list->lenght = str[i] - 32;
			i = i + 2;
		}
		if ((str[i] == 'h' && str[i + 1] != 'h')
			|| (str[i] == 'l' && str[i + 1] != 'l')
			|| (str[i] == 'j') || (str[i] == 'z'))
			list->lenght = str[i];
		i++;
	}
}

char	*get_specifier(const char *str, t_format *list)
{
	int i;

	i = 0;
	while (str[i] != '%' && str[i])
	{
		if (str[i] == 'c' || str[i] == 'C' || str[i] == 's' || str[i] == 'S'
			|| str[i] == 'p' || str[i] == 'd' || str[i] == 'i' || str[i] == 'D'
			|| str[i] == 'o' || str[i] == 'O' || str[i] == 'U'
			|| str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
		{
			list->spec = str[i];
			break ;
		}
		if (!is_handler(str[i]))
			return (ft_strdup(str));
		i++;
	}
	if (str[i] == '%' && !list->spec)
		list->percent = str[i];
	return (ft_strsub(str, 0, i));
}
