/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:34:29 by oskulska          #+#    #+#             */
/*   Updated: 2018/09/13 19:34:31 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	is_correct_pointer(t_command *list, char *pointer)
{
	t_command *tmp;

	tmp = list;
	while (tmp)
	{
		if (ft_strequ(tmp->label, pointer))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	check_arg_for_cmd(char *name, int *arg)
{
	int i;
	int k;

	i = -1;
	k = -1;
	while (++i < 17)
		if (ft_strequ(name, g_cmd_def[i].name))
			break ;
	while (++k < 3)
		if (arg[0] == g_cmd_def[i].first_arg[k])
		{
			k = -1;
			while (++k < 3)
				if (arg[1] == g_cmd_def[i].second_arg[k])
				{
					k = -1;
					while (++k < 2)
						if (arg[2] == g_cmd_def[i].third_arg[k])
							return (1);
				}
		}
	return (0);
}

static int	check_arg_num(char *name, int *arg)
{
	int i;
	int k;
	int sum;

	i = -1;
	k = 0;
	sum = 0;
	while (++i < 17)
		if (ft_strequ(name, g_cmd_def[i].name))
			break ;
	while (k < 3)
	{
		if (arg[k] != 0)
			sum++;
		k++;
	}
	if (sum < g_cmd_def[i].num_of_arg)
		return (0);
	return (1);
}

void		check_all_param(t_header *header)
{
	t_command	*tmp;
	int			i;

	tmp = header->cmd_list;
	if (ft_strlen(header->bot_name) > PROG_NAME_LENGTH)
		error_cases(7, &header, header->name_line);
	if (ft_strlen(header->comment) > COMMENT_LENGTH)
		error_cases(8, &header, header->cmt_line);
	while (tmp)
	{
		if (tmp->opcode > 0)
		{
			if (!check_arg_for_cmd(tmp->command_name, tmp->arg_type)
				|| !check_arg_num(tmp->command_name, tmp->arg_type))
				error_cases(9, &header, tmp->num);
			i = -1;
			while (++i < 3)
				if (tmp->arg_pointer[i] != NULL)
					if (!is_correct_pointer(header->cmd_list,
						tmp->arg_pointer[i]))
						error_cases(10, &header, tmp->num);
		}
		tmp = tmp->next;
	}
}
