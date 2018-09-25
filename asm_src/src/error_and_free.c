/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:34:50 by oskulska          #+#    #+#             */
/*   Updated: 2018/09/13 19:34:52 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_def_error	g_error_def[18] =
{
	{1, "Not correct quotes."},
	{2, "Syntax error."},
	{3, "Error command."},
	{4, "invalid command param"},
	{5, "Label name should consist only LABEL_CHARS"},
	{6, "Not correct argument for command."},
	{7, "Champion name should not be longer than PROG_NAME_LENGTH."},
	{8, "Comment should not be longer than COMMENT_LENGTH."},
	{9, "Not correct arguments type for instruction."},
	{10, "Label for pointer does not exist."},
	{11, "No Champion name."},
	{12, "No comment."},
	{13, "Label with this name already exist."},
	{14, "Field .name already exist."},
	{15, "Field .comment already exist."},
	{16, "Field .comment should be before command."},
	{17, "Field .name should be before command."},
	{18, "Bot is too short, to be a Champion."}
};

void		error_cases(int k, t_header **header, int line)
{
	int i;

	i = 0;
	while (i < 18)
	{
		if (g_error_def[i].num == k)
		{
			ft_printf("%s On line %d.\n", g_error_def[i].str, line);
			ft_free(header);
			free(*header);
			system("leaks asm");
			exit(0);
		}
		i++;
	}
}

void		ft_clear(char **arr)
{
	size_t	count;

	count = 0;
	while (arr[count])
	{
		free(arr[count]);
		arr[count] = NULL;
		count++;
	}
	free(arr);
	arr = NULL;
}

void		ft_free(t_header **header)
{
	t_command	*tmp;
	int			i;

	tmp = (*header)->cmd_list;
	if ((*header)->comment)
		free((*header)->comment);
	if ((*header)->bot_name)
		free((*header)->bot_name);
	if ((*header)->curr_label)
		free((*header)->curr_label);
	if ((*header)->file_name)
		free((*header)->file_name);
	while (tmp)
	{
		i = -1;
		while (++i < 3)
			if (tmp->arg_pointer[i])
				free(tmp->arg_pointer[i]);
		if (tmp->line)
			free(tmp->line);
		if (tmp->label)
			free(tmp->label);
		free(tmp);
		tmp = tmp->next;
	}
}

void		error_exit(char *str, const char *arg)
{
	ft_printf("%s %s.\n", str, arg);
	system("leaks asm");
	exit(0);
}
