/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putonolen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:36:59 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:37:00 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_intoposmin(t_printf **format, char *outc)
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
	ft_intoposmin_1(format, outc);
}

static void	ft_intoposnomin(t_printf **format, char *outc)
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
	ft_intoposnomin_1(format, outc);
}

void		ft_putonolen(t_printf **format, char *outc)
{
	if ((*format)->flag[0] == '-')
		ft_intoposmin(format, outc);
	else
		ft_intoposnomin(format, outc);
	(*format)->num = (*format)->num + ft_strlen((*format)->buf);
	write(1, (*format)->buf, ft_strlen((*format)->buf));
	free((*format)->buf);
	(*format)->buf = ft_strdup("");
}
