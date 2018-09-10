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
		cor->process->player->live_curr = 0;
		cor->process->player->last_live = 0;
		cor->process->command = -1;
		cor->process->carry = 1;
		cor->process->live = 0;
		cor->process->count_num = cor->proc_num;
		cor->proc_num++;
		cor->winner = (player + k);
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
	new->player->live_curr = 0;
	new->player->last_live = 0;
	new->live = 0;
	new->command = -1;
	new->carry = 1;
	cor->process = new;
	new->count_num = cor->proc_num;
	cor->proc_num++;
	cor->winner = &player[k];
	draw_palyer_info(cor, new , k);
}

void add_players(t_cor *cor)
{
	int k;

	k = 0;
	cor->def_num = 1;
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
			ft_printf("%02x ", cor->arena[i]);
			row++;
			i++;
		}
		ft_printf("\n");
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
		cor->vizu->map[pos + i].comm = proc->player->code[i];
		cor->vizu->map[pos + i].player = proc->player->num * (-1);
		i++;
	}
	cor->vizu->map[pos].type = 1;
}

void game_init(t_cor *cor)
{
	int pos;
	int num_pl;
	t_process *tmp;

	pos = 0;
	num_pl = -1;
	tmp = cor->process;
	// ft_putstr("Introducing contestants...\n");
	while(num_pl > -5)
	{
		tmp = cor->process;
		while(tmp)
		{
			if(num_pl == tmp->player->num)
			{
				data_to_arena(cor, pos, tmp, tmp->player->prog_size);
				// ft_printf("* player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", tmp->player->num * (-1), tmp->player->prog_size, tmp->player->prog_name, tmp->player->comment);
				tmp->pc = pos;
				pos += MEM_SIZE / cor->p_num;
			}
			tmp = tmp->next;
		}
		num_pl--;
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
		if(tmp == NULL)
		{
			ft_printf("list of proc is null ??? \n");
			exit(0);
		}
		while(i < 4)// проверка на сумму криков жизнь процессов , порожденных 1 играком;
		{
			if(cor->player[i].live_curr >= 21)
			{
				cor->curr_cycle_t_d = cor->curr_cycle_t_d - CYCLE_DELTA;
				ft_printf("Cycle to die is now %d\n", cor->curr_cycle_t_d);
				cor->curr_chechs = -1;
				cor->player[i].live_curr = 0;
				i = 0;
				while(i < 4)// обнуление всех крииков жизнь
				{
					cor->player[i].live_curr = 0;
					cor->player[i].live_summ = 0;
					i++;
				}
				break;
			}
			i++;
		}


		// Проверка всех процессов на "жизнь"
		// {{
		while(tmp)
		{
			if(tmp->live == 0) // Если процесс не жив удаляем его из списка
			{
				if(prev == NULL) // Для случая , когда это первый елемент списка
				{
					tmp = cor->process->next;
					free(cor->process);
					cor->process = tmp;
					if(!tmp) // Если это был единственный процесс 
					{
						ft_printf("last proc is dead \n");
						ft_printf("winner is %s\n", cor->winner->prog_name);
						exit(0);
					}
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
				tmp->live = 0;// Если процесс жив то жизнь тратится
			prev = tmp;
			if(tmp)
				tmp = tmp->next;
		}
		if(!cor->process)
		{
			ft_printf("winner is %s\n", cor->winner->prog_name);
			ft_printf("last proc is dead (2) \n");
			exit(0);
		}
		// }}

		cor->curr_chechs++;
		if(cor->curr_chechs == MAX_CHECKS)
		{
			cor->curr_cycle_t_d = cor->curr_cycle_t_d - CYCLE_DELTA;
			ft_printf("Cycle to die is now %d\n", cor->curr_cycle_t_d);
			cor->curr_chechs = 0;
		}
		cor->live_check = 1;
		// ft_printf("cor->curr_chechs = %d\n", cor->curr_chechs);
		// ft_printf("Cycle to die is now %d\n", cor->curr_cycle_t_d);
	}
	else
		cor->live_check++;
	// ft_printf("cor->live_check = %d\n", cor->live_check);
	// ft_printf("cor->curr_chechs = %d\n", cor->curr_chechs);
	if(cor->curr_cycle_t_d < 0)
	{
		ft_putstr("Cycle to die is now ");
		ft_putnbr(cor->curr_cycle_t_d);
		ft_printf("\nwinner is %s\n", cor->winner->prog_name);
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
		if(cor->cycles >= 63000)
			return ;
	}
}

void to_map(t_cor *cor)
{
	init_window(cor);
	add_players(cor);
	draw_info(cor);
	game_init(cor);
	if(cor->visu == 1)
	{
		// mvwprintw(cor->vizu->win2, 50, 2, "%d", cor->vizu->end_of_prs);
		refresh_map(cor);
		while (1)
			;
	}
	// print_map(cor);
	init_comand_function(cor);
	game(cor);
	ft_printf("Cycle to die is now %d\n", cor->curr_cycle_t_d);
		ft_putstr("\n");
	// print_map(cor);
	endwin();
	// while(1)
	// 	;
}