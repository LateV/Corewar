/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:33:57 by oskulska          #+#    #+#             */
/*   Updated: 2018/09/13 19:33:59 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "libft.h"
# include "ft_printf.h"
# include "vm.h"

typedef struct			s_def_cmd
{
	int					opcode;
	char				*name;
	int					num_of_arg;
	int					first_arg[3];
	int					second_arg[3];
	int					third_arg[2];
	int					label_size;
	int					codage_octal;
}						t_def_cmd;

t_def_cmd				g_cmd_def[17];

typedef struct			s_def_error
{
	int					num;
	char				*str;
}						t_def_error;

t_def_error				g_error_def[18];

union					u_byterange
{
	int					num;
	char				ch2[2];
	char				ch[4];
}						t_byterange;

typedef struct			s_command
{
	int					num;
	char				*label;
	char				*line;
	char				*command_name;
	int					arg_type[3];
	ssize_t				num_arg[3];
	char				*arg_pointer[3];
	int					is_codage_octal;
	int					label_size;
	int					size;
	int					byte_sum[3];
	int					codage_octal;
	int					opcode;
	struct s_command	*next;
}						t_command;

typedef struct			s_header
{
	char				*bot_name;
	int					name__len;
	int					name_line;
	int					cmt_line;
	unsigned int		prog_size;
	char				*comment;
	int					comment_len;
	char				*curr_label;
	char				*file_name;
	t_command			*cmd_list;
}						t_header;

void					read_file(const char *str, t_header **header);
void					ft_clear(char **arr);
void					ft_free(t_header **header);
int						check_extension(const char **str, int y);
void					error_exit(char *str, const char *arg);
int						check_flag(const char **argv, int argc);
t_command				*create_new_node(int num, char *str);
void					push_back(t_header **header, t_command *new_node);
int						find_command(t_command **node);
void					init_struct(t_header **header);
ssize_t					ft_atol(const char *str);
void					count_opcode(t_command *node);
void					count_pointer(t_header *node);
void					write_to_file(t_header *header);
void					error_cases(int k, t_header **header, int line);
void					check_all_param(t_header *header);
int						check_quotes(char *str);
void					validate_params(t_header **header);
int						char_pos(char *str, char c);
int						check_quotes(char *str);
void					validate_name_and_cmt(t_header **header,
							char *type, int num);
int						ft_isspace(char c);
int						is_label_char(char *str);
int						check_for_digit(char *str);
void					split_line_for_arg(t_command **node, t_header **header);
void					skip_comments(t_command *node);
void					find_curr_label(t_header **header, t_command *node);
int						check_label_chars(t_command *node);
void					validate_label(t_header **header);
void					fill_name_and_cmt(t_header **header);
t_command				*find_curr_list(t_command *copy, char *str);
#endif
