#include "vm.h"

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