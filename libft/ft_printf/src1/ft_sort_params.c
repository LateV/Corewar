/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:40:03 by oskulska          #+#    #+#             */
/*   Updated: 2017/11/17 17:40:12 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sort_params(int argc, char **argv)
{
	int		i;
	char	*tmp;
	int		is_swap;

	is_swap = 1;
	while (is_swap)
	{
		is_swap = 0;
		i = 1;
		while (argc > i + 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				tmp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = tmp;
				is_swap = 1;
			}
			i++;
		}
	}
}
