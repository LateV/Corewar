#include "vm.h"


void	ft_error(t_cor *cor, char *error)
{
	cor->p_num = cor->p_num;
	ft_putstr(error);
	ft_putstr("\n");
	exit(0);
}

inline static void	ft_while_and_if(t_cor *cor, char *flag, char *value)
{
	int					i;

	i = 0;
	while (value[i] != '\0')
	{
		if (!ft_isdigit(value[i]))
		{
			ft_printf("Invalid format in flag ");
			ft_error(cor, flag);
		}
		i++;
	}
	if (i > 11)
	{
		ft_printf("Invalid format (over int) in flag ");
		ft_error(cor, flag);
	}
}

int val_int(t_cor *cor, char *flag, char *value)
{
	unsigned long int	b;
	int					i;

	b = 0;
	i = 0;
	ft_while_and_if(cor, flag, value);
	if (value[i] == '-')
	{
		ft_printf("Value can not be negative in flag ");
		ft_error(cor, flag);
	}
	if (value[i] == '+' || value[i] == '-')
		i++;
	while (value[i] != '\0')
	{
		b = (b * 10) + (value[i] - '0');
		i++;
	}
	if (b > 2147483647)
	{
		ft_printf("Invalid format (over int value) in flag ");
		ft_error(cor, flag);
	}
	return ((int)b);
}

int flag_force(t_cor *cor, char **argv, int i)
{
	int num;

	if(argv[i + 1] == NULL)
		ft_error(cor, "Invalid format in flag -force");
	num = val_int(cor, argv[i], argv[i + 1]);
	cor->start_from = num;
	return(i + 1);
}

int flag_n(t_cor *cor, char **argv, int i)
{
	int num;
	int j;

	j = 0;
	if(argv[i + 1] == NULL)
		ft_error(cor, "Invalid format in flag -n");
	num = val_int(cor, argv[i], argv[i + 1]);
	if(num > 4 || num < 1)
		ft_error(cor, "Number of the player must be [1-4]");
	while(j < 4)
	{
		if(cor->player[j].num == num)
			return(i + 1);
		j++;
	}
	cor->flag_p_num = num;
	return(i + 1);
}

int flag_dump(t_cor *cor, char **argv, int i)
{
	int num;

	if(argv[i + 1] == NULL)
		ft_error(cor, "Invalid format in flag -dump");
	num = val_int(cor, argv[i], argv[i + 1]);
	cor->dump = num;
	return(i + 1);
}

int flag_mon(t_cor *cor, char **argv, int i)
{
	int num;

	if(argv[i + 1] == NULL)
		ft_error(cor, "Invalid format in flag -mon");
	num = val_int(cor, argv[i], argv[i + 1]);
	cor->mon = num;
	return(i + 1);
}


int		manage_flags(t_cor *cor, char **argv, int i)
{
	if(ft_strcmp(argv[i], "-n") == 0)
		return(flag_n(cor, argv, i));
	if(ft_strcmp(argv[i], "-v") == 0)
	{
		cor->visu = 1;
		return(i);
	}
	// if(ft_strcmp(argv[i], "-a") == 0)
	// 	return(flag_a(cor, argv, i));
	// if(ft_strcmp(argv[i], "-log") == 0)
	// 	return(flag_log(cor, argv, i));
	// if(ft_strcmp(argv[i], "--stealth") == 0)
	// 	return(flag_stealth(cor, argv, i));
	if(ft_strcmp(argv[i], "-dump") == 0)
		return(flag_dump(cor, argv, i));
	if(ft_strcmp(argv[i], "-mon") == 0)
		return(flag_mon(cor, argv, i));
	// if(ft_strcmp(argv[i], "-s") == 0)
	// 	return(flag_s(cor, argv, i));
	if(ft_strcmp(argv[i], "-force") == 0)
		return(flag_force(cor, argv, i));
	return(-1);
}

void cor_format(t_cor *cor, char *path)
{
	int i;


	i = ft_strlen(path);
	if(i - 5 > 0)
	{
		if(ft_strcmp(path + i - 4, ".cor") != 0)
		{
			ft_putstr("Can't read source file (missing .cor) ");
			ft_error(cor, path);
		}
		cor->player[cor->p_num].file_path = path;
	}
	else
	{
		ft_putstr("Can't read source file ");
		ft_error(cor, path);
	}	
	if(cor->p_num > 3)
		ft_error(cor, "Error: max 4 players");
}

void	calculate_p_num(t_cor *cor)
{
	if(cor->p_num > 3)
		ft_error(cor, "Error: max 4 players");
	if(cor->flag_p_num != -1)
	{
		cor->player[cor->p_num].num = cor->flag_p_num;
		cor->curr_pl = cor->player[cor->p_num].num;
		cor->flag_p_num = -1;
		cor->p_num++;
	}
	else
	{
		cor->player[cor->p_num].num = -2;
		cor->p_num++;
	}
}



void	manage_files(t_cor *cor, char *argv)
{
	cor_format(cor, argv);
	calculate_p_num(cor);
}

void init_players(t_cor *cor)
{
	int  i;

	i = 0;
	cor->def_num = 1;
	while (i < 4)
	{
		cor->player[i].num = -1;
		i++;
	}
}

void check_name(t_cor *cor, int fd, int i)
{
	int ret;

	ret = read(fd, &cor->player[i].prog_name, PROG_NAME_LENGTH);
	if(ret < PROG_NAME_LENGTH)
	{
		ft_putstr("Bad programm name length in file: ");
		ft_error(cor, cor->player[i].file_path);
	}
}

