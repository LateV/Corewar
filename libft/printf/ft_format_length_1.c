/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_length_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:05:02 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/25 17:05:03 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int			ft_format_length_2(int i, char *stdl,
	char *str, t_printf **format)
{
	if (str[i] == 'z')
	{
		(*format)->length[0] = str[i];
		(*format)->length[1] = '\0';
		i = i + 1;
	}
	else if (ft_strchr(stdl, str[i]) != NULL &&
		ft_strchr(stdl, str[i + 1]) != NULL)
		i = i + 2;
	else if (ft_strchr(stdl, str[i]) != NULL &&
		ft_strchr(stdl, str[i + 1]) == NULL)
		i = i + 1;
	return (i);
}

int					ft_format_length_1(int i, char *stdl,
	char *str, t_printf **format)
{
	if (str[i] == 'l' && str[i + 1] != 'l' &&
		(*format)->length[1] != 'l' &&
		(*format)->length[0] != 'j' && (*format)->length[0] != 'z')
	{
		(*format)->length[0] = str[i];
		(*format)->length[1] = '\0';
		i = i + 1;
	}
	else if (str[i] == 'l' && str[i + 1] == 'l' &&
		(*format)->length[0] != 'j' && (*format)->length[0] != 'z')
	{
		(*format)->length[0] = str[i];
		(*format)->length[1] = str[i + 1];
		i = i + 1;
	}
	else if (str[i] == 'j' && (*format)->length[0] != 'z')
	{
		(*format)->length[0] = str[i];
		(*format)->length[1] = '\0';
		i = i + 1;
	}
	else
		return (ft_format_length_2(i, stdl, str, format));
	return (i);
}
