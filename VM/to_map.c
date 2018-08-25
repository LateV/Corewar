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

// void print_map(t_cor *cor)
// {

// }

// void data_to_arena(t_cor *cor, int pos, t_process *proc, unsigned int size)
// {
// 	int i;
// }

void game_init(t_cor *cor)
{
	int pos;
	t_process *tmp;

	pos = 0;
	tmp = cor->process;
	while(tmp)
	{
		// data_to_arena(cor, pos, tmp, tmp->player->prog_size);
		pos += cor->code_summ / cor->p_num;
		tmp = tmp->next;
	}
	printf("summ = %d\n", cor->code_summ);

}

void to_map(t_cor *cor)
{
	add_players(cor);
	game_init(cor);
}