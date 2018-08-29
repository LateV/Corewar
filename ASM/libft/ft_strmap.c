/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:10:02 by oskulska          #+#    #+#             */
/*   Updated: 2017/11/03 17:10:14 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;
	int		len;
	int		k;

	i = 0;
	k = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[k] = f(s[i]);
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}
