#include "vm.h"

void	ft_error(t_cor *cor, char *error)
{
	cor->p_num = cor->p_num;
	ft_putstr(error);
	ft_putstr("\n");
	exit(0);
}

int flag_n(t_cor *cor, char **argv, int i)
{
	int num;
	int j;

	j = 0;
	if(argv[i + 1] == NULL)
		return(-1);
	num = ft_atoi(argv[i + 1]);
	if(num > 4 || num < 1)
		return(i);
	while(j < 4)
	{
		if(cor->player[j].num == num)
			return(i);
		j++;
	}
	cor->flag_p_num = num;
	return(i + 1);
}

int		manage_flags(t_cor *cor, char **argv, int i)
{

	if(ft_strcmp(argv[i], "-n") == 0)
		return(flag_n(cor, argv, i));
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
			ft_putstr("Can't read source file ");
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
	while(i < 4)
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
		ft_putstr(" bytes > 682 bytes)");
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
					break;
				}
				k = 0;
				cor->def_num++;
			}
		}
		i++;
	}
}

// void visual_init(t_cor *cor)
// {
// 	initscr();
// 	noecho();
// 	keypad(stdscr, true);
// 	curs_set(false);

// 	write(1, "\e[8;60;200;t", 14);
// 	cor->win1 = newwin(60, 150, 0, 0);
// 	cor->win2 = newwin(60, 50, 0, 150);
// 	refresh();
// 	box(cor->win1, 0, 0);
// 	box(cor->win2, 0, 0); 
// }

int main(int argc, char **argv)
{
	t_cor cor;
	int i;
	int j;

	i = 1;
	cor.p_num = 0;
	cor.flag_p_num = -1;
	cor.code_summ = 0;

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
	// visual_init(&cor);
	cor.process = NULL;
	def_num(&cor);
	cor.def_num = 1;
	to_map(&cor);

	system("leaks -quiet corewar");
	return(0);
}