#include "vm.h"

int		manage_flags(t_cor cor, char **argv, int i)
{
	return(i);
}

void cor_format(t_cor cor, char *path)
{
	int i;

	printf("path = %s\n", path);
	i = ft_strlen(path);
	printf("len = %d\n", i);

}

// void magic_header(char *line)
// {
// 	unsigned int i;
// 	char		null[4]

// 	read(fd, &i, 4);
// 	check_magic(i)
// 	read(fd, &name, PROG_NAME_LENGTH);
// 	read(fd, &null, 4);
// 	check_null()
// 	read(fd, &prog_size, 4);
// 	read(fd, &comment, COMMENT_LENGTH);
// 	read(fd, &null, 4);
// 	check_null()
// 	unsigned char *exec = malloc(sizeof(unsigned char) * prog_size);
// 	read(fd, exec, prog_size);

// }

void	manage_files(t_cor cor, char arg, char **argv)
{
	// int fd;

	// fd = open(arg, O_RDONLY);
	cor_format(arg);
	// magic_header(arg, fd);

	return(i);
}

int main(int argc, char **argv)
{
	t_cor cor;
	char *arg;
	int i;
	int j;

	i = 1;
	t_cor.p_num = 0;
	while(i < argc)
	{
		arg = ft_strtrim(argv[i]);
		if(arg[0] == '-')
			j = manage_flags(cor, arg, argv, i);
		manage_files(cor, arg);
		free(arg);
		i++;
	}
	system("leaks -quiet corewar");
	return(0);
}