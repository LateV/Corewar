VM_DIR		=	./VM/
ASM_DIR		=	./ASM_SRC/

BG			=	"\033[32;1m"
BR			=	"\033[31;1m"
EOC			=	"\033[0m"

all:  $(VM_DIR) $(ASM_DIR)

$(VM_DIR): 
	@make -C $(VM_DIR)

$(ASM_DIR): 
	@make -C $(ASM_DIR)

clean:
	@make clean -C $(VM_DIR)
	@make clean -C $(ASM_DIR)

fclean: clean
	@make fclean -C $(VM_DIR)
	@make fclean -C $(ASM_DIR)

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all fclean clean re $(VM_DIR) $(ASM_DIR)