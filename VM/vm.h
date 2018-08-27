#ifndef VM_H
# define VM_H
# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

typedef char	t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

#include <curses.h>
#include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"

typedef struct			s_player
{
	char 				*file_path;
	unsigned char		prog_name[PROG_NAME_LENGTH + 1];
	unsigned char		comment[COMMENT_LENGTH + 1];
	unsigned char		*code;
	int					num;
	unsigned int		magic;
	unsigned int		prog_size;
}						t_player;

typedef struct			s_process
{
	int 				live; 			// Жив или нет (bool)
	unsigned int 		registr[16]; 	// регистры (16 штук)
	int 				pc;				// позиция на карте (0 - 4096)
	int 				cary; 			// флаг для некоторых команд
	void (*instruct) (void);			// команда, Которую исполняет процесс ( потом придумаю тип в котором хранить) 
	int 		 		delay; 			// сколько циклов до выполнения команды
	t_player 			*player;		// указатель на игрока который создал процесс
	struct s_process  	*next;
}						t_process;

typedef struct			s_cor
{
	unsigned char 		arena[MEM_SIZE + 1];
	int 				code_summ;
	int 				start;
	int 				visu;
	int 				dump;
	int 				curr_pl;
	int					p_num;
	int 				flag_p_num;
	int 				def_num;
	WINDOW 				*win1;
	WINDOW 				*win2;			
	t_process			*process;
	t_player			player[4];
}						t_cor;

void 					to_map(t_cor *cor);

#endif
