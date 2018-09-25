/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:41:16 by oskulska          #+#    #+#             */
/*   Updated: 2018/09/13 19:41:27 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_coma(t_command **node, t_header **header)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	s = (*node)->line;
	if (s[i] == SEPARATOR_CHAR)
		error_cases(6, header, (*node)->num);
	while (s[i])
	{
		if (s[i] == SEPARATOR_CHAR)
			j++;
		i++;
	}
	if (j > 2 || (i > 0 && s[i - 1] == SEPARATOR_CHAR))
		error_cases(6, header, (*node)->num);
}

static int	check_t_int(char *str, int k, t_command *node, int type)
{
	int i;

	i = 0;
	if (check_for_digit(str) != -1 ||
		(str[i] == '-' && check_for_digit(str + 1) != -1))
	{
		node->num_arg[k] = ft_atol(str);
		node->arg_type[k] = type;
		return (1);
	}
	else if (str[i] && str[i] == LABEL_CHAR)
	{
		if (is_label_char(str + 1) == -1)
			return (-1);
		node->arg_pointer[k] = ft_strdup(str + 1);
		node->arg_type[k] = type;
		return (1);
	}
	return (-1);
}

static	int	check_t_dir(char *str, int k, t_command *node, int type)
{
	int i;

	i = 0;
	if (ft_isdigit(str[i]) || str[i] == '-')
	{
		node->num_arg[k] = ft_atol(str);
		node->arg_type[k] = type;
		if (str[i] == '-')
			str++;
		if (check_for_digit(str) == -1)
			return (-1);
		return (1);
	}
	else if (str[i] && str[i] == LABEL_CHAR)
	{
		if (is_label_char(str + 1) == -1)
			return (-1);
		node->arg_pointer[k] = ft_strdup(str + 1);
		node->arg_type[k] = type;
		return (1);
	}
	return (-1);
}

int			find_arg_type(char *str, t_command *tmp, int k)
{
	int i;

	i = 0;
	if (str[i] == 'r')
	{
		if (check_for_digit(str + 1) == -1)
			return (-1);
		tmp->arg_type[k] = 1;
		tmp->num_arg[k] = ft_atol(str + 1);
		if (tmp->num_arg[k] <= 0 || tmp->num_arg[k] > REG_NUM)
			return (-1);
		return (1);
	}
	if (str[i] == DIRECT_CHAR)
		return (check_t_dir(str + 1, k, tmp, 2));
	if (check_for_digit(str) != -1 || (str[i] == LABEL_CHAR)
		|| (str[i] == '-' && check_for_digit(str + 1) != -1))
		return (check_t_int(str, k, tmp, 3));
	return (-1);
}

void		split_line_for_arg(t_command **node, t_header **header)
{
	char	**arr;
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	check_coma(node, header);
	arr = ft_strsplit((*node)->line, SEPARATOR_CHAR);
	while (arr[i])
	{
		if (str)
			free(str);
		str = ft_strtrim(arr[i]);
		if (find_arg_type(str, *node, i) < 0)
		{
			ft_clear(arr);
			free(str);
			error_cases(6, header, (*node)->num);
		}
		i++;
	}
	ft_clear(arr);
	free(str);
}
