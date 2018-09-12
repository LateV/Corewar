NAME = my_asm

SRCS = main.c read.c live.c count_params.c writing.c check_error.c free_params.c asm_library.c init.c

LIBFT = libft/

OBJECTS = $(SRCS:.c=.o)


FLAGS = -Wall -Werror -Wextra

CC = gcc

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "Creating .o files. Please wait..."
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) -L $(LIBFT) -lftprintf
	@echo "All .o files successfully created."
	@echo "Executable successfully created."
%.o: %.c
	gcc $(FLAGS) -c $<
clean:
	@echo "Deleting all .o files. Please wait..."
	@rm -f $(OBJECTS)
	@make clean -C $(LIBFT)
	@echo "All .o files deleted."

fclean: clean
	@echo "Deleting all .o files and executable. Please wait..."
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "All .o files and executable deleted."

re: fclean all

.PHONY: re all clean fclean
