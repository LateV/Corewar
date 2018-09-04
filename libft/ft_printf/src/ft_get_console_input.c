/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:13:01 by oskulska          #+#    #+#             */
/*   Updated: 2017/11/14 18:13:02 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_console_input(char *str, int buf_size, int buf)
{
	char	read_buf[buf];
	char	*tmp;
	int		len;
	int		ret;

	len = 0;
	ret = 0;
	str = (char *)malloc(sizeof(char) * buf_size + 1);
	while ((ret = read(0, read_buf, buf)))
	{
		if (len == buf_size)
		{
			tmp = ft_memory(str);
			free(str);
			str = tmp;
			buf_size = buf_size + buf_size / 2;
		}
		str[len] = read_buf[0];
		len++;
	}
	if (ret < 0)
		return (NULL);
	str[len] = '\0';
	return (str);
}
