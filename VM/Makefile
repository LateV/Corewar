NAME		=	 ../corewar

SRC	=	main.c 					\
		to_map.c				\
		init_comm_f.c			\
		codage_identify.c		\
		load_from_reg.c			\
		comm_live.c				\
		comm_ld.c				\
		comm_and_or_xor.c 		\
		comm_zjmp.c				\
		comm_ldi.c				\
		comm_sti.c				\
		comm_fork.c				\
		comm_lld.c				\
		comm_lldi.c				\
		comm_lfork.c			\
		comm_aff.c				\
		comm_st.c				\
		comm_add.c				\
		comm_sub.c				\
		comm_next.c				\
		get_data.c 				\
		set_proc_pos.c 			\
		arg_handler.c			\
		v_main.c 				\
		v_map_handler.c 		\
		live_cheker.c 			\
		game_init.c 			\
		game.c 					\
		v_map_handler2.c 		\
		v_map_handler3.c 		\
		v_map_handler4.c 		\
		v_map_handler5.c 		\
		flag_validation.c 		\
		ft_error.c 				\
		manage_flags.c 			\
		manage_flags2.c 		\
		manage_files.c 			\
		validate_players.c 		\
		validate_players2.c 	\
		usadge.c 				\
		new_player.c 			\

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR		=	./src/

OBJ_DIR		=	./obj/

INC_DIR		=	./inc/

LIB_DIR		=	./../libft/

LIBFT_DIR	=	$(LIB_DIR)libft/

LIBFT		=	$(LIBFT_DIR)libft.a

PRINTF_DIR	=	$(LIB_DIR)ft_printf/

LIBPRINTF	=	$(PRINTF_DIR)libftprintf.a

HEAD_PRINTF	=	$(PRINTF_DIR)$(INC_DIR)ft_printf.h
HEAD_LIBFT	=	$(LIBFT_DIR)$(INC_DIR)libft.h

HEAD_VM 	=	$(INC_DIR)vm.h

HEAD_FLAGS	=	-I $(INC_DIR) -I $(PRINTF_DIR)$(INC_DIR) -I $(LIBFT_DIR)$(INC_DIR)

LIBS_FLAGS	=	-L $(PRINTF_DIR) -lft -L $(LIBFT_DIR) -lftprintf -lncurses

CC_FLAGS	=	-Wall -Werror -Wextra -std=c11 -g

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
	@echo ${BG}"corewar is ready"${EOC}

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(HEAD_VM) $(HEAD_VIZU)
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

.PHONY: all fclean clean re $(LIBFT) $(LIBPRINTF)