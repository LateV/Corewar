/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdnolen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:37:06 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:37:07 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_ppupadmin_1(t_printf **format, char *outc)
{
	char	*dec;
	char	*pz;

	pz = ft_genchar_x(format);
	if ((*format)->precision >= 0 && (*format)->precisiondef >= 0)
	{
		if (outc[0] == '0')
			outc[0] = '\0';
		dec = ft_genchar(' ', (*format)->width - (int)ft_strlen(outc) - 2);
		outc = ft_strjoin_free_12(pz, outc);
		outc = ft_strjoin_free_12(outc, dec);
	}
	else
	{
		dec = ft_genchar(' ', (*format)->width - (int)ft_strlen(outc) - 2);
		outc = ft_strjoin_free_12(pz, outc);
		outc = ft_strjoin_free_12(outc, dec);
	}
	(*format)->buf = ft_strjoin_free_12((*format)->buf, outc);
}

static void	ft_ppupadnomin_1(t_printf **format, char *outc)
{
	char	*dec;
	char	*pz;

	pz = ft_genchar_x(format);
	if ((*format)->precision >= 0 && (*format)->precisiondef >= 0)
	{
		if (outc[0] == '0')
			outc[0] = '\0';
		dec = ft_genchar(' ', (*format)->width - (int)ft_strlen(outc) - 2);
		dec = ft_strjoin_free_12(dec, pz);
		outc = ft_strjoin_free_12(dec, outc);
	}
	else
		outc = ft_ppupadnomin_11(format, outc);
	(*format)->buf = ft_strjoin_free_12((*format)->buf, outc);
}

static void	ft_ppupadmin(t_printf **format, char *outc)
{
	char	*dec;

	if ((*format)->precision > (int)ft_strlen(outc) &&
		(*format)->flag[3] == '\0' && (*format)->flag[1] == '\0')
	{
		dec = ft_genchar('0', (*format)->precision - ft_strlen(outc));
		outc = ft_strjoin_free_12(dec, outc);
		if ((*format)->width > (int)ft_strlen(outc))
		{
			dec = ft_genchar(' ', (*format)->width - ft_strlen(outc));
			outc = ft_strjoin_free_12(outc, dec);
		}
		(*format)->buf = ft_strjoin_free_12((*format)->buf, outc);
		return ;
	}
	ft_ppupadmin_1(format, outc);
}

static void	ft_ppupadnomin(t_printf **format, char *outc)
{
	char	*dec;
	char	*pz;

	if ((*format)->precision > (int)ft_strlen(outc))
	{
		pz = ft_genchar_x(format);
		dec = ft_genchar('0', (*format)->precision - ft_strlen(outc));
		dec = ft_strjoin_free_12(pz, dec);
		outc = ft_strjoin_free_12(dec, outc);
		if ((*format)->width > (int)ft_strlen(outc))
		{
			dec = ft_genchar(' ', (*format)->width - ft_strlen(outc));
			outc = ft_strjoin_free_12(dec, outc);
		}
		(*format)->buf = ft_strjoin_free_12((*format)->buf, outc);
		return ;
	}
	ft_ppupadnomin_1(format, outc);
}

void		ft_ppupad(t_printf **format, char *outc)
{
	if ((*format)->flag[0] == '-')
		ft_ppupadmin(format, outc);
	else
		ft_ppupadnomin(format, outc);
	(*format)->num = (*format)->num + ft_strlen((*format)->buf);
	write(1, (*format)->buf, ft_strlen((*format)->buf));
	free((*format)->buf);
	(*format)->buf = ft_strdup("");
}
