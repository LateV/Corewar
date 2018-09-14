/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:35:11 by oskulska          #+#    #+#             */
/*   Updated: 2018/09/13 19:35:12 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_to_list(int num, char *line, t_header **header)
{
	t_command *node;

	if (ft_strstr(line, NAME_CMD_STRING))
	{
		if ((*header)->bot_name != NULL)
			error_exit("double name\n");
		(*header)->bot_name = ft_strtrim(line);
	}
	else if (ft_strstr(line, COMMENT_CMD_STRING))
	{
		if ((*header)->comment != NULL)
			error_exit("double comment\n");
		(*header)->comment = ft_strtrim(line);
	}
	else
	{
		node = create_new_node(num, ft_strtrim(line));
		push_back(header, node);
	}
}

void	push_back(t_header **header, t_command *new_node)
{
	t_command *tmp;

	tmp = (*header)->cmd_list;
	if ((*header)->cmd_list == NULL)
	{
		(*header)->cmd_list = new_node;
		return ;
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new_node;
}

int	skip_comment(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0)
	{
		free(str);
		return (1);
	}
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '#' || str[i] == '\0')
	{
		free(str);
		return (1);
	}
	return (0);
}

void	read_file(const char *str, t_header **header)
{
	int		fd;
	char	*line;
	int		num;
	line = NULL;
	num = 0;
	(*header)->file_name = ft_strdup(str);
	if ((fd = open(str, O_RDONLY)) < 0)
		error_exit(str);
	while (get_next_line(fd, &line) > 0)
	{
		num++;
		if (skip_comment(line))
			continue;
		else
			add_to_list(num, line, header);
		free(line);
	}
	if (line == NULL)
		error_exit("empty file\n");
	validate_params(header);
	count_pointer(*header);
	write_to_file(*header);
}
