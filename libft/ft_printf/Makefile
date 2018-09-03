
NAME		=	libftprintf.a

SRC	=	ft_w.c  						\
		ft_l.c 							\
		ft_sort_params.c 				\
		ft_memory.c 					\
		ft_get_console_input.c 			\
	  	pf_format_char.c 				\
	  	pf_format_int.c 				\
	   	pf_format_str.c 				\
	   	pf_format_u_o_x.c 				\
	   	pf_format_wchar.c 				\
	   	pf_function.c 					\
	   	pf_handleformat.c 				\
	   	ft_printf.c 					\
	   	pf_function_second.c 			\
	   	ft_memory.c
	  
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR		=	./src/
OBJ_DIR		=	./obj/
INC_DIR		=	./inc/

INC_LIBDIR	=	./../libft/$(INC_DIR)	

LIBFT_HEAD	=	$(INC_LIBDIR)libft.h

HEADER		=	$(INC_DIR)ft_printf.h

HEAD_FLAGS	=	-I $(INC_DIR) -I $(INC_LIBDIR)

CC_FLAGS	=	-Wall -Werror -Wextra -std=c11

CC			=	gcc

BG			=	"\033[32;1m"
BR			=	"\033[31;1m"
EOC			=	"\033[0m"

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo ${BG}"ft_printf is ready"${EOC}
	
$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(HEADER)
	@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEAD_FLAGS)
	@echo ${BG}"[✓] $<"

clean:
	@rm -rf $(OBJ)
	@echo ${BR}"[✗] clean"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo ${BR}"[✗] $(NAME)"

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all fclean clean re 