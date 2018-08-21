/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:40:46 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:40:47 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_convert(unsigned long long n)
{
	if ((n > 0 && n <= 9) || n == 0)
		return ('0' + n);
	else if (n >= 10 && n <= 35)
		return ('a' + n - 10);
	else
		return (0);
}

char		*ft_itoa_base(unsigned long long num, int base)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 70;
	str = (char*)malloc(sizeof(char) * i--);
	str = ft_memset(str, ' ', 70);
	str[70] = '\0';
	while (num >= (unsigned long long)base)
	{
		str[i--] = ft_convert(num % base);
		num = num / base;
	}
	str[i] = ft_convert(num % base);
	tmp = ft_strtrim(str);
	free(str);
	str = tmp;
	return (str);
}
