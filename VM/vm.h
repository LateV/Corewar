#ifndef VM_H
# define VM_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"

typedef struct			s_player
{
	char 				*name;
	char				*comment;
	char 				*code;
	int 				len_code;
}						t_player;

typedef struct			s_process
{
	int 		live; // сколько жизней (хз)
	int 		registr; // хз
	int 		pc; // позиция (хз)
	int 		cary; //  флаг (хз)
	// ??unknown 	instruct; // хз 
	// ??unknown 	arg; // хз
}						t_process;

typedef struct			s_cor
{
	unsigned char 		*arena;
	int					p_num;
	t_player			player[4];
}						t_cor;

#endif
