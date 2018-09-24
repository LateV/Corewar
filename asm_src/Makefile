NAME		=	 ../asm

SRC	= 	asm_library_pt1.c 				\
		asm_library_pt2.c 				\
		check_arg.c 					\
		count_size.c 					\
		error_and_free.c 				\
		init_struct.c 					\
		main.c 							\
		read_file.c 					\
		validate_label.c 				\
		validate_arg.c 					\
		validate_name.c 				\
		writing_to_file.c 				\


OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR		=	./src/

OBJ_DIR		=	./obj/

INC_DIR		=	./inc/

LIB_DIR		=	./../libft/

LIBFT_DIR	=	$(LIB_DIR)libft/

INC_VM		=	../vm/inc/

LIBFT		=	$(LIBFT_DIR)libft.a

PRINTF_DIR	=	$(LIB_DIR)ft_printf/

LIBPRINTF	=	$(PRINTF_DIR)libftprintf.a

HEAD_PRINTF	=	$(PRINTF_DIR)$(INC_DIR)ft_printf.h
HEAD_LIBFT	=	$(LIBFT_DIR)$(INC_DIR)libft.h

HEAD_ASM =	$(INC_DIR)asm.h

HEAD_FLAGS	=	-I $(INC_DIR) -I $(PRINTF_DIR)$(INC_DIR) -I $(LIBFT_DIR)$(INC_DIR) -I $(INC_VM)

LIBS_FLAGS	=	-L $(PRINTF_DIR) -lft -L $(LIBFT_DIR) -lftprintf -lncurses

CC_FLAGS	=	-Wall -Werror -Wextra -std=c11

CC			=	gcc

BG			=	"\033[32;1m"
BR			=	"\033[31;1m"
EOC			=	"\033[0m"

all: $(LIBFT) $(NAME)

$(LIBFT): $(LIBPRINTF)
	@make -C $(LIBFT_DIR)

$(LIBPRINTF):
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(LIBS_FLAGS)
	@echo ${BG}"asm is ready"${EOC}

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(HEAD_ASM)
	@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEAD_FLAGS) 
	@echo ${BG}"[✓] $<"

clean:
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ)
	@echo ${BR}"[✗] clean"

fclean: clean
	@make fclean -C $(PRINTF_DIR)
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo ${BR}"[✗] $(NAME)"

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all fclean clean re 