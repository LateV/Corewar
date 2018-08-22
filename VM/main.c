#include "vm.h"

int manage_flags(char arg, char **argv, int i)
{
	return(i);
}

int manage_files(char arg, char **argv, int i)
{
	int fd;

	fd = open(arg);
	return(i);
}

int main(int argc, char **argv)
{
	t_cor cor;
	char *arg;
	int i;

	i = 1;
	while(i < argc)
	{
		arg = ft_strtrim(argv[i]);
		if(arg[0] == '-')
			i = manage_flags(arg, argv, i);
		else
			i = manage_files(arg, argv, i);
		free(arg);
		i++;
	}
	system("leaks -quiet corewar");
	return(0);
}