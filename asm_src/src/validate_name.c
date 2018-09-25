/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:21:31 by oskulska          #+#    #+#             */
/*   Updated: 2018/09/13 19:21:34 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		validate_name_and_cmt(t_header **header, char *type, int num)
{
	char	*str;
	int		len;

	len = ft_strlen(type);
	if ((*header)->bot_name == NULL)
		error_cases(11, header, 0);
	if ((*header)->comment == NULL)
		error_cases(12, header, 0);
	if (len == (int)ft_strlen(NAME_CMD_STRING))
		str = (*header)->bot_name;
	else
		str = (*header)->comment;
	if (ft_strnstr(str, type, len))
	{
		if (check_quotes(str) == 1)
			error_cases(1, header, num);
		while (str[len] && str[len] != '"')
		{
			if (str[len] && str[len] != ' ' && str[len] != '\t')
				error_cases(2, header, num);
			len++;
		}
	}
	else
		error_cases(3, header, num);
}

void		fill_name_and_cmt(t_header **header)
{
	char **arr;

	arr = ft_strsplit((*header)->bot_name, '"');
	free((*header)->bot_name);
	if (arr[1])
		(*header)->bot_name = ft_strdup(arr[1]);
	else
		(*header)->bot_name = ft_strdup("");
	ft_clear(arr);
	(*header)->name__len = (int)ft_strlen((*header)->bot_name);
	arr = ft_strsplit((*header)->comment, '"');
	free((*header)->comment);
	if (arr[1])
		(*header)->comment = ft_strdup(arr[1]);
	else
		(*header)->comment = ft_strdup("");
	(*header)->comment_len = (int)ft_strlen((*header)->comment);
	ft_clear(arr);
}

int			special_char_pos(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == DIRECT_CHAR ||
			s[i] == LABEL_CHAR || s[i] == '\t')
			return (i);
		i++;
	}
	return (0);
}

int			find_cmd(t_command **node)
{
	int		i;
	int		c;
	char	*str;

	i = 0;
	c = special_char_pos((*node)->line);
	if (c == 0)
		return (1);
	str = ft_strsub((*node)->line, 0, c);
	while (i < 17)
	{
		if (ft_strequ(str, g_cmd_def[i].name))
		{
			(*node)->command_name = g_cmd_def[i].name;
			(*node)->size = 1;
			(*node)->label_size = g_cmd_def[i].label_size;
			(*node)->is_codage_octal = g_cmd_def[i].codage_octal;
			(*node)->opcode = g_cmd_def[i].opcode;
			free(str);
			return (1);
		}
		i++;
	}
	free(str);
	return (-1);
}

int			find_command(t_command **node)
{
	char	*string;
	int		pos;
	int		len;

	len = (int)ft_strlen((*node)->line);
	pos = special_char_pos((*node)->line);
	if (len > 0 && find_cmd(node) == -1)
		return (-1);
	else
	{
		string = ft_strsub((*node)->line, pos, len - pos);
		free((*node)->line);
		(*node)->line = ft_strtrim(string);
		free(string);
	}
	return (1);
}