void check_null(t_cor *cor, int fd, int i)
{
	int ret;
	unsigned int ch;

	ret = read(fd, &ch, 4);
	if(ret < 4 || ch != 0)
	{
		ft_putstr("NULL error in file: ");
		ft_error(cor, cor->player[i].file_path);
	}
}

void magic_header(t_cor *cor, int fd, int i)
{
	int ret;

	ret = read(fd, &cor->player[i].magic, 4);
	if(ret < 4)
	{
		ft_putstr("Bad magic header in file: ");
		ft_error(cor, cor->player[i].file_path);
	}
	ft_reverse_bits((void*)&cor->player[i].magic,
		sizeof(cor->player[i].magic));
	if(COREWAR_EXEC_MAGIC != cor->player[i].magic)
	{
		ft_putstr("Bad magic header in file: ");
		ft_error(cor, cor->player[i].file_path);
	}
}

void bot_size(t_cor *cor, int fd, int i)
{
	int ret;

	ret = read(fd, &cor->player[i].prog_size, 4);
	if(ret < 4)
	{
		ft_putstr("Error in Bot size information in file: ");
		ft_error(cor, cor->player[i].file_path);
	}
	ft_reverse_bits((void*)&cor->player[i].prog_size,
		sizeof(cor->player[i].prog_size));
	if(cor->player[i].prog_size > 682)
	{
		ft_putstr("Error: File ");
		ft_putstr(cor->player[i].file_path);
		ft_putstr(" has too large a code (");
		ft_putnbr(cor->player[i].prog_size);
		ft_printf(" bytes > %d bytes)", CHAMP_MAX_SIZE);
		ft_error(cor, "");
	}
	cor->code_summ += cor->player[i].prog_size;
}

void bot_comment(t_cor *cor, int fd, int i)
{
	int ret;

	ret = read(fd, &cor->player[i].comment, COMMENT_LENGTH);
	if(ret < COMMENT_LENGTH)
	{
		ft_putstr("Error in comment in file: ");
		ft_error(cor, cor->player[i].file_path);
	}
}

void bot_code(t_cor *cor, int fd, int i)
{
	unsigned int ret = 0;
	unsigned int ret_p;
	unsigned char buff[42];
	

	cor->player[i].code = ft_memalloc(sizeof(unsigned char) * cor->player[i].prog_size);
	ret = read(fd, cor->player[i].code, cor->player[i].prog_size);
	ret_p = read(fd, &buff, 2);
	if(ret < cor->player[i].prog_size || ret_p > 0)
	{
		ft_putstr("Error in lenth executable code in file: ");
		ft_error(cor, cor->player[i].file_path);
	}
}


void	validate_players(t_cor *cor)
{
	int fd;
	int i;

	i = 0;
	while(i < cor->p_num && cor->player[i].file_path != NULL)
	{
		fd = open(cor->player[i].file_path, O_RDONLY);
		if(fd < 0)
		{
			ft_putstr(strerror(errno));
			ft_putstr(": ");
			ft_error(cor, cor->player[i].file_path);
		}
		magic_header(cor, fd, i);
		check_name(cor, fd, i);
		check_null(cor, fd, i);
		bot_size(cor, fd, i);
		bot_comment(cor, fd, i);
		check_null(cor, fd, i);
		bot_code(cor, fd, i);
		i++;
	}
}

void def_num(t_cor *cor)
{
	int k;
	int i;

	k = 0;
	i = 0;
	cor->def_num = 1;
	while(i < cor->p_num)
	{
		if(cor->player[i].num == -2)
		{
			cor->def_num = 1;
			while(cor->def_num < 5)
			{
				while(k < 4)
				{
					if(cor->def_num == cor->player[k].num)
						break;
					k++; 
				}
				if(k == 4)
				{
					cor->player[i].num = cor->def_num;
					k = 0;
					break;
				}
				k = 0;
				cor->def_num++;
			}
		}
		i++;
	}
}

void usadge(void)
{
	ft_printf("here was supposed to be {[~~usadge~~~]}\n");
	exit(0);
}

int main(int argc, char **argv)
{
	t_cor cor;
	int i;
	int j;

	if(argc == 1)
		usadge();
	i = 1;
	cor.p_num = 0;
	cor.start_from = 0;
	cor.flag_p_num = -1;
	cor.code_summ = 0;
	cor.visu = 0;
	cor.pause = 1;
	cor.proc_num = 1;
	cor.stealth = 0;
	cor.cycles = 1;
	cor.dump = 0;
	cor.mon = 0;
	ft_bzero(cor.arena, sizeof(unsigned char) * MEM_SIZE);
	ft_bzero(cor.player, sizeof(t_player) * 4);
	init_players(&cor);
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			j = manage_flags(&cor, argv, i);
			if (j > i)
				i++;
			else if (j == -1)
				manage_files(&cor, argv[i]);
			i++;
			continue;
		}
		manage_files(&cor, argv[i]);
		i++;
	}
	validate_players(&cor);
	cor.process = NULL;
	def_num(&cor);
	cor.def_num = 1;
	cor.live_check = 1;
	cor.curr_cycle_t_d = CYCLE_TO_DIE;
	cor.curr_chechs = 0;
	if(cor.p_num == 0)
		usadge();
	to_map(&cor);
	system("leaks -quiet corewar");
	return(0);
}