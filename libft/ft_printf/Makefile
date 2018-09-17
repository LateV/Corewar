
NAME		=	libftprintf.a

SRC	=	ft_printf.c 						\
	  	ft_notion.c 						\
	  	ft_creatstrctr.c 					\
		ft_parse_conversions.c 				\
		ft_parse_length.c 					\
		ft_parse_precision.c 				\
		ft_parse_width.c 					\
		ft_manage_chars.c 					\
		ft_manage_signed_numbers.c 			\
		ft_manage_unsigned_numbers.c 		\
		ft_manage_strings.c 				\
		ft_manage_pointers.c 				\
		unicode.c 							\
		ft_manage_nonvalid.c 				\

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