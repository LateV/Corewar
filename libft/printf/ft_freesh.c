/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:42:46 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:42:47 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_freesh(t_printf *format)
{
	format->width = -1;
	format->precision = -1;
	format->widthdef = -1;
	ft_memset(format->flag, '\0', 5);
	ft_memset(format->length, '\0', 2);
	ft_memset(format->type, '\0', 2);
}
