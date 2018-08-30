#include "vm.h"

void add_player(t_cor *cor, t_player *player, int k)
{
	t_process *tmp;

	tmp = cor->process;
	if (!tmp)
	{
		cor->process = ft_memalloc(sizeof(t_process));
		cor->process->next = NULL;
		cor->process->player = (player + k);
		cor->process->delay = -1;
		cor->process->registr[0] = cor->process->player->num * (-1);
		return ;
	}
	while(69)
	{
		if(tmp->next == NULL)
		{
			tmp->next = ft_memalloc(sizeof(t_process));
			if(tmp->next)
			{
				tmp->next->player = &player[k];
				tmp->next->delay = -1;
				tmp->next->registr[0] = tmp->next->player->num * (-1);
				tmp->next->next = NULL;
			}
			break ;
		}
		tmp = tmp->next;
	}
}

void add_players(t_cor *cor)
{
	int k;

	k = 0;
	while(cor->def_num < 5)
	{

		while(k < cor->p_num)
		{
			if(cor->def_num == cor->player[k].num)
			{

				add_player(cor, cor->player , k);
				break;
			}
			k++; 
		}
		k = 0;
		cor->def_num++;
	}
}

void print_map(t_cor *cor)
{
	int row;
	int i;

	row = 0;
	i = 0;
	while(i < MEM_SIZE)
	{
		while(row < 64)
		{
			printf("%02x ", cor->arena[i]);
			row++;
			i++;
		}
		printf("\n");
		row = 0;
	}
}

void data_to_arena(t_cor *cor, int pos, t_process *proc, unsigned int size)
{
	unsigned int i;

	i = 0;
	while(i < size)
	{
		cor->arena[pos + i] = proc->player->code[i];
		i++;
	}
}

void game_init(t_cor *cor)
{
	int pos;
	t_process *tmp;

	pos = 0;
	tmp = cor->process;
	while(tmp)
	{
		data_to_arena(cor, pos, tmp, tmp->player->prog_size);
		tmp->pc = pos;
		pos += MEM_SIZE / cor->p_num;
		tmp = tmp->next;
	}
}

void game(t_cor *cor)
{
	t_process *tmp;

	cor->cycles = 1;
	while(69)
	{
		tmp = cor->process;
		while(tmp)
		{
			if(cor->arena[tmp->pc] > 0 && cor->arena[tmp->pc] < 17)
			{
				ft_printf("num intst%d\n", cor->arena[tmp->pc] - 1);
				cor->instruct[(int)cor->arena[tmp->pc] - 1](cor, tmp);
			}
			else
			{
				ft_printf("num intst%d\n", cor->arena[tmp->pc] - 1);
				cor->instruct[16](cor, tmp);
			}
			ft_putstr("pos = ");
			ft_putnbr(tmp->pc);
			ft_putstr("\n");
			tmp = tmp->next;
		}
		ft_putstr("It is now cycle ");
		ft_putnbr(cor->cycles);
		ft_putstr("\n");
		cor->cycles++;
		if(cor->cycles >= 5000)
			return ;
	}
}

void to_map(t_cor *cor)
{
	add_players(cor);
	game_init(cor);
	// print_map(cor);
	init_comand_function(cor);
	game(cor);
	// print_map(cor);
	endwin();
	// while(1)
	// 	;
}