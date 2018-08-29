NAME = corewar

LIBFTDIR = libft/

SRC =	VM/main.c 					\
		VM/to_map.c					\
		VM/init_comm_f.c			\
		VM/load_data_to_reg.c		\
		VM/arg_identify.c			\
		VM/load_from_reg.c			\
		VM/comm_live.c				\
		VM/comm_ld.c				\
		VM/comm_or.c				\
		VM/comm_xor.c				\
		VM/comm_zjmp.c				\
		VM/comm_ldi.c				\
		VM/comm_sti.c				\
		VM/comm_fork.c				\
		VM/comm_lld.c				\
		VM/comm_lldi.c				\
		VM/comm_lfork.c				\
		VM/comm_aff.c				\
		VM/comm_st.c				\
		VM/comm_add.c				\
		VM/comm_sub.c				\
		VM/comm_and.c				\
		VM/comm_next.c				\

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME) 

$(NAME): $(OBJ) $(LIBFTDIR)libft.a
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lncurses -L./$(LIBFTDIR) -lft

$(LIBFTDIR)libft.a: libft/Makefile
	make -C $(LIBFTDIR)

%.o: %.c
		$(CC) $(CFLAGS) -o $@ -c $<
clean:
		rm -f $(OBJ)
		make clean -C $(LIBFTDIR)

fclean: clean
		rm -f $(NAME)
		rm -f $(LIBFTDIR)libft.a

re: fclean all
