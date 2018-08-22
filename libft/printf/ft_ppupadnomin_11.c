/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ppupadnomin_11.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:47:46 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/25 16:47:48 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_ppupadnomin_11(t_printf **format, char *outc)
{
	char	*dec;
	char	*pz;

	pz = ft_genchar_x(format);
	if ((*format)->flag[4] == '0')
	{
		dec = ft_genchar('0', (*format)->width - (int)ft_strlen(outc) - 2);
		dec = ft_strjoin_free_12(pz, dec);
	}
	else
	{
		dec = ft_genchar(' ', (*format)->width - (int)ft_strlen(outc) - 2);
		dec = ft_strjoin_free_12(dec, pz);
	}
	outc = ft_strjoin_free_02(dec, outc);
	return (outc);
}
