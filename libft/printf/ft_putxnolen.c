/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxnolen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:36:39 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:36:40 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_intxposmin(t_printf **format, char *outc)
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
	ft_intxposmin_1(format, outc);
}

static void	ft_intxposnomin(t_printf **format, char *outc)
{
	char	*dec;

	if ((*format)->precision > (int)ft_strlen(outc) &&
		(*format)->flag[2] == '\0')
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
	ft_intxposnomin_1(format, outc);
}

void		ft_putxnolen(t_printf **format, char *outc)
{
	if ((*format)->type[0] == 'X')
		ft_strtoupper(outc);
	if ((*format)->flag[0] == '-')
		ft_intxposmin(format, outc);
	else
		ft_intxposnomin(format, outc);
}
