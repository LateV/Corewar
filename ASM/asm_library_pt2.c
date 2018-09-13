/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_library_pt2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:34:16 by oskulska          #+#    #+#             */
/*   Updated: 2018/09/13 19:34:18 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Olga SKULSKA on 9/13/18.
//

#include "asm.h"

ssize_t	ft_atol(const char *str)
{
	int			i;
	ssize_t		n;
	ssize_t	    nb;

	i = 0;
	n = 1;
	nb = 0;
	while ((str[i] < 14 && str[i] >= 9) || str[i] == ' ')
		i++;
	if (str[i] == '-' && str[i + 1] <= '9' && str[i + 1] >= '0')
	{
		n = -1;
		i++;
	}
	if (str[i] == '+' && str[i + 1] <= '9' && str[i + 1] >= '0')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		if (nb * 10 + str[i] - '0' < nb)
			return (n == 1 ? -1 : 0);
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * n);
}

void check_coma(t_command **node, t_header **header)
{
	int i;
	int j;
	char *s;

	i = 0;
	j = 0;
	s = (*node)->line;
	while(s[i])
	{
		if(s[i] == ',')
			j++;
		i++;
	}
	if(j > 2)
		error_cases(6,header);
}


void skip_comments(t_command *node)
{
	char *str;
	char *s;
	int i;

	str = node->line;
	if((i = char_pos(str, '#')) > 0)
	{
		s = ft_strsub(str,0,i);
		free(node->line);
		node->line = ft_strdup(s);
		free(s);
	}
}

int check_quotes(char *str)
{
	int i;

	i = -1;
	while(str[++i])
		if(str[i] == '"')
		{
			while (str[++i])
				if(str[i] == '"')
				{
					if(str[++i] == '\0')
						return 0;
					break;
				}
			while (str[i] == ' ')
				i++;
			if(str[i] && (str[i] == ' ' || str[i] == '#' ))
				return 0;
			else
				return 1;
		}
	return 1;
}

