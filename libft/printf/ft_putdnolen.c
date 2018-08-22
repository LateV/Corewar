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

static void	ft_intdposmin(t_printf **format, char *outc)
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
	ft_intdposmin_1(format, outc);
}

static void	ft_intdposnomin(t_printf **format, char *outc)
{
	char	*dec;

	if ((*format)->precision > (int)ft_strlen(outc) &&
		(((*format)->flag[3] == '\0' && (*format)->flag[1] == '\0') ||
			(*format)->type[0] == 'u'))
	{
		dec = ft_genchar('0', (*format)->precision - ft_strlen(outc));
		outc = ft_strjoin_free_12(dec, outc);
		if ((*format)->width > (int)ft_strlen(outc))
		{
			dec = ft_genchar(' ', (*format)->width - ft_strlen(outc));
			outc = ft_strjoin_free_12(dec, outc);
		}
		(*format)->buf = ft_strjoin_free_12((*format)->buf, outc);
		return ;
	}
	ft_intdposnomin_1(format, outc);
}

static void	ft_intdnegmin(t_printf **format, char *outc)
{
	char	*dec;
	char	*neg;

	if ((*format)->precision > (int)ft_strlen(outc))
	{
		neg = ft_genchar('-', 1);
		dec = ft_genchar('0', (*format)->precision - ft_strlen(outc));
		dec = ft_strjoin_free_12(neg, dec);
		outc = ft_strjoin_free_12(outc, dec);
		if ((*format)->width > (int)ft_strlen(outc))
		{
			dec = ft_genchar(' ', (*format)->width - ft_strlen(outc));
			outc = ft_strjoin_free_12(dec, outc);
		}
		(*format)->buf = ft_strjoin_free_12((*format)->buf, outc);
		return ;
	}
	ft_intdnegmin_1(format, outc);
}

static void	ft_intdnegnomin(t_printf **format, char *outc)
{
	char	*dec;
	char	*neg;

	if ((*format)->precision > (int)ft_strlen(outc))
	{
		neg = ft_genchar('-', 1);
		dec = ft_genchar('0', (*format)->precision - ft_strlen(outc));
		dec = ft_strjoin_free_12(neg, dec);
		outc = ft_strjoin_free_12(dec, outc);
		if ((*format)->width > (int)ft_strlen(outc))
		{
			dec = ft_genchar(' ', (*format)->width - ft_strlen(outc));
			outc = ft_strjoin_free_12(dec, outc);
		}
		(*format)->buf = ft_strjoin_free_12((*format)->buf, outc);
		return ;
	}
	ft_intdnegnomin_1(format, outc);
}

void		ft_putdnolen(t_printf **format, char *outc)
{
	char *tmp;

	if ((*format)->sign > 0 && outc[0] != '-')
	{
		if ((*format)->flag[0] == '-')
			ft_intdposmin(format, outc);
		else
			ft_intdposnomin(format, outc);
	}
	else
	{
		tmp = outc;
		outc = ft_strdup(outc + 1);
		if ((*format)->flag[0] == '-')
			ft_intdnegmin(format, outc);
		else
			ft_intdnegnomin(format, outc);
		free(tmp);
	}
	(*format)->buf = (*format)->buf;
	(*format)->num = (*format)->num + ft_strlen((*format)->buf);
	write(1, (*format)->buf, ft_strlen((*format)->buf));
	free((*format)->buf);
	(*format)->buf = ft_strdup("");
}
