/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:45:22 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/20 20:45:23 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline	static	void	cor_format(t_cor *cor, char *path)
{
	int					i;

	i = ft_strlen(path);
	if (i - 5 > 0)
	{
		if (ft_strcmp(path + i - 4, ".cor") != 0)
		{
			ft_putstr("Can't read source file (missing .cor) ");
			ft_error(cor, path);
		}
		cor->player[cor->p_num].file_path = path;
	}
	else
	{
		ft_putstr("Can't read source file ");
		ft_error(cor, path);
	}
	if (cor->p_num > 3)
		ft_error(cor, "Error: max 4 players");
}

inline static	void	calculate_p_num(t_cor *cor)
{
	if (cor->p_num > 3)
		ft_error(cor, "Error: max 4 players");
	if (cor->flag_p_num != -1)
	{
		cor->player[cor->p_num].num = cor->flag_p_num;
		cor->curr_pl = cor->player[cor->p_num].num;
		cor->flag_p_num = -1;
		cor->p_num++;
	}
	else
	{
		cor->player[cor->p_num].num = -2;
		cor->p_num++;
	}
}

void					manage_files(t_cor *cor, char *argv)
{
	cor_format(cor, argv);
	calculate_p_num(cor);
}
