/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pput_wchar_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:48:36 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/17 16:48:38 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static wchar_t	*ft_item(t_printf **format, wchar_t *s)
{
	wchar_t	*new;
	int		i;

	i = 0;
	new = (wchar_t*)malloc(sizeof(wchar_t) * ft_wandc_len(s));
	ft_memset(new, '\0', ft_wandc_len(s));
	new[ft_wandc_len(s)] = '\0';
	while ((*format)->precision >= ft_wchar_len(s[i]) + ft_wandc_len(new))
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static void		ft_putiknomin_zero(t_printf **format, wchar_t *s)
{
	wchar_t	*i;
	char	*str;

	if ((*format)->precision < ft_wandc_len(s) && (*format)->precisiondef >= 0)
	{
		i = ft_item(format, s);
		ft_putstr(str = ft_genchar('0', (*format)->width - ft_wandc_len(i)));
		ft_put_wcharstr(i);
		(*format)->num = (*format)->num + ft_wandc_len(i);
		(*format)->num = (*format)->num + ((*format)->width - ft_wandc_len(i));
		free(str);
		free(i);
		return ;
	}
	else
	{
		ft_putstr(str = ft_genchar('0', (*format)->width - ft_wandc_len(s)));
		ft_put_wcharstr(s);
		(*format)->num = (*format)->num + ft_wandc_len(s);
		if ((*format)->width - ft_wandc_len(s) > 0)
			(*format)->num = (*format)->num +
		((*format)->width - ft_wandc_len(s));
		free(str);
		return ;
	}
}

static void		ft_putiknomin(t_printf **format, wchar_t *s)
{
	wchar_t	*i;
	char	*str;

	if ((*format)->precision < ft_wandc_len(s) && (*format)->precisiondef >= 0)
	{
		i = ft_item(format, s);
		ft_putstr(str = ft_genchar(' ', (*format)->width - ft_wandc_len(i)));
		ft_put_wcharstr(i);
		(*format)->num = (*format)->num + ft_wandc_len(i);
		(*format)->num = (*format)->num + ft_strlen(str);
		free(i);
	}
	else
	{
		ft_putstr(str = ft_genchar(' ', (*format)->width - ft_wandc_len(s)));
		ft_put_wcharstr(s);
		(*format)->num = (*format)->num + ft_wandc_len(s);
		if ((*format)->width - ft_wandc_len(s) > 0)
			(*format)->num = (*format)->num +
		((*format)->width - ft_wandc_len(s));
	}
	free(str);
}

static void		ft_putikmin(t_printf **format, wchar_t *s)
{
	wchar_t	*i;
	char	*str;

	if ((*format)->precision < ft_wandc_len(s) && (*format)->precision >= 0)
	{
		i = ft_item(format, s);
		ft_put_wcharstr(i);
		ft_putstr(str = ft_genchar(' ', (*format)->width - ft_wandc_len(i)));
		(*format)->num = (*format)->num + ft_wandc_len(i);
		(*format)->num = (*format)->num + ((*format)->width - ft_wandc_len(i));
		free(str);
		free(i);
		return ;
	}
	else
	{
		ft_put_wcharstr(s);
		ft_putstr(str = ft_genchar(' ', (*format)->width - ft_wandc_len(s)));
		(*format)->num = (*format)->num + ft_wandc_len(s);
		if ((*format)->width - ft_wandc_len(s) > 0)
			(*format)->num = (*format)->num +
		((*format)->width - ft_wandc_len(s));
		free(str);
		return ;
	}
}

void			ft_pput_wchar_str(t_printf **format, va_list argum)
{
	wchar_t	*s;

	if ((*format)->precision < 0)
		(*format)->precisiondef = -1;
	s = va_arg(argum, wchar_t*);
	if (s == NULL)
	{
		ft_pputstrik(format, "(null)");
		return ;
	}
	if ((*format)->width < 0)
		(*format)->width = 0;
	(*format)->num = (*format)->num + ft_strlen((*format)->buf);
	write(1, (*format)->buf, ft_strlen((*format)->buf));
	free((*format)->buf);
	(*format)->buf = ft_strdup("");
	if ((*format)->flag[0] == '-')
		ft_putikmin(format, s);
	else if ((*format)->flag[0] != '-' && (*format)->flag[4] != '\0')
		ft_putiknomin_zero(format, s);
	else
		ft_putiknomin(format, s);
}
