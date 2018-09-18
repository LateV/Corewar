/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:27:47 by oskulska          #+#    #+#             */
/*   Updated: 2018/09/13 19:27:50 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	validate_label(t_header **header)
{
	t_command *tmp;

	tmp = (*header)->cmd_list;
	while (tmp)
	{
		skip_comments(tmp);
		if (check_label_chars(tmp) == -1)
			error_cases(5, header, tmp->num);
		else if (check_label_chars(tmp) == 1)
		{
			find_curr_label(header, tmp);
			if (find_command(&tmp) == -1)
			    error_cases(3,header,tmp->num);
		}
		if (tmp->label == NULL && (*header)->curr_label)
			tmp->label = ft_strdup((*header)->curr_label);
		split_line_for_arg(&tmp, header);
		count_opcode(tmp);
		tmp = tmp->next;
	}
}

int	check_label_chars(t_command *node)
{
	int		i;
	char	*str;

	i = -1;
	str = node->line;
	while (str[++i])
		if (str[i] == LABEL_CHAR)
		{
			if (str[i - 1] && (ft_isspace(str[i - 1]) || str[i - 1] == DIRECT_CHAR || str[i - 1] == SEPARATOR_CHAR))
			{
				if (find_command(&node) == -1)
					return (-1);
				return (0);
			}
			else if(ft_strchr(LABEL_CHARS,str[i-1]))
			{
				while (--i > 0)
					if (!ft_strchr(LABEL_CHARS, str[i]))
						return (-1);
				return (1);
			}
			else
                return (-1);
		}
	return (1);
}

void	validate_params(t_header **header)
{
	validate_name_and_cmt(header, NAME_CMD_STRING, (*header)->name_line);
	validate_name_and_cmt(header, COMMENT_CMD_STRING, (*header)->cmt_line);
	fill_name_and_cmt(header);
	validate_label(header);
	check_all_param(*header);
}

void	same_label(t_header **header, char *str)
{
	t_command *tmp;

	tmp = (*header)->cmd_list;
	while (tmp)
	{
		if (ft_strequ(tmp->label, str))
			error_cases(13, header, tmp->num);
		tmp = tmp->next;
	}
}

void	find_curr_label(t_header **header, t_command *node)
{
	int		i;
	char	*str;
	char	*s;

	if ((i = char_pos(node->line, ':')) > 0)
	{
		if ((*header)->curr_label)
			free((*header)->curr_label);
		str = ft_strdup(node->line);
		free(node->line);
		s = ft_strsub(str, i + 1, ft_strlen(str) - i);
		node->line = ft_strtrim(s);
		(*header)->curr_label = ft_strsub(str, 0, i);
		free(s);
		same_label(header, (*header)->curr_label);
		node->label = ft_strsub(str, 0, i);
		free(str);
	}
}
