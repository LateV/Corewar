/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creatstrctr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:58:52 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/03/27 19:05:15 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_format	*ft_creatstrctr(void)
{
	t_format *new;

	if (!(new = (t_format*)malloc(sizeof(t_format))))
		return (NULL);
	new->flag_zero = 0;
	new->flag_hash = 0;
	new->flag_minus = 0;
	new->flag_plus = 0;
	new->flag_space = 0;
	new->width = 0;
	new->precision = -1;
	new->length_h = 0;
	new->length_l = 0;
	new->length_j = 0;
	new->length_z = 0;
	new->type = 0;
	return (new);
}
