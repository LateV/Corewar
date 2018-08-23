#include "vm.h"

void	ft_reverse_bits(void *a, size_t size) // to.do : 
{
	size_t	i;
	char	tmp;
	char	*bits;

	i = 0;
	bits = (char*)a;
	while (i != size - i)
	{
		tmp = bits[i];
		bits[i] = bits[size - 1 - i];
		bits[size - 1 - i] = tmp;
		i++;
	}
}

void	ft_error(t_cor *cor, char *error)
{
	cor->p_num = cor->p_num;
	ft_putstr(error);
	exit(0);
}

int		manage_flags(t_cor *cor, char **argv, int i)
{
	cor->p_num = cor->p_num;
	printf("argv[i] = %s\n", argv[i]);
	return(i);
}

void cor_format(t_cor *cor, char *path)
{
	int i;

	i = ft_strlen(path);
	if(i - 5 > 0)
	{
		if(ft_strcmp(path + i - 4, ".cor") != 0)
			ft_error(cor, "Bad file name (must by file_name.cor)\n");
	}
	else
		ft_error(cor , "Bad input file\n");
}

void	calculate_p_num(t_cor *cor)
{
	int i;

	i = 0;
	if(cor->p_num > 3)
		ft_error(cor, "Error: max 4 players\n");
	if(cor->flag_p_num == -1)
	{
		cor->player[cor->p_num].num = cor->p_num + 1;
		cor->curr_pl = cor->player[cor->p_num].num;
		cor->p_num++;
	}
	else
	{
		cor->player[cor->p_num].num = cor->flag_p_num;
		cor->flag_p_num = -1;
		cor->curr_pl = cor->player[cor->p_num].num;
		cor->p_num++;
	}
}

void magic_header(char *argv)
{
	unsigned int i;
	// char		null[4];
	int fd;

	fd = open(argv, O_RDONLY);
	read(fd, &i, 4);
	printf("magic = %#x", i);
	// check_magic(i)
	// read(fd, &name, PROG_NAME_LENGTH);
	// read(fd, &null, 4);
	// check_null()
	// read(fd, &prog_size, 4);
	// read(fd, &comment, COMMENT_LENGTH);
	// read(fd, &null, 4);
	// check_null()
	// unsigned char *exec = malloc(sizeof(unsigned char) * prog_size);
	// read(fd, exec, prog_size);

}

void	manage_files(t_cor *cor, char *argv)
{
	cor_format(cor, argv);
	printf("argv[i] = %s\n", argv);
	calculate_p_num(cor);
	magic_header(argv);
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
	system("leaks -quiet corewar");
	return(0);
}