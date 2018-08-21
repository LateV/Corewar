/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:35:40 by vibondar          #+#    #+#             */
/*   Updated: 2018/07/16 15:35:42 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *tmp;

	tmp = *alst;
	if (alst != NULL && new != NULL)
	{
		if (*alst == NULL)
		{
			*alst = new;
			return ;
		}
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
