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
		cor->process->live = 1;
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
	int i;

	i = 1;
	while(42)
	{
		tmp = cor->process;
		while(tmp)
		{

			tmp = tmp->next;
		}
		printf("It is now cycle %d\n", i);
		i++;
		if(i > 5000)
			return ;
	}
}

void to_map(t_cor *cor)
{
	add_players(cor);
	game_init(cor);
	game(cor);
}