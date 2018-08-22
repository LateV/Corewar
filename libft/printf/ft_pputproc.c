/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputproc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:38:38 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:38:40 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_pputproc(t_printf **format)
{
	char *outc;
	char *proc;

	if ((*format)->flag[4] == '0' && (*format)->flag[0] == '\0')
		outc = ft_genchar('0', (*format)->width - 1);
	else
		outc = ft_genchar(' ', (*format)->width - 1);
	proc = ft_genchar('%', 1);
	if ((*format)->flag[0] == '-')
		outc = ft_strjoin_free_12(proc, outc);
	else
		outc = ft_strjoin_free_12(outc, proc);
	(*format)->buf = ft_strjoin_free_12((*format)->buf, outc);
	(*format)->num = (*format)->num + ft_strlen((*format)->buf);
	write(1, (*format)->buf, ft_strlen((*format)->buf));
	free((*format)->buf);
	(*format)->buf = ft_strdup("");
}
