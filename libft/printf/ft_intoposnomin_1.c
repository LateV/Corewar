/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intoposnomin_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:41:41 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:41:43 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_intoposmin_pzp(t_printf **format, char *outc)
{
	char	*dec;
	char	*pz;

	dec = ft_genchar('0', (*format)->precision - (int)ft_strlen(outc) - 1);
	if ((*format)->flag[2] == '#' && outc[0] != '0')
		pz = ft_genchar('0', 1);
	else
		pz = ft_genchar('\0', 1);
	pz = ft_strjoin_free_12(pz, dec);
	outc = ft_strjoin_free_12(pz, outc);
	dec = ft_genchar(' ', (*format)->width - ft_strlen(outc));
	outc = ft_strjoin_free_12(dec, outc);
	(*format)->buf = ft_strjoin_free_12((*format)->buf, outc);
}

static char	*ft_intoposmin_pz1(t_printf **format, char *outc)
{
	char	*dec;
	char	*pz;

	if ((*format)->flag[4] == '0')
		dec = ft_genchar('0', (*format)->width - (int)ft_strlen(outc) - 1);
	else
		dec = ft_genchar_s(' ', (*format)->width - (int)ft_strlen(outc) - 1);
	if ((*format)->flag[2] == '#' && outc[0] != '0')
		pz = ft_genchar('0', 1);
	else
		pz = ft_genchar('0', 1);
	if (outc[0] == '0')
		outc[0] = '\0';
	pz = ft_strjoin_free_02(dec, pz);
	outc = ft_strjoin_free_12(pz, outc);
	return (outc);
}

static void	ft_intoposmin_pz(t_printf **format, char *outc)
{
	char	*dec;
	char	*pz;

	if ((*format)->precision > (int)ft_strlen(outc))
	{
		ft_intoposmin_pzp(format, outc);
		return ;
	}
	if ((*format)->precision >= 0 && (*format)->precisiondef >= 0)
	{
		dec = ft_genchar(' ', (*format)->width - (int)ft_strlen(outc) - 1);
		if ((*format)->flag[2] == '#' && outc[0] != '0')
			pz = ft_genchar('0', 1);
		else
			pz = ft_genchar('\0', 1);
		outc = ft_strjoin_free_12(pz, outc);
		outc = ft_strjoin_free_12(dec, outc);
	}
	else
		outc = ft_intoposmin_pz1(format, outc);
	(*format)->buf = ft_strjoin_free_12((*format)->buf, outc);
}

void		ft_intoposnomin_1(t_printf **format, char *outc)
{
	char	*dec;

	if ((*format)->flag[2] != '\0')
	{
		ft_intoposmin_pz(format, outc);
		return ;
	}
	if ((*format)->precision >= 0 && (*format)->precisiondef >= 0)
	{
		if (outc[0] == '0')
			outc[0] = '\0';
		dec = ft_genchar(' ', (*format)->width - (int)ft_strlen(outc));
		outc = ft_strjoin_free_12(dec, outc);
	}
	else
	{
		if ((*format)->flag[4] == '0')
			dec = ft_genchar('0', (*format)->width - (int)ft_strlen(outc));
		else
			dec = ft_genchar_s(' ', (*format)->width - (int)ft_strlen(outc));
		outc = ft_strjoin_free_02(dec, outc);
	}
	(*format)->buf = ft_strjoin_free_12((*format)->buf, outc);
}
