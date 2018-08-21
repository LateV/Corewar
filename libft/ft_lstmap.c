/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:34:29 by vibondar          #+#    #+#             */
/*   Updated: 2017/11/08 18:34:31 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*fresh;
	t_list	*fr_iter;

	if (!lst || !f)
		return (NULL);
	tmp = lst;
	fresh = f(tmp);
	if (fresh == NULL)
		return (NULL);
	fr_iter = fresh;
	while (tmp->next)
	{
		tmp = tmp->next;
		fr_iter->next = f(tmp);
		if (fr_iter->next == NULL)
			return (NULL);
		fr_iter = fr_iter->next;
	}
	return (fresh);
}
