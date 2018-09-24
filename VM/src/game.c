/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:43:11 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/20 20:43:12 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_map(t_cor *cor)
{
	int row;
	int i;

	row = 0;
	i = 0;
	ft_printf("0x0000 : ");
	while (i < MEM_SIZE)
	{
		if (i != 0)
			ft_printf("%#06x : ", i);
		while (row < 64)
		{
			ft_printf("%02x ", cor->arena[i]);
			row++;
			i++;
		}
		ft_printf("\n");
		row = 0;
	}
}

void	flag_output(t_cor *cor)
{
	char buff;

	if (cor->visu == 0 && cor->dump != 0 && cor->cycles == cor->dump)
	{
		print_map(cor);
		exit(0);
	}
	while (cor->s <= cor->cycles && cor->s > 0 && cor->visu == 0 && cor->dump == 0)
	{
		print_map(cor);
		read(0, &buff, 1);
		if (buff == '\n')
			break ;
		else
			exit(0);
	}
}

void	process_activity(t_cor *cor)
{
	t_process *tmp;

	tmp = cor->process;
	while (tmp)
	{
		if (tmp->command == -1)
		{
			if (cor->arena[tmp->pc] > 0 && cor->arena[tmp->pc] < 17)
			{
				tmp->command = cor->arena[tmp->pc] - 1;
				cor->instruct[tmp->command](cor, tmp);
			}
			else
				set_proc_pos(cor, tmp, 1);
		}
		else
			cor->instruct[tmp->command](cor, tmp);
		tmp = tmp->next;
	}
}

void	game(t_cor *cor)
{
	while (69)
	{
		if (cor->visu == 1)
		{
			cor->vizu->key = getch();
			if (cor->vizu->key == 27)
			{
				endwin();
				exit(1);
			}
			v_speed_test(cor, cor->vizu->key);
			breakdown(cor);
			refresher(cor);
			if (cor->vizu->key == 32 && cor->pause == 1)
				cor->pause = 0;
			else if (cor->vizu->key == 32 && cor->pause == 0)
				cor->pause = 1;
			if (cor->cycles > cor->start_from)
			{
				refresh_vizu(cor);
				if (cor->pause == 1 && cor->vizu->key != 10)
					continue;
			}
		}
		else
		{
			if (cor->visu == 0 && cor->dump == 0 && cor->s == 0 && (cor->mon == cor->cycles || cor->log == 1))
				ft_printf("It is now cycle %d\n", cor->cycles);
		}
		flag_output(cor);
		process_activity(cor);
		live_cheker(cor);
		if (cor->cycles == cor->mon && cor->log == 0 && cor->visu == 0)
			exit(0);
		cor->cycles++;
	}
}
