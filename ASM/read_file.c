/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:35:11 by oskulska          #+#    #+#             */
/*   Updated: 2018/09/18 15:18:06 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_to_list(int num, char *line, t_header **header)
{
	t_command	*node;
	char		*str;

	str = ft_strtrim(line);
	if (ft_strnstr(str, NAME_CMD_STRING, 5))
	{
		if ((*header)->bot_name != NULL)
			error_cases(14, header, num);
		(*header)->bot_name = str;
		(*header)->name_line = num;
	}
	else if (ft_strnstr(str, COMMENT_CMD_STRING, 8))
	{
		if ((*header)->comment != NULL)
			error_cases(15, header, num);
		(*header)->comment = str;
		(*header)->cmt_line = num;
	}
	else
	{
		node = create_new_node(num, str);
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
		tmp = tmp->next;
	tmp->next = new_node;
}

int		skip_comment(char *str)
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
	if ((fd = open(str, O_RDONLY)) < 0)
		error_exit("Can't open a file", str);
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
		error_exit("Error,", "empty file");
	(*header)->file_name = ft_strdup(str);
	validate_params(header);
	count_pointer(*header);
	write_to_file(*header);
}
