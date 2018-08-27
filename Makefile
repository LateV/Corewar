NAME = corewar

LIBFTDIR = libft/

SRC =	VM/main.c 					\
		VM/to_map.c					\
		
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
