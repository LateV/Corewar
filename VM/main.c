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
	return(i);
}

void cor_format(t_cor *cor, char *path)
{
	int i;

	if(cor->p_num > 3)
		ft_error(cor, "Error: max 4 players");
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
}

void	calculate_p_num(t_cor *cor)
{
	int i;

	i = 0;
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
		cor->player[cor->p_num].num = cor->p_num + 1;
		cor->curr_pl = cor->player[cor->p_num].num;
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
	// ft_reverse_bits((void*)&cor->player[i].prog_name, PROG_NAME_LENGTH);
	// write(1, cor->player[i].prog_name, PROG_NAME_LENGTH);
	// printf("\n");
	
	// read(fd, &null, 4);
	// check_null()
	// read(fd, &prog_size, 4);
	// read(fd, &comment, COMMENT_LENGTH);
	// read(fd, &null, 4);
	// check_null()
	// unsigned char *exec = malloc(sizeof(unsigned char) * prog_size);
	// read(fd, exec, prog_size);
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

void	validate_players(t_cor *cor)
{
	int fd;
	int i;

	i = 0;
	while(i < cor->p_num)
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
		// check_null();
		// bot_size();
		// bot_comment();
		// check_null();
		// bot_code();
		// check_size();
		i++;
	}
}

int main(int argc, char **argv)
{
	t_cor cor;
	int i;
	int j;

	i = 1;
	cor.p_num = 0;
	cor.flag_p_num = -1;
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
	system("leaks -quiet corewar");
	return(0);
}