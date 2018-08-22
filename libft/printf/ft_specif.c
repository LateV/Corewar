/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:22:31 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/02 14:22:33 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_specif_fill(t_printf **format, char *str, int i, va_list argum)
{
	char	*formatic;

	formatic = ft_strdup("*.ljhztL-+#0 123456789");
	while (ft_strchr(formatic, str[i]) != NULL && str[i] != '\0')
	{
		if (ft_strchr("-+#0 ", str[i]) != NULL)
			i = ft_format_flag(i, "-+#0 ", str, format);
		else if (ft_isdigit(str[i]) || str[i] == '*')
			i = ft_format_width(i, str, format, argum);
		else if (str[i] == '.')
			i = ft_format_precision(i, format, str, argum);
		else if (ft_strchr("ljhztL", str[i]) != NULL)
			i = ft_format_length(i, "ljhztL", str, format);
	}
	free(formatic);
	return (i);
}

int			ft_specif(t_printf **format, char *str, int i, va_list argum)
{
	i = ft_specif_fill(format, str, i, argum);
	if (ft_strchr("sSpdDioOuUxXcC", str[i]) != NULL && str[i] != '\0')
		i = ft_format_type(i, str, format);
	else if (str[i] == '%')
	{
		(*format)->type[0] = str[i];
		i++;
	}
	else if (str[i] == '\0')
	{
		(*format)->type[0] = '\0';
		(*format)->invalid = 1;
	}
	else if (str[i] != '\0')
	{
		ft_pputcharik(format, str[i]);
		i++;
	}
	return (i);
}
