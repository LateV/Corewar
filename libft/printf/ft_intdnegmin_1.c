/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdnegmin_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:42:10 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:42:11 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_intdnegmin_p(t_printf **format, char *outc)
{
	char *dec;
	char *neg;

	dec = ft_genchar(' ', (*format)->width - (int)ft_strlen(outc) - 1);
	neg = ft_genchar('-', 1);
	outc = ft_strjoin_free_12(neg, outc);
	outc = ft_strjoin_free_12(outc, dec);
	return (outc);
}

void		ft_intdnegmin_1(t_printf **format, char *outc)
{
	char	*dec;
	char	*neg;

	if ((*format)->precision >= 0 && (*format)->precisiondef >= 0)
	{
		neg = ft_genchar('-', 1);
		outc = ft_strjoin_free_12(neg, outc);
		dec = ft_genchar(' ', (*format)->width - (int)ft_strlen(outc) - 1);
		outc = ft_strjoin_free_12(outc, dec);
	}
	else
		outc = ft_intdnegmin_p(format, outc);
	(*format)->buf = ft_strjoin_free_12((*format)->buf, outc);
}
