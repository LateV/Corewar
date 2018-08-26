NAME = asm

LIBFTDIR = ../libft/

SRC =	main.c 					\
		
OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME) 

$(NAME): $(OBJ) $(LIBFTDIR)libft.a
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFTDIR) -lft

$(LIBFTDIR)libft.a: $(LIBFTDIR)Makefile
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
