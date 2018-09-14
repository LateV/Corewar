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
#define ABS(x) (((x)<0) ? -(x) : (x))

# include <curses.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"
# include "ft_printf.h"


struct s_process;
struct s_cor;

typedef struct			s_player
{
	int 				live_curr;	// сумма криков "жизнь" процессами, породженными данным играком
	int 				last_live;	// цикл последнего крика "жизнь"					
	int 				live_summ; 	// Количество криков "жизнь" для даннаого играока за период (0 - curr_cycle_t_d) циклов
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
	int 				count_num; 		// номер процесса
	int 				live; 			// Жив или нет (bool)
	unsigned int 		registr[16]; 	// регистры (16 штук)
	int 				pc;				// позиция на карте (0 - 4096)
	int 				carry; 			// флаг для некоторых команд
	int 		 		delay;			// сколько циклов до выполнения команды
	int 				arg1;			//  аргументы {{
	int 				arg2;
	int 				arg3;
	int 				arg_type[3];	// }}
	int 				label;
	int 				codage;
	int 				command;
	int 				ind_loc;
	t_player 			*player;		// указатель на игрока который создал процесс
	struct s_process  	*next;			// указатель на следующий процесс
}						t_process;

typedef struct			s_map
{
	unsigned char		comm;
	int 				type;
	int	 				player;
	int 				life_time;
	int 				life_scream;
}						t_map;

typedef struct			s_vizu
{
	WINDOW 				*win1;
	WINDOW				*win2;
	int 				end_of_prs;
	t_map 				*map;
	int 				speed;
	char 				key;
}						t_vizu;

typedef struct			s_cor
{
	unsigned char 		arena[MEM_SIZE + 1];
	int 				proc_num;
	int 				cycles;
	int 				code_summ;
	int 				start;
	int 				visu;
	int 				dump;
	int 				pause;
	int 				stealth;
	int 				a;
	int 				s;
	int 				log;
	int 				curr_pl;
	int					p_num;
	int 				flag_p_num;
	int 				def_num;
	int 				live_check;
	int 				curr_cycle_t_d;
	int 				curr_chechs;
	WINDOW 				*win1;
	WINDOW 				*win2;				
	t_process			*process;
	t_player			player[4];
	t_player 			*winner;
	void (*instruct[17]) (struct s_cor *cor, t_process *process);
	t_vizu 				*vizu;
	int 				start_from;
}						t_cor;


char 					get_char(t_cor *cor, int loc);
void 					usadge(void);
void 					print_map(t_cor *cor);
short 					get_short(t_cor *cor, int loc);
int 					get_int(t_cor *cor, int loc);
int 					t_dir(t_cor *cor, t_process *process, int *arg, int loc);
int 					t_reg(t_cor *cor, int *arg, int loc);
int 					t_ind(t_cor *cor, int *arg, int loc);
int 					get_reg(t_process *process, unsigned char reg);
void					set_proc_pos(t_cor *cor, t_process *process, int shift);
int 					arg_handler(t_cor *cor, t_process *process, int *arg, int s);
void 					to_map(t_cor *cor);
void 					init_comand_function(t_cor *cor);
void 					load_from_reg(t_cor *cor, t_process *process, int loc, int r_num);
void 					codage_identify(t_process *process, unsigned char args);
void 					comm_live(t_cor *cor, t_process *process);
void 					comm_ld(t_cor *cor, t_process *process);
void 					comm_and_or_xor(t_cor *cor, t_process *process);
void 					comm_zjmp(t_cor *cor, t_process *process);
void 					comm_ldi(t_cor *cor, t_process *process);
void 					comm_sti(t_cor *cor, t_process *process);
void 					comm_fork(t_cor *cor, t_process *process);
void 					comm_lld(t_cor *cor, t_process *process);
void 					comm_lldi(t_cor *cor, t_process *process);
void 					comm_lfork(t_cor *cor, t_process *process);
void 					comm_aff(t_cor *cor, t_process *process);
void 					comm_st(t_cor *cor, t_process *process);
void 					comm_add(t_cor *cor, t_process *process);
void 					comm_sub(t_cor *cor, t_process *process);
void 					comm_next(t_cor *cor, t_process *process);
void 					add_proc(t_cor *cor, t_process *process, int loc);
void 					live_cheker(t_cor *cor);
void 					game_init(t_cor *cor);
void 					add_players(t_cor *cor);
void 					game(t_cor *cor);
// vizu
void					init_window(t_cor *cor);
void					draw_palyer_info(t_cor *cor, t_process *proc, int k);
void					draw_info(t_cor *cor);
void					put_com(t_cor *cor, int pos, unsigned char comm, int color);
void					put_car(t_cor *cor, int pos, unsigned char comm, int color);
void					init_map(t_cor *cor);
void					refresh_map(t_cor *cor);
void					refresh_vizu(t_cor *cor);
void					initital_draw(t_cor *cor);
void					v_speed_test(t_cor *cor, char t);
#endif
