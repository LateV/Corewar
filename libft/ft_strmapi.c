/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:32:24 by vibondar          #+#    #+#             */
/*   Updated: 2017/11/02 14:32:25 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*r;

	i = 0;
	if (s && f)
	{
		r = (char*)ft_memalloc(sizeof(char) * (ft_strlen(s) + 1));
		if (r)
		{
			while (s[i] != '\0')
			{
				r[i] = f(i, s[i]);
				i++;
			}
			r[i] = '\0';
			return (r);
		}
	}
	return (NULL);
}
