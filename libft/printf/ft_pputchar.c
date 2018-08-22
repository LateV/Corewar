/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:37:51 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/11 13:37:54 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void		ft_printelse(t_printf **format, char c)
{
	char		*stroka;

	if ((*format)->width > 1)
	{
		stroka = (char*)malloc(sizeof(char) * (*format)->width);
		if ((*format)->flag[4] == '0')
			ft_memset(stroka, '0', (*format)->width);
		else
			ft_memset(stroka, ' ', (*format)->width);
		stroka[(*format)->width] = '\0';
		stroka[(*format)->width - 1] = c;
		(*format)->buf = ft_strjoin((*format)->buf, stroka);
	}
	else
	{
		stroka = (char*)malloc(sizeof(char) * 2);
		stroka[0] = c;
		stroka[1] = '\0';
		(*format)->buf = ft_strjoin((*format)->buf, stroka);
	}
	free(stroka);
}

static void		ft_print(t_printf **format, char c)
{
	char		*stroka;
	int			len;

	if ((*format)->width <= 0)
	{
		stroka = (char*)ft_memalloc(sizeof(char) * 2);
		(*format)->buf = ft_strjoin((*format)->buf, "  ");
		len = ft_strlen((*format)->buf);
		(*format)->buf[len - 2] = c;
		(*format)->buf[len - 1] = '\0';
		free(stroka);
	}
	else
	{
		stroka = (char*)ft_memalloc(sizeof(char) * (*format)->width);
		ft_memset(stroka, ' ', (*format)->width);
		stroka[0] = c;
		stroka[(*format)->width] = '\0';
		(*format)->buf = ft_strjoin((*format)->buf, stroka);
		free(stroka);
	}
}

static void		ft_printnullm(t_printf **format)
{
	char		*spac;

	spac = (char*)ft_memalloc(sizeof(char) * (*format)->width + 1);
	ft_memset(spac, ' ', (*format)->width);
	spac[0] = '\0';
	(*format)->num = (*format)->num + ft_strlen((*format)->buf);
	write(1, (*format)->buf, (*format)->num);
	write(1, spac, (*format)->width);
	if ((*format)->width > 0)
		(*format)->num = (*format)->num + (*format)->width;
	else
		(*format)->num = (*format)->num + 1;
	free((*format)->buf);
	free(spac);
	(*format)->buf = ft_strdup("");
}

static void		ft_printnull(t_printf **format)
{
	char		*stroka;

	if ((*format)->flag[0] == '-')
	{
		ft_printnullm(format);
		return ;
	}
	if ((*format)->width > 1)
	{
		stroka = (char*)malloc(sizeof(char) * (*format)->width);
		if ((*format)->flag[4] == '0')
			ft_memset(stroka, '0', (*format)->width);
		else
			ft_memset(stroka, ' ', (*format)->width);
		stroka[(*format)->width] = '\0';
		stroka[(*format)->width - 1] = '\0';
		write(1, stroka, ft_strlen(stroka) + 1);
		(*format)->num = (*format)->num + (*format)->width;
		free(stroka);
	}
	else
	{
		write(1, "\0", 1);
		(*format)->num = (*format)->num + 1;
	}
}

void			ft_pputcharik(t_printf **format, char c)
{
	char		*tmp;

	if ((*format)->width < 0)
		(*format)->width = 0;
	tmp = (*format)->buf;
	if (c == '\0')
	{
		(*format)->num = (*format)->num + ft_strlen((*format)->buf);
		write(1, (*format)->buf, ft_strlen((*format)->buf));
		free((*format)->buf);
		(*format)->buf = ft_strdup("");
		ft_printnull(format);
		return ;
	}
	if ((*format)->flag[0] == '-')
	{
		ft_print(format, c);
		free(tmp);
		return ;
	}
	ft_printelse(format, c);
	(*format)->num = (*format)->num + ft_strlen((*format)->buf);
	write(1, (*format)->buf, ft_strlen((*format)->buf));
	free((*format)->buf);
	(*format)->buf = ft_strdup("");
}
