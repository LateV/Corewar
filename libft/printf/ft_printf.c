/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:37:35 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:37:37 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_struct(t_printf **format)
{
	(*format)->width = -1;
	(*format)->precision = -1;
	(*format)->precisiondef = 0;
	(*format)->invalid = 0;
	(*format)->num = 0;
	ft_memset((*format)->flag, '\0', 5);
	ft_memset((*format)->length, '\0', 2);
	ft_memset((*format)->type, '\0', 2);
}

static int	ft_outforstr(char *str, int i, t_printf **format)
{
	int		j;
	char	*s2;

	j = i;
	while (str[i] != '%' && str[i] != '\0')
		i++;
	s2 = ft_strsub(str, j, i - j);
	if (s2)
	{
		(*format)->buf = ft_strjoin_free_12((*format)->buf, s2);
		(*format)->num = (*format)->num + ft_strlen((*format)->buf);
		write(1, (*format)->buf, ft_strlen((*format)->buf));
		free((*format)->buf);
		(*format)->buf = ft_strdup("");
	}
	return (i);
}

static int	ft_loop(char *str, int i, t_printf **format, va_list argum)
{
	if (str[i] != '\0')
		(*format)->buf = ft_strdup("");
	while (str[i] != '\0')
	{
		if ((*format)->invalid == 1)
			break ;
		if (str[i] != '%')
			i = ft_outforstr(str, i, format);
		if (str[i] == '%')
		{
			i++;
			i = ft_specif(format, str, i, argum);
			if ((*format)->invalid != 1 && (*format)->type[0] != '\0')
				ft_outp((*format), argum);
			ft_freesh((*format));
		}
	}
	return (i);
}

int			ft_printf(char *str, ...)
{
	va_list			argum;
	t_printf		*format;
	int				k;

	format = malloc(sizeof(t_printf));
	ft_struct(&format);
	va_start(argum, str);
	ft_loop(str, 0, &format, argum);
	va_end(argum);
	free(format);
	k = format->num;
	return (k);
}
