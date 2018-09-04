/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:34:56 by vibondar          #+#    #+#             */
/*   Updated: 2017/11/08 18:34:58 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*current;

	tmp = *alst;
	current = *alst;
	while (tmp)
	{
		current = tmp;
		tmp = tmp->next;
		del(current->content, current->content_size);
		free(current);
	}
	*alst = NULL;
}
