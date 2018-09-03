/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:41:56 by vibondar          #+#    #+#             */
/*   Updated: 2017/11/06 14:41:57 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_let_num(char const *str, char ch, int i)
{
	int	n;

	n = 0;
	while (str[i + n] != ch && str[i + n])
		n++;
	return (n);
}

static char	*put_word(char const *str, char ch, int *i)
{
	int		j;
	char	*word;

	word = (char *)malloc(sizeof(char) * ft_let_num(str, ch, *i) + 1);
	if (word == NULL)
		return (0);
	j = 0;
	while (str[*i] != '\0' && str[*i] != ch)
	{
		word[j] = str[*i];
		(*i)++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

static int	ft_wn(char *str, char ch)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (str[i] != ch && (str[i + 1] == ch || str[i + 1] == '\0'))
			counter++;
	}
	return (counter);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		k;
	char	**r;

	if (!s || !c)
		return (0);
	i = 0;
	k = 0;
	if ((r = (char **)malloc(sizeof(char *) * ft_wn((char *)s, c) + 1)) == 0)
		return (0);
	while (s[k] != '\0')
	{
		if (s[k] != c)
		{
			if ((r[i++] = put_word(s, c, &k)) == 0)
			{
				ft_memdel((void **)r);
				return (0);
			}
		}
		else
			k++;
	}
	r[i] = 0;
	return (r);
}
