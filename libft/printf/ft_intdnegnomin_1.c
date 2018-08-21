/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdnegnomin_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:42:16 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:42:17 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_intdnegnomin_p(t_printf **format, char *outc)
{
	char *dec;
	char *neg;

	if ((*format)->flag[4] == '0')
	{
		dec = ft_genchar('0', (*format)->width - (int)ft_strlen(outc) - 1);
		neg = ft_genchar('-', 1);
		dec = ft_strjoin_free_12(neg, dec);
		outc = ft_strjoin_free_12(dec, outc);
	}
	else
	{
		dec = ft_genchar(' ', (*format)->width - (int)ft_strlen(outc) - 1);
		neg = ft_genchar('-', 1);
		dec = ft_strjoin_free_12(dec, neg);
		outc = ft_strjoin_free_12(dec, outc);
	}
	return (outc);
}

void		ft_intdnegnomin_1(t_printf **format, char *outc)
{
	char	*dec;
	char	*neg;

	if ((*format)->precision >= 0 && (*format)->precisiondef >= 0)
	{
		neg = ft_genchar('-', 1);
		dec = ft_genchar(' ', (*format)->width - (int)ft_strlen(outc) - 1);
		dec = ft_strjoin_free_12(dec, neg);
		outc = ft_strjoin_free_12(dec, outc);
	}
	else
		outc = ft_intdnegnomin_p(format, outc);
	(*format)->buf = ft_strjoin_free_12((*format)->buf, outc);
}
