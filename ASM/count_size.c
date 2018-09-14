/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:34:39 by oskulska          #+#    #+#             */
/*   Updated: 2018/09/13 19:34:41 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	count_opcode(t_command *node)
{
	int a;
	int b;
	int c;
	int i;

	i = -1;
	while (++i < 3)
	{
		if (node->arg_type[i] == T_REG)
			node->byte_sum[i] = 1;
		if (node->arg_type[i] == T_DIR)
			node->byte_sum[i] = node->label_size;
		if (node->arg_type[i] == T_IND)
			node->byte_sum[i] = 2;
		node->size += node->byte_sum[i];
	}
	if (node->is_codage_octal == 1)
	{
		a = node->arg_type[0] << 6;
		b = node->arg_type[1] << 4;
		c = node->arg_type[2] << 2;
		node->codage_octal = a | b | c;
		node->size += 1;
	}
	else
		node->codage_octal = -1;
}

static	t_command	*find_curr_list(t_command *copy, char *str)
{
	while (copy)
	{
		if (ft_strequ(copy->label, str))
			break ;
		copy = copy->next;
	}
	return (copy);
}

static	void	count_forward(t_command *tmp, int i)
{
	t_command *copy;

	copy = tmp;
	while (copy)
	{
		if (ft_strequ(copy->label, tmp->arg_pointer[i]))
			break ;
		else
			tmp->num_arg[i] += copy->size;
		copy = copy->next;
	}
}

static	void	count_backward(t_command *copy, t_command *tmp, int i)
{
	while (copy)
	{
		if (copy->num == tmp->num)
			break ;
		else
			tmp->num_arg[i] += copy->size;
		copy = copy->next;
	}
    if (tmp->label_size == 2)
        tmp->num_arg[i] = 0xffff - tmp->num_arg[i] + 1;
    else
        tmp->num_arg[i] = 0xffffffff - tmp->num_arg[i] + 1;
}

void	count_pointer(t_header *node)
{
	int			i;
	t_command	*tmp;
	t_command	*copy;

	tmp = node->cmd_list;
	while (tmp)
	{
		i = -1;
		while (++i < 3)
			if (tmp->arg_pointer[i])
			{
				copy = find_curr_list(node->cmd_list, tmp->arg_pointer[i]);
				if (copy && tmp->num < copy->num)
					count_forward(tmp, i);
				else
					count_backward(copy, tmp, i);
			}
		node->prog_size += tmp->size;
		tmp = tmp->next;
	}
}
