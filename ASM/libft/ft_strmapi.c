/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:05:20 by oskulska          #+#    #+#             */
/*   Updated: 2017/11/03 17:05:22 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		str[k] = f(i, s[i]);
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}
