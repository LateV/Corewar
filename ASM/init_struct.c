/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:35:00 by oskulska          #+#    #+#             */
/*   Updated: 2018/09/13 19:35:02 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_command	*create_new_node(int num, char *str)
{
	t_command *new_node;

	new_node = ft_memalloc(sizeof(t_command));
	new_node->line = ft_strdup(str);
	free(str);
	new_node->num = num;
	new_node->label_size = 2;
	return (new_node);
}

void		init_struct(t_header **header)
{
	*header = ft_memalloc(sizeof(t_header));
}
