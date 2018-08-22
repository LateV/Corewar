/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_w_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:53:19 by rkhilenk          #+#    #+#             */
/*   Updated: 2018/01/11 15:53:21 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <string.h>

size_t	ft_w_strlen(const wchar_t *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		ft_wandc_len(const wchar_t *s)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] <= 127)
			len += 1;
		else if (s[i] <= 2047)
			len += 2;
		else if (s[i] <= 65535)
			len += 3;
		else if (s[i] <= 1114111)
			len += 4;
		i++;
	}
	return (len);
}

int		ft_wchar_len(const wchar_t c)
{
	if (c <= 127)
		return (1);
	else if (c <= 2047)
		return (2);
	else if (c <= 65535)
		return (3);
	else if (c <= 1114111)
		return (4);
	return (0);
}
