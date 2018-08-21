/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputdnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:38:28 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:38:30 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_pputdnbr(t_printf **format, va_list argum)
{
	if ((*format)->precision < 0)
	{
		(*format)->precisiondef = (*format)->precision;
		(*format)->precision = 0;
	}
	if ((*format)->length[0] == '\0' && (*format)->length[1] == '\0')
		ft_putdnolen(format, ft_length_nolen(format, argum));
	if ((*format)->length[0] == 'h' && (*format)->length[1] == '\0')
		ft_putdnolen(format, ft_length_h(format, argum));
	if ((*format)->length[0] == 'h' && (*format)->length[1] == 'h')
		ft_putdnolen(format, ft_length_hh(format, argum));
	if ((*format)->length[0] == 'l' && (*format)->length[1] == '\0')
		ft_putdnolen(format, ft_length_l(format, argum));
	if ((*format)->length[0] == 'l' && (*format)->length[1] == 'l')
		ft_putdnolen(format, ft_length_ll(format, argum));
	if ((*format)->length[0] == 'j' && (*format)->length[1] == '\0')
		ft_putdnolen(format, ft_length_j(format, argum));
	if ((*format)->length[0] == 'z' && (*format)->length[1] == '\0')
		ft_putdnolen(format, ft_length_z(format, argum));
	(*format)->num = (*format)->num + ft_strlen((*format)->buf);
	write(1, (*format)->buf, ft_strlen((*format)->buf));
	free((*format)->buf);
	(*format)->buf = ft_strdup("");
}

void	ft_pputunbr(t_printf **format, va_list argum)
{
	if ((*format)->precision < 0)
	{
		(*format)->precisiondef = (*format)->precision;
		(*format)->precision = 0;
	}
	if ((*format)->length[0] == '\0' && (*format)->length[1] == '\0')
		ft_putdnolen(format, ft_lengthu_nolen(format, argum));
	if ((*format)->length[0] == 'h' && (*format)->length[1] == '\0')
		ft_putdnolen(format, ft_lengthu_h(format, argum));
	if ((*format)->length[0] == 'h' && (*format)->length[1] == 'h')
		ft_putdnolen(format, ft_lengthu_hh(format, argum));
	if ((*format)->length[0] == 'l' && (*format)->length[1] == '\0')
		ft_putdnolen(format, ft_lengthu_l(format, argum));
	if ((*format)->length[0] == 'l' && (*format)->length[1] == 'l')
		ft_putdnolen(format, ft_lengthu_ll(format, argum));
	if ((*format)->length[0] == 'j' && (*format)->length[1] == '\0')
		ft_putdnolen(format, ft_lengthu_j(format, argum));
	if ((*format)->length[0] == 'z' && (*format)->length[1] == '\0')
		ft_putdnolen(format, ft_lengthu_z(format, argum));
	(*format)->num = (*format)->num + ft_strlen((*format)->buf);
	write(1, (*format)->buf, ft_strlen((*format)->buf));
	free((*format)->buf);
	(*format)->buf = ft_strdup("");
}

void	ft_pputonbr(t_printf **format, va_list argum)
{
	if ((*format)->precision < 0)
	{
		(*format)->precisiondef = (*format)->precision;
		(*format)->precision = 0;
	}
	if ((*format)->length[0] == '\0' && (*format)->length[1] == '\0')
		ft_putonolen(format, ft_lengtho_nolen(format, argum, 8));
	if ((*format)->length[0] == 'h' && (*format)->length[1] == '\0')
		ft_putonolen(format, ft_lengtho_h(format, argum, 8));
	if ((*format)->length[0] == 'h' && (*format)->length[1] == 'h')
		ft_putonolen(format, ft_lengtho_hh(format, argum, 8));
	if ((*format)->length[0] == 'l' && (*format)->length[1] == '\0')
		ft_putonolen(format, ft_lengtho_l(format, argum, 8));
	if ((*format)->length[0] == 'l' && (*format)->length[1] == 'l')
		ft_putonolen(format, ft_lengtho_ll(format, argum, 8));
	if ((*format)->length[0] == 'j' && (*format)->length[1] == '\0')
		ft_putonolen(format, ft_lengtho_j(format, argum, 8));
	if ((*format)->length[0] == 'z' && (*format)->length[1] == '\0')
		ft_putonolen(format, ft_lengtho_z(format, argum, 8));
	(*format)->num = (*format)->num + ft_strlen((*format)->buf);
	write(1, (*format)->buf, ft_strlen((*format)->buf));
	free((*format)->buf);
	(*format)->buf = ft_strdup("");
}

void	ft_pputxnbr(t_printf **format, va_list argum)
{
	if ((*format)->precision < 0)
	{
		(*format)->precisiondef = (*format)->precision;
		(*format)->precision = 0;
	}
	if ((*format)->length[0] == '\0' && (*format)->length[1] == '\0')
		ft_putxnolen(format, ft_lengtho_nolen(format, argum, 16));
	if ((*format)->length[0] == 'h' && (*format)->length[1] == '\0')
		ft_putxnolen(format, ft_lengtho_h(format, argum, 16));
	if ((*format)->length[0] == 'h' && (*format)->length[1] == 'h')
		ft_putxnolen(format, ft_lengtho_hh(format, argum, 16));
	if ((*format)->length[0] == 'l' && (*format)->length[1] == '\0')
		ft_putxnolen(format, ft_lengtho_l(format, argum, 16));
	if ((*format)->length[0] == 'l' && (*format)->length[1] == 'l')
		ft_putxnolen(format, ft_lengtho_ll(format, argum, 16));
	if ((*format)->length[0] == 'j' && (*format)->length[1] == '\0')
		ft_putxnolen(format, ft_lengtho_j(format, argum, 16));
	if ((*format)->length[0] == 'z' && (*format)->length[1] == '\0')
		ft_putxnolen(format, ft_lengtho_z(format, argum, 16));
	(*format)->num = (*format)->num + ft_strlen((*format)->buf);
	write(1, (*format)->buf, ft_strlen((*format)->buf));
	free((*format)->buf);
	(*format)->buf = ft_strdup("");
}
