#include "vm.h"

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