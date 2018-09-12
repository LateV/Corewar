#include "libft/libft.h"
#include <fcntl.h>

#define IND_SIZE				2
#define REG_SIZE				4
#define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3


#define MAX_ARGS_NUMBER			4
#define MAX_PLAYERS				4
#define MEM_SIZE				(4*1024)
#define IDX_MOD					(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

#define REG_NUMBER				16

#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10

/*
**
*/

typedef char	t_arg_type;

#define T_REG					1
#define T_DIR					2
#define T_IND					3
#define T_LAB					8

/*
**
*/

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3


#include <stddef.h>
typedef struct		s_def_com
{
    int opcode;
    char *name;
    int  num_of_arg;
    int  first_arg[3];
    int  second_arg[3];
    int third_arg[2];
    int label_size;
    int codage_octal;


}					t_def_com;

typedef struct		s_def_error
{
    int num;
    char *str;
}					t_def_error;



typedef struct		s_command
{
    int num;
    char *label;
    char *line;
    char *command_name;
    int  type_arg[3];
    ssize_t  num_arg[3];
    char *pointer_arg[3];
    int  is_codage_octal;
    int  label_size;
    int  size;
    int  byte_sum[3];
    int codage_octal;
    int opcode;
    struct s_command	*next;
}					t_command;


typedef struct		s_header
{
    char			    *bot_name;
    int                 name__len;
    unsigned int		prog_size;
    char				*comment;
    int                 comment_len;
    char                *curr_label;
    const char          *file_name;
    t_command           *com_list;
}					t_header;

t_def_com g_def[17];
t_def_error error_def[10];




void  read_file(const char *str, t_header **header);
void		ft_clear(char **arr);
void ft_free(t_header **header);
int ft_check_extension(const char **str, int y);
void error_exit( const char *str);
int ft_check_flag(const char **argv, int argc);
t_command *create_new_node(int num, char *str);
void push_back(t_header **header, t_command *new_node);
int ft_find_command(t_command **node);
size_t	ft_arr_len(char **arr);
void init_struct(t_header **header);
ssize_t	ft_atoi_long(const char *str);
void ft_count_opcode(t_command *node);
void ft_count_pointer(t_header *node);
void ft_label(t_header *node);
void ft_write_to_file(t_header *header);
void print_to_file(int fd, int byte, int param);
void error_cases(int k, t_header **header);
int ft_skip_comment(char *str);
int ft_find_pointer(char *s, t_command **node);
void ft_check_params(t_header *header);
int ft_check_quotes(char *str);
void ft_validate_all_params(t_header **header);
//void ft_fill_arg_param(char *str,int k, t_command **node);
void ft_find_arg_type(char *str, t_command **node);
int ft_find_char_num(char *str, char c);
int ft_check_quotes(char *str);
void validate_name_comment(t_header **header, char *type);
int ft_isspace(char c);
int ft_find_char_num(char *str, char c);
int label_char(char *str);
int check_for_digit(char *str);
void find_arg(t_command **node, t_header **header);
void skip_com(t_command *node);
void find_curr_label(t_header **header, t_command *node);
int validte_label_2(t_command *node);