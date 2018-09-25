/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_players.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:46:55 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/20 20:46:57 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline static void		check_null(t_cor *cor, int fd, int i)
{
	int				ret;
	unsigned int	ch;

	ret = read(fd, &ch, 4);
	if (ret < 4 || ch != 0)
	{
		ft_putstr("NULL error in file: ");
		ft_error(cor, cor->player[i].file_path);
	}
}

inline static void		bot_size(t_cor *cor, int fd, int i)
{
	int	ret;

	ret = read(fd, &cor->player[i].prog_size, 4);
	if (ret < 4)
	{
		ft_putstr("Error in Bot size information in file: ");
		ft_error(cor, cor->player[i].file_path);
	}
	ft_reverse_bits((void*)&cor->player[i].prog_size,
		sizeof(cor->player[i].prog_size));
	if (cor->player[i].prog_size > 682)
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

inline static void		magic_header(t_cor *cor, int fd, int i)
{
	int	ret;

	ret = read(fd, &cor->player[i].magic, 4);
	if (ret < 4)
	{
		ft_putstr("Bad magic header in file: ");
		ft_error(cor, cor->player[i].file_path);
	}
	ft_reverse_bits((void*)&cor->player[i].magic,
		sizeof(cor->player[i].magic));
	if (COREWAR_EXEC_MAGIC != cor->player[i].magic)
	{
		ft_putstr("Bad magic header in file: ");
		ft_error(cor, cor->player[i].file_path);
	}
}

inline static void		check_name(t_cor *cor, int fd, int i)
{
	int	ret;
	int j;

	j = 0;
	ret = read(fd, &cor->player[i].prog_name, PROG_NAME_LENGTH);
	while (j < ret)
	{
		if (cor->player[i].prog_name[j] != 0)
			break ;
		j++;
	}
	if (ret < PROG_NAME_LENGTH || j == ret)
	{
		ft_putstr("Bad programm name length in file: ");
		ft_error(cor, cor->player[i].file_path);
	}
}

void					validate_players(t_cor *cor)
{
	int	fd;
	int	i;

	i = 0;
	while (i < cor->p_num && cor->player[i].file_path != NULL)
	{
		fd = open(cor->player[i].file_path, O_RDONLY);
		if (fd < 0)
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
