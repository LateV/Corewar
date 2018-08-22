/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:39:05 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:39:07 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_outp1(t_printf *format, va_list argum)
{
	if (format->type[0] == 'O')
		ft_putonolen(&format, ft_lengtho_l(&format, argum, 8));
	if (format->type[0] == 'x' || format->type[0] == 'X')
		ft_pputxnbr(&format, argum);
	if (format->type[0] == '%')
		ft_pputproc(&format);
	if (format->type[0] == 'C')
		ft_pput_wchar(&format, argum);
	if (format->type[0] == 'S')
		ft_pput_wchar_str(&format, argum);
	if (format->type[0] == 'p')
		ft_ppupad(&format, ft_lengtho_l(&format, argum, 16));
}

void		ft_outp(t_printf *format, va_list argum)
{
	if (format->type[0] == 's')
		ft_pputstr(&format, argum);
	if (format->type[0] == 'c')
		ft_pputchar(&format, argum);
	if (format->type[0] == 'd' || format->type[0] == 'i')
		ft_pputdnbr(&format, argum);
	if (format->type[0] == 'D')
		ft_putdnolen(&format, ft_length_l(&format, argum));
	if (format->type[0] == 'u')
		ft_pputunbr(&format, argum);
	if (format->type[0] == 'U')
		ft_putdnolen(&format, ft_lengthu_l(&format, argum));
	if (format->type[0] == 'o')
		ft_pputonbr(&format, argum);
	ft_outp1(format, argum);
}
