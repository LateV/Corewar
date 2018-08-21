/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputstrik.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:07:12 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/25 16:07:14 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_pputstr(t_printf **format, va_list argum)
{
	char	*str;

	if ((*format)->length[0] == 'l')
	{
		ft_pput_wchar_str(format, argum);
		return ;
	}
	str = va_arg(argum, char*);
	ft_pputstrik(format, str);
}
