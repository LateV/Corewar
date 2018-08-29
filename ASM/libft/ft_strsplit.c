/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:32:29 by oskulska          #+#    #+#             */
/*   Updated: 2017/11/13 15:33:58 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_copy(char const *s, char **res, char c, int n)
{
	int	i;
	int	k;
	int	j;
	int l;

	i = 0;
	j = 0;
	while (i < n)
	{
		while (s[j] == c)
			j++;
		if (s[j])
		{
			l = ft_l(&s[j], c);
			if ((res[i] = (char*)malloc(sizeof(char) * (l + 1))) == NULL)
				return ;
			res[i][l] = '\0';
			k = 0;
			while (k < l)
				res[i][k++] = s[j++];
		}
		i++;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		n;

	if (s == NULL)
		return (NULL);
	n = ft_w(s, c);
	res = (char**)malloc(sizeof(char*) * (n + 1));
	if (res == NULL)
	{
		free(res);
		return (NULL);
	}
	res[n] = NULL;
	ft_copy(s, res, c, n);
	return (res);
}
