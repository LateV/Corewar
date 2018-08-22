/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputcharik.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:14:28 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/25 16:14:30 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void			ft_pputchar(t_printf **format, va_list argum)
{
	char		c;

	if ((*format)->length[0] == 'l')
	{
		ft_pput_wchar(format, argum);
		return ;
	}
	c = va_arg(argum, int);
	ft_pputcharik(format, c);
	(*format)->num = (*format)->num + ft_strlen((*format)->buf);
	write(1, (*format)->buf, ft_strlen((*format)->buf));
	free((*format)->buf);
	(*format)->buf = ft_strdup("");
}
