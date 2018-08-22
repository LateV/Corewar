/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intoposmin_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:41:34 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:41:35 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_intoposmin_pzp(t_printf **format, char *outc)
{
	char	*dec;
	char	*pz;

	dec = ft_genchar('0', (*format)->precision - (int)ft_strlen(outc) - 1);
	if ((*format)->flag[2] == '#')
		pz = ft_genchar('0', 1);
	else
		pz = ft_genchar('\0', 1);
	pz = ft_strjoin_free_12(pz, dec);
	outc = ft_strjoin_free_12(pz, outc);
	dec = ft_genchar(' ', (*format)->width - ft_strlen(outc));
	outc = ft_strjoin_free_12(outc, dec);
	(*format)->buf = ft_strjoin_free_12((*format)->buf, outc);
}

static char	*ft_intoposmin_pz1(t_printf **format, char *outc)
{
	char	*dec;
	char	*pz;

	dec = ft_genchar(' ', (*format)->width - (int)ft_strlen(outc));
	if ((*format)->flag[2] == '#')
		pz = ft_genchar('0', 1);
	else
		pz = ft_genchar('\0', 1);
	outc = ft_strjoin_free_12(pz, outc);
	outc = ft_strjoin_free_12(outc, dec);
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
	if ((*format)->precision >= 0)
	{
		dec = ft_genchar(' ', (*format)->width - (int)ft_strlen(outc) - 1);
		if ((*format)->flag[2] == '#')
			pz = ft_genchar('0', 1);
		else
			pz = ft_genchar('\0', 1);
		outc = ft_strjoin_free_12(pz, outc);
		outc = ft_strjoin_free_12(outc, dec);
	}
	else
		outc = ft_intoposmin_pz1(format, outc);
	(*format)->buf = ft_strjoin_free_12((*format)->buf, outc);
}

void		ft_intoposmin_1(t_printf **format, char *outc)
{
	char	*dec;

	if ((*format)->flag[2] != '\0')
	{
		ft_intoposmin_pz(format, outc);
		return ;
	}
	if ((*format)->precision >= 0)
	{
		dec = ft_genchar(' ', (*format)->width - (int)ft_strlen(outc));
		outc = ft_strjoin_free_12(outc, dec);
		dec = ft_genchar(' ', ft_strlen(outc) - (*format)->width);
		outc = ft_strjoin_free_12(outc, dec);
	}
	else
	{
		if ((*format)->flag[4] == '0')
			dec = ft_genchar('0', (*format)->width - (int)ft_strlen(outc));
		else
			dec = ft_genchar(' ', (*format)->width - (int)ft_strlen(outc));
		outc = ft_strjoin_free_12(outc, dec);
		dec = ft_genchar(' ', ft_strlen(outc) - (*format)->width);
		outc = ft_strjoin_free_12(outc, dec);
	}
	(*format)->buf = ft_strjoin_free_12((*format)->buf, outc);
}
