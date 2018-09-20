/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 15:40:31 by oskulska          #+#    #+#             */
/*   Updated: 2018/09/13 15:40:37 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_def_cmd		g_cmd_def[17] = {
	{1, "live", 1, {2, 0, 0}, {0, 0, 0}, {0, 0}, 4, 0},
	{2, "ld", 2, {2, 3, 0}, {1, 0, 0}, {0, 0}, 4, 1},
	{11, "sti", 3, {1, 0, 0}, {1, 2, 3}, {1, 2}, 2, 1},
	{3, "st", 2, {1, 0, 0}, {1, 3, 0}, {0, 0}, 4, 1},
	{4, "add", 3, {1, 0, 0}, {1, 0, 0}, {1, 0}, 4, 1},
	{5, "sub", 3, {1, 0, 0}, {1, 0, 0}, {1, 0}, 4, 1},
	{6, "and", 3, {3, 2, 1}, {3, 2, 1}, {1, 0}, 4, 1},
	{7, "or", 3, {3, 2, 1}, {3, 2, 1}, {1, 0}, 4, 1},
	{8, "xor", 3, {3, 2, 1}, {3, 2, 1}, {1, 0}, 4, 1},
	{9, "zjmp", 1, {2, 0, 0}, {0, 0, 0}, {0, 0}, 2, 0},
	{10, "ldi", 3, {3, 2, 1}, {1, 2, 0}, {1, 0}, 2, 1},
	{12, "fork", 1, {2, 0, 0}, {0, 0, 0}, {0l, 0}, 2, 0},
	{14, "lldi", 3, {1, 2, 3}, {1, 2, 0}, {1, 0}, 2, 1},
	{13, "lld", 2, {2, 3, 0}, {1, 0, 0}, {0, 0}, 4, 1},
	{15, "lfork", 1, {2, 0, 0}, {0, 0, 0}, {0, 0}, 2, 0},
	{16, "aff", 1, {1, 0, 0}, {0, 0, 0}, {0, 0}, 4, 1},
	{0, "NULL", 1, {0, 0, 0}, {0, 0, 0}, {0, 0}, 0, 0}
};


int				check_extension(const char **str, int y)
{
	size_t		len;

	len = ft_strlen(str[y]);
	if (str[y][len - 1] == 's' && str[y][len - 2] == '.')
		return (y);
	return (0);
}

int				main(int argc, char const *argv[])
{
	t_header	*header;
	int			y;

	init_struct(&header);
	if (argc > 1)
	{
		if ((y = check_extension(argv, argc - 1)) > 0)
			read_file(argv[y], &header);
		else
			error_exit("Can't open a file", argv[argc - 1]);
	}
	else
		ft_printf("Usage: ./asm <sourcefile.s>");
	return (0);
}
