/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:58:02 by oskulska          #+#    #+#             */
/*   Updated: 2018/03/13 10:58:06 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_wchar(unsigned int v, size_t len)
{
	char	*byte;

	byte = ft_strnew(len + 1);
	if (len == 1)
		byte[0] = (unsigned char)(v);
	if (len == 2)
	{
		byte[0] = (unsigned char)(((v & 1984) >> 6) + 192);
		byte[1] = (unsigned char)((v & 63) + 128);
	}
	if (len == 3)
	{
		byte[0] = (unsigned char)(((v & 0xF000) >> 12) + 0xE0);
		byte[1] = (unsigned char)(((v & 0x0FC0) >> 6) + 0x80);
		byte[2] = (unsigned char)((v & 0x003F) + 0x80);
	}
	if (len == 4)
	{
		byte[0] = (4034953344 >> 24) | ((v >> 18) << 29) >> 29;
		byte[1] = ((4034953344 << 8) >> 24) | ((v >> 12) << 26) >> 26;
		byte[2] = ((4034953344 << 16) >> 24) | ((v >> 6) << 26) >> 26;
		byte[3] = ((4034953344 << 24) >> 24) | (v << 26) >> 26;
	}
	return (byte);
}

char		*makewchar(t_format *list, unsigned int n)
{
	char	*byte;

	if (n == 0)
		byte = ft_wchar(n, 0);
	if (n < 128 && n > 0)
		byte = ft_wchar(n, 1);
	if (n < 2048 && n > 127)
		byte = ft_wchar(n, 2);
	if (n < 65536 && n > 2047)
		byte = ft_wchar(n, 3);
	if (n > 65535)
		byte = ft_wchar(n, 4);
	if (list->spec == 'C' || (list->spec == 'c' && list->lenght == 'l'))
		format_str(list, byte);
	return (byte);
}

char		*get_new_width(t_format *list, char *str)
{
	char	*add;
	int		len;

	len = (int)ft_strlen(str);
	add = ft_strnew(0);
	if ((list->plus || list->space || list->numsign) && list->prs == -1)
		len++;
	if ((list->widt > (int)ft_strlen(str)) && (list->widt > list->prs))
	{
		if ((list->widt < list->prs) && list->widt > (int)ft_strlen(str))
			list->widt = 0;
		if ((list->plus || list->numsign || list->space) && list->prs >= 0)
			list->widt--;
		if (list->prs > (int)ft_strlen(str))
			list->widt = list->widt - list->prs;
		else
			list->widt = list->widt - len;
		free(add);
		add = ft_memset(ft_strnew((size_t)list->widt), ' ', (size_t)list->widt);
	}
	return (add);
}

char		*add_presicion(t_format *list, char *str)
{
	char	*arg;

	arg = ft_strnew(0);
	if (list->prs > (int)ft_strlen(str) && list->prs >= 0)
	{
		free(arg);
		arg = ft_strnew(list->prs - ft_strlen(str));
		ft_memset(arg, '0', list->prs - ft_strlen(str));
	}
	return (arg);
}

void		format_no_spec(t_format *list, char *str)
{
	int		i;
	int		k;
	char	*s;

	s = ft_strnew(ft_strlen(str));
	i = -1;
	k = -1;
	while (str[++i] && str[i] != '%')
	{
		if (!ft_isalpha(str[i]) && str[i] && str[i + 1] != '%')
		{
			i++;
			list->len++;
		}
		if (ft_isalpha(str[i]) && str[i])
		{
			s[++k] = str[i];
			list->len++;
		}
	}
	if ((list->minus || (!list->prs && !list->widt)) && list->prsflag)
		pf_putstr(list, s);
	format_str(list, s);
	free(s);
	free(str);
}
