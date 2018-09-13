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
		cor->process->carry = 0;
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
	new->carry = 0;
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
		if(cor->visu == 1)
		{
			cor->vizu->map[pos + i].comm = proc->player->code[i];
			cor->vizu->map[pos + i].player = proc->player->num * (-1);
		}
		i++;
	}
	if(cor->visu == 1)
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
	if(cor->visu == 0)
		ft_putstr("Introducing contestants...\n");
	while(num_pl > -5)
	{
		tmp = cor->process;
		while(tmp)
		{
			if(num_pl == tmp->player->num)
			{
				data_to_arena(cor, pos, tmp, tmp->player->prog_size);
				if(cor->visu == 0)
					ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", tmp->player->num * (-1), tmp->player->prog_size, tmp->player->prog_name, tmp->player->comment);
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
			// ft_printf("list of proc is null ??? \n");
			endwin();
			system("leaks -quiet corewar");
			exit(0);
		}
		while(i < 4)// проверка на сумму криков жизнь процессов , порожденных 1 играком;
		{
			if(cor->player[i].live_curr >= 21)
			{
				cor->curr_cycle_t_d = cor->curr_cycle_t_d - CYCLE_DELTA;
				if(cor->visu == 0)
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
						if(cor->visu == 0)
							ft_printf("Contestant %d, \"%s\", has won !\n", cor->winner->num * (-1), cor->winner->prog_name);
						endwin();
						system("leaks -quiet corewar");
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
			if(cor->visu == 0)
				ft_printf("Contestant %d, \"%s\", has won !\n", cor->winner->num * (-1), cor->winner->prog_name);
			endwin();
			system("leaks -quiet corewar");
			exit(0);
		}
		// }}

		cor->curr_chechs++;
		if(cor->curr_chechs == MAX_CHECKS)
		{
			cor->curr_cycle_t_d = cor->curr_cycle_t_d - CYCLE_DELTA;
			if(cor->visu == 0)
				ft_printf("Cycle to die is now %d\n", cor->curr_cycle_t_d);
			cor->curr_chechs = 0;
		}
		cor->live_check = 1;
	}
	else
		cor->live_check++;
	if(cor->curr_cycle_t_d < 0)
	{
		if(cor->visu == 0)
		{
			// ft_printf("Cycle to die is now %d\n", cor->curr_cycle_t_d);
			ft_printf("Contestant %d, \"%s\", has won !\n", cor->winner->num * (-1), cor->winner->prog_name);
		}
		endwin();
		system("leaks -quiet corewar");
		exit(0);
	}
}

void game(t_cor *cor)
{
	t_process *tmp;

	cor->cycles = 1;
	cor->start_from = 0;
	while(69)
	{
		if(cor->visu == 1)
		{
			cor->vizu->key = getch();
			v_speed_test(cor, cor->vizu->key);

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
			if(cor->visu == 0)
				ft_printf("It is now cycle %d\n", cor->cycles);
		}
		tmp = cor->process;
		while(tmp)
		{
			if(tmp->command == -1)
			{
				if(cor->cycles == 18896)
				{
					
					ft_printf("tmp->pc = %d\n", tmp->pc);
				}
				if(cor->arena[tmp->pc] > 0 && cor->arena[tmp->pc] < 17)
				{

					if(cor->cycles == 18896)
						ft_printf("wtf?????4\n");
					tmp->command = cor->arena[tmp->pc] - 1;
					cor->instruct[tmp->command](cor, tmp);

					if(cor->cycles == 18896)
						ft_printf("wtf?????5\n");

				}
				else
				{

					if(cor->cycles == 18896)
						ft_printf("wtf?????6\n");
					set_proc_pos(cor, tmp, 1);

					if(cor->cycles == 18896)
						ft_printf("wtf?????7\n");

				}
			}
			else
			{

					if(cor->cycles == 18896)
						ft_printf("wtf?????8\n");

				cor->instruct[tmp->command](cor, tmp);

					if(cor->cycles == 18896)
						ft_printf("wtf?????9\n");

			}

					if(cor->cycles == 18896)
						ft_printf("wtf?????10\n");

			tmp = tmp->next;

					if(cor->cycles == 18896)
						ft_printf("wtf?????11\n");

		}
		cor->cycles++;

					if(cor->cycles == 18896)
						ft_printf("wtf?????12\n");

		live_cheker(cor);

					if(cor->cycles == 18896)
						ft_printf("wtf?????13\n");

	}
}

void to_map(t_cor *cor)
{
	init_window(cor);
	add_players(cor);
	draw_info(cor);
	game_init(cor);
	if(cor->visu == 1)
		refresh_vizu(cor);
	// print_map(cor);
	init_comand_function(cor);
	game(cor);
	if(cor->visu == 0)
		ft_printf("Cycle to die is now %d\n", cor->curr_cycle_t_d);
	// print_map(cor);
	endwin();
	// while(1)
	// 	;
}