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

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC =	ft_bzero.c      			\
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
		ft_genchar.c   				\
		ft_llutoa_base.c 			\
		ft_itoa_base.c 				\
		ft_strjoin_free_12.c 		\
		ft_arr_len.c 				\
		ft_count_words.c 			\
		ft_lstadd_back.c 			\
		ft_strtoupper.c 			\
		ft_reverse_bits.c 			\
		printf/ft_wchar_len.c 		\
		printf/ft_putxnolen.c 		\
		printf/ft_specif.c 			\
		printf/ft_printf.c 			\
		printf/ft_outp.c    		\
		printf/ft_pputstr.c 		\
		printf/ft_pputchar.c   		\
		printf/ft_format.c 			\
		printf/ft_pputdnbr.c 		\
		printf/ft_pitoa.c 			\
		printf/ft_freesh.c 			\
		printf/ft_pputproc.c   		\
		printf/ft_putdnolen.c      	\
		printf/ft_intdnegmin_1.c 	\
		printf/ft_intdposmin_1.c   	\
		printf/ft_intdnegmin_1.c   	\
		printf/ft_intdposnomin_1.c 	\
		printf/ft_intdnegnomin_1.c 	\
		printf/ft_length.c 			\
		printf/ft_length_1.c 		\
		printf/ft_length_u.c 		\
		printf/ft_length_u_1.c 		\
		printf/ft_putonolen.c 		\
		printf/ft_putxnolen.c 		\
		printf/ft_intoposnomin_1.c  \
		printf/ft_intxposnomin_1.c  \
		printf/ft_intoposmin_1.c 	\
		printf/ft_intxposmin_1.c 	\
		printf/ft_length_o.c 		\
		printf/ft_length_o_1.c 		\
		printf/ft_pput_wchar.c 		\
		printf/ft_wchar_len.c 		\
		printf/ft_pput_wchar_str.c 	\
		printf/ft_put_wcharstr.c 	\
		printf/ft_pputcharik.c 		\
		printf/ft_ppupad.c 			\
		printf/ft_pputstrik.c 		\
		printf/ft_ppupadnomin_11.c 	\
		printf/ft_format_length_1.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all