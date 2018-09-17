# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vibondar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 16:25:41 by vibondar          #+#    #+#              #
#    Updated: 2017/11/08 16:25:43 by vibondar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		libft.a

SRC	=	ft_bzero.c      			\
		ft_memchr.c					\
		ft_memcpy.c					\
		ft_memset.c					\
		ft_memccpy.c    			\
		ft_memmove.c    			\
		ft_strcat.c     			\
		ft_strcpy.c     			\
		ft_strdup.c     			\
		ft_strlen.c     			\
		ft_strncat.c    			\
		ft_strncpy.c    			\
		ft_memcmp.c 				\
		ft_strstr.c     			\
		ft_strnstr.c    			\
		ft_strcmp.c 				\
		ft_strncmp.c    			\
		ft_strlcat.c    			\
		ft_atoi.c 					\
		ft_isalpha.c 				\
		ft_isdigit.c 				\
		ft_isascii.c 				\
		ft_isalnum.c 				\
		ft_isprint.c 				\
		ft_toupper.c    			\
		ft_tolower.c    			\
		ft_strchr.c     			\
		ft_strrchr.c    			\
		ft_memalloc.c   			\
		ft_memdel.c     			\
		ft_strnew.c     			\
		ft_strdel.c     			\
		ft_strclr.c     			\
		ft_striter.c    			\
		ft_striteri.c   			\
		ft_strmap.c     			\
		ft_strmapi.c    			\
		ft_strequ.c     			\
		ft_strnequ.c    			\
		ft_strsub.c     			\
		ft_strjoin.c				\
		ft_strtrim.c				\
		ft_strsplit.c 				\
		ft_itoa.c 					\
		ft_putchar.c 				\
		ft_putstr.c 				\
		ft_putendl.c 				\
		ft_putnbr.c 				\
		ft_putchar_fd.c 			\
		ft_putstr_fd.c 				\
		ft_putendl_fd.c 			\
		ft_putnbr_fd.c 				\
		ft_lstnew.c     			\
		ft_lstdelone.c  			\
		ft_lstdel.c     			\
		ft_lstadd.c     			\
		ft_lstiter.c    			\
		ft_lstmap.c     			\
		get_next_line.c 			\
		ft_dig_count.c 				\
		ft_llutoa_base.c 			\
		ft_itoa_base.c 				\
		ft_strjoin_free_12.c 		\
		ft_arr_len.c 				\
		ft_count_words.c 			\
		ft_lstadd_back.c 			\
		ft_strtoupper.c 			\
		ft_reverse_bits.c 			\
		ft_loweret.c 				\
		ft_strndup.c 				\
		ft_itoa_ubase.c 			\
		ft_uppercase.c 				\
		ft_wstrlen.c 				\
		ft_len_num.c 				\

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR		=	./src/
OBJ_DIR		=	./obj/
INC_DIR		=	./inc/

HEAD_FLAGS	=	-I $(INC_DIR)

HEADER		=	$(INC_DIR)libft.h

CC_FLAGS	=	-Wall -Werror -Wextra -std=c11

CC			=	gcc

BG			=	"\033[32;1m"
BR			=	"\033[31;1m"
EOC			=	"\033[0m"

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo ${BG}"libft.a is ready" ${EOC}

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(HEADER)
	@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEAD_FLAGS)
	@echo ${BG}"[✓] $<" ${EOC}

clean :
	@rm -rf $(OBJ)
	@echo ${BR}"[✗] cleaning" ${EOC}

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo ${BR}"[✗] $(NAME)" ${EOC}

re : fclean all

vpath %.c $(SRC_DIR)

.PHONY: all fclean clean re 