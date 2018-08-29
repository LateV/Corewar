/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:47:02 by oskulska          #+#    #+#             */
/*   Updated: 2017/11/09 15:47:04 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	current = *alst;
	while (current != NULL)
	{
		del((current)->content, (current)->content_size);
		free(current);
		current = current->next;
	}
	*alst = NULL;
}
