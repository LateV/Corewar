/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:42:58 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:42:59 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			ft_format_flag(int i, char *std_flag, char *str, t_printf **format)
{
	while (ft_strchr(std_flag, str[i]) != NULL && str[i] != '\0')
	{
		if (str[i] == '-')
			(*format)->flag[0] = str[i];
		if (str[i] == '+')
			(*format)->flag[1] = str[i];
		if (str[i] == '#')
			(*format)->flag[2] = str[i];
		if (str[i] == '0')
			(*format)->flag[4] = str[i];
		if (str[i] == ' ')
			(*format)->flag[3] = str[i];
		i++;
	}
	return (i);
}

int			ft_format_width(int i, char *str, t_printf **format, va_list argum)
{
	if (str[i] == '*')
	{
		(*format)->width = va_arg(argum, int);
		if ((*format)->width < 0)
		{
			(*format)->width = (*format)->width * (-1);
			(*format)->flag[0] = '-';
		}
		i++;
		return (i);
	}
	else
		(*format)->width = ft_atoi(str + i);
	i = i + ft_dig_count((*format)->width);
	return (i);
}

int			ft_format_precision(int i, t_printf **format,
	char *str, va_list argum)
{
	if (str[i] == '.' && ft_isdigit(str[i + 1]))
	{
		(*format)->precision = ft_atoi(str + i + 1);
		i = i + 1 + ft_dig_count((*format)->precision);
		return (i);
	}
	if (str[i] == '.' && str[i + 1] == '*')
	{
		(*format)->precision = va_arg(argum, int);
		if ((*format)->precision < 0)
			(*format)->precision = -1;
		i = i + 2;
		return (i);
	}
	if (str[i] == '.' && !ft_isdigit(str[i + 1]))
	{
		(*format)->precision = 0;
		i++;
		return (i);
	}
	return (i);
}

int			ft_format_length(int i, char *stdl, char *str, t_printf **format)
{
	if (ft_strchr(stdl, str[i]) != NULL && str[i] != '\0')
	{
		if (str[i] == 'h' && str[i + 1] == 'h' &&
			(*format)->length[0] == '\0')
		{
			(*format)->length[0] = str[i];
			(*format)->length[1] = str[i + 1];
			i = i + 2;
		}
		else if (str[i] == 'h' && str[i + 1] != 'h' &&
			(*format)->length[0] != 'l' &&
			(*format)->length[0] != 'j' && (*format)->length[0] != 'z')
		{
			(*format)->length[0] = str[i];
			(*format)->length[1] = '\0';
			i = i + 1;
		}
		else
			return (ft_format_length_1(i, "ljhztL", str, format));
	}
	return (i);
}

int			ft_format_type(int i, char *str, t_printf **format)
{
	(*format)->type[0] = str[i];
	i++;
	return (i);
}
