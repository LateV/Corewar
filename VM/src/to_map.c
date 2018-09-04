#include "vm.h"

void add_player(t_cor *cor, t_player *player, int k)
{
	t_process *tmp;
	t_process *new;

	tmp = cor->process;
	if (!tmp)
	{
		cor->process = ft_memalloc(sizeof(t_process));
		cor->process->next = NULL;
		cor->process->player = (player + k);
		cor->process->delay = -1;
		cor->process->player->num = cor->process->player->num * (-1);
		cor->process->registr[0] = cor->process->player->num;
		cor->process->player->live_summ = 0;
		cor->process->command = -1;
		cor->process->carry = 1;
		cor->process->live = 0;
		draw_palyer_info(cor, cor->process , k);
		return ;
	}
	new = ft_memalloc(sizeof(t_process));
	new->next = cor->process;
	new->player = &player[k];
	new->delay = -1;
	new->player->num = new->player->num * (-1);
	new->registr[0] = new->player->num;
	new->player->live_summ = 0;
	new->live = 0;
	new->command = -1;
	new->carry = 1;
	cor->process = new;
	draw_palyer_info(cor, new , k);
}

void add_players(t_cor *cor)
{
	int k;

	k = 0;
	cor->def_num = 4;
	while(cor->def_num > 0)
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
		cor->def_num--;
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
		put_com(cor, pos + i, proc->player->code[i], proc->player->num);
		i++;
	}
	put_car(cor, pos, proc->player->code[0], proc->player->num);
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

void live_cheker(t_cor *cor)
{
	t_process *prev;
	t_process *tmp;
	int i;

	i = 0;
	if(cor->live_check == cor->curr_cycle_t_d)
	{
		tmp = cor->process;
		prev = NULL;
		while(tmp)
		{
			if(tmp->live == 0)
			{
				if(prev == NULL)
				{
					tmp = cor->process->next;
					free(cor->process);
					cor->process = tmp;
				}
				else
				{
					prev->next = tmp->next;
					free(tmp);
					tmp = prev->next;
					continue;
				}
			}
			else
				tmp->live = 0;
			prev = tmp;
			tmp = tmp->next; // SEGFAULT!
		}
		while(i < 4)
		{
			if(cor->player[i].live_summ >= 21)
			{
				cor->curr_cycle_t_d = cor->curr_cycle_t_d - CYCLE_DELTA;
				cor->curr_chechs = -1;
			}
			i++;
		}
		cor->curr_chechs++;
		// ft_putstr("cor->curr_chechs is now ");
		// ft_putnbr(cor->curr_chechs);
		// ft_putstr("\n");
		// ft_putstr("Cycle to die is now ");
		// ft_putnbr(cor->curr_cycle_t_d);
		// ft_putstr("\n");
		if(cor->curr_chechs == MAX_CHECKS)
		{
			cor->curr_cycle_t_d = cor->curr_cycle_t_d - CYCLE_DELTA;
			cor->curr_chechs = 0;
		}
		cor->live_check = 0;
			i = 0;
		while(i < 4)
		{
			cor->player[i].live_summ = 0;
			i++;
		}
	}
	else
		cor->live_check++;
	if(cor->curr_cycle_t_d < 0)
	{
		ft_putstr("Cycle to die is now ");
		ft_putnbr(cor->curr_cycle_t_d);
		ft_putstr("\n");
		exit(0);
	}
}

void game(t_cor *cor)
{
	t_process *tmp;

	cor->cycles = 1;
	while(69)
	{
		ft_putstr("It is now cycle ");
		ft_putnbr(cor->cycles);
		ft_putstr("\n");
		tmp = cor->process;
		// ft_putstr("pos = ");
		// ft_putnbr(tmp->pc);
		// ft_putstr("\n");
		while(tmp)
		{
			if(tmp->command == -1)
			{
				// ft_putstr("pos = ");
		 	// 	ft_putnbr(tmp->pc);
				// ft_putstr("\n");
				if(cor->arena[tmp->pc] > 0 && cor->arena[tmp->pc] < 17)
				{
					tmp->command = cor->arena[tmp->pc] - 1;
					cor->instruct[tmp->command](cor, tmp);
				}
				else
					set_proc_pos(tmp, 1);
			}
			else
				cor->instruct[tmp->command](cor, tmp);
			tmp = tmp->next;
		}
		cor->cycles++;
		live_cheker(cor);
		if(cor->cycles >= 60000)
			return ;
	}
}

void to_map(t_cor *cor)
{
	init_window(cor); 
	add_players(cor);
	draw_info(cor);
	game_init(cor);

	wrefresh(cor->vizu->win1);
	wrefresh(cor->vizu->win2);
	while (1)
		;
	
	// print_map(cor);
	init_comand_function(cor);
	game(cor);
	ft_putstr("Cycle to die is now ");
		ft_putnbr(cor->curr_cycle_t_d);
		ft_putstr("\n");
	// print_map(cor);
	endwin();
	// while(1)
	// 	;
}