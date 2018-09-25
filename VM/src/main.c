/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:45:14 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/20 20:45:15 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline static void			init_players(t_cor *cor)
{
	int	i;

	i = 0;
	cor->def_num = 1;
	while (i < 4)
	{
		cor->player[i].num = -1;
		i++;
	}
}

inline static void			def_num2(t_cor *cor, int i)
{
	int	k;

	k = 0;
	cor->def_num = 1;
	while (cor->def_num < 5)
	{
		while (k < 4)
		{
			if (cor->def_num == cor->player[k].num)
				break ;
			k++;
		}
		if (k == 4)
		{
			cor->player[i].num = cor->def_num;
			k = 0;
			break ;
		}
		k = 0;
		cor->def_num++;
	}
}

inline static void			def_num(t_cor *cor)
{
	int	i;

	i = 0;
	cor->def_num = 1;
	while (i < cor->p_num)
	{
		if (cor->player[i].num == -2)
			def_num2(cor, i);
		i++;
	}
}

inline static void			reader(t_cor *cor, int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			j = manage_flags(cor, argv, i);
			if (j > i)
				i++;
			else if (j == -1)
				manage_files(cor, argv[i]);
			i++;
			continue;
		}
		manage_files(cor, argv[i]);
		i++;
	}
}

int							main(int argc, char **argv)
{
	t_cor cor;

	if (argc == 1)
		usadge();
	ft_bzero(&cor, sizeof(t_cor));
	cor.pause = 1;
	cor.proc_num = 1;
	cor.cycles = 1;
	cor.flag_p_num = -1;
	cor.live_check = 1;
	init_players(&cor);
	reader(&cor, argc, argv);
	validate_players(&cor);
	def_num(&cor);
	cor.def_num = 1;
	cor.curr_cycle_t_d = CYCLE_TO_DIE;
	if (cor.p_num == 0)
		usadge();
	to_map(&cor);
	system("leaks -quiet corewar");
	return (0);
}
