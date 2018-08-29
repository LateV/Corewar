/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:30:08 by oskulska          #+#    #+#             */
/*   Updated: 2017/11/09 16:30:10 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *current;
	t_list *result;
	t_list *tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	current = lst;
	result = malloc(sizeof(t_list));
	if (result == NULL)
		return (NULL);
	result = f(current);
	tmp = result;
	current = current->next;
	while (current != NULL)
	{
		tmp->next = malloc(sizeof(t_list));
		if (tmp->next == NULL)
			return (NULL);
		tmp->next = f(current);
		current = current->next;
		tmp = tmp->next;
	}
	return (result);
	free(lst);
}
