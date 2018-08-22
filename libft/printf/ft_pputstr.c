/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:37:55 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:37:57 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_flagzero(t_printf **format, char *stroka)
{
	char	*tmp;

	tmp = ft_genchar('0', (*format)->width - (int)ft_strlen(stroka));
	tmp = ft_strjoin_free_12(tmp, stroka);
	(*format)->buf = ft_strjoin_free_12((*format)->buf, tmp);
}

static void	ft_noflagmins(t_printf **format, char *stroka)
{
	char	*tmp;

	if ((*format)->flag[4] == '0')
	{
		ft_flagzero(format, stroka);
		return ;
	}
	tmp = ft_genchar(' ', (*format)->width - (int)ft_strlen(stroka));
	tmp = ft_strjoin_free_12(tmp, stroka);
	(*format)->buf = ft_strjoin_free_12((*format)->buf, tmp);
}

static void	ft_flagmins(t_printf **format, char *stroka)
{
	char	*tmp;

	tmp = ft_genchar(' ', (*format)->width - (int)ft_strlen(stroka));
	tmp = ft_strjoin_free_12(stroka, tmp);
	(*format)->buf = ft_strjoin_free_12((*format)->buf, tmp);
}

static char	*ft_stroka(t_printf **format, char *str)
{
	int		i;
	char	*stroka;

	i = 0;
	if ((*format)->precision > (int)ft_strlen(str) || (*format)->precision < 0)
	{
		stroka = ft_genchar('\0', (int)ft_strlen(str) + 1);
		stroka = ft_strncpy(stroka, str, (int)ft_strlen(str) + 1);
	}
	else
	{
		stroka = ft_genchar('\0', (*format)->precision + 1);
		stroka = ft_strncpy(stroka, str, (*format)->precision);
	}
	return (stroka);
}

void		ft_pputstrik(t_printf **format, char *str)
{
	char	*stroka;

	if (str == NULL)
		stroka = ft_stroka(format, "(null)");
	else
		stroka = ft_stroka(format, str);
	if ((*format)->flag[0] == '-' && str)
		ft_flagmins(format, stroka);
	else
		ft_noflagmins(format, stroka);
	(*format)->num = (*format)->num + ft_strlen((*format)->buf);
	write(1, (*format)->buf, ft_strlen((*format)->buf));
	free((*format)->buf);
	(*format)->buf = ft_strdup("");
}
