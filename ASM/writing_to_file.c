/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_to_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:13:13 by oskulska          #+#    #+#             */
/*   Updated: 2018/09/13 19:13:15 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	int		get_prog_name(t_header *header)
{
	char		*str;
	char		*s;
	int			len;
	int			fd;

	str = ft_strrchr(header->file_name, '/');
	len = ft_strlen(str);
	while (len > 0)
	{
		if (str[len] == '.')
			break ;
		len--;
	}
	s = ft_strsub(str, 1, len - 1);
	free(header->file_name);
	header->file_name = ft_strjoin(s, ".cor");
	free(s);
	fd = open(header->file_name, O_CREAT |
		O_TRUNC | O_WRONLY, S_IRWXU | S_IRWXG | S_IROTH);
	if (fd == -1)
	{
		ft_free(&header);
		error_exit("Error creating ", "a .cor file");
	}
	return (fd);
}

static	void	print_to_file(int fd, int byte, int param)
{
	int i;

	i = 3;
	t_byterange.num = param;
	if (byte == 1)
		ft_putchar_fd(t_byterange.num, fd);
	if (byte == 2)
	{
		ft_putchar_fd(t_byterange.ch2[1], fd);
		ft_putchar_fd(t_byterange.ch2[0], fd);
	}
	if (byte == 4)
		while (i > -1)
		{
			ft_putchar_fd(t_byterange.ch[i], fd);
			i--;
		}
}

static	void	add_zero(int num, int fd)
{
	while (num > 0)
	{
		print_to_file(fd, 1, 0);
		num--;
	}
}

static	void	write_command_to_file(t_header *header, int fd)
{
	t_command	*tmp;
	int			i;

	tmp = header->cmd_list;
	while (tmp)
	{
		if (tmp->opcode > 0)
		{
			t_byterange.num = tmp->opcode;
			print_to_file(fd, 1, tmp->opcode);
			if (tmp->is_codage_octal == 1)
				print_to_file(fd, 1, tmp->codage_octal);
			i = 0;
			while (i < 3)
			{
				if (tmp->arg_type[i])
					print_to_file(fd, tmp->byte_sum[i], tmp->num_arg[i]);
				i++;
			}
		}
		tmp = tmp->next;
	}
}

void			write_to_file(t_header *header)
{
	int i;
	int fd;

	fd = get_prog_name(header);
	print_to_file(fd, 4, COREWAR_EXEC_MAGIC);
	i = 0;
	while (header->bot_name[i])
	{
		print_to_file(fd, 1, header->bot_name[i]);
		i++;
	}
	add_zero(PROG_NAME_LENGTH - header->name__len + 4, fd);
	print_to_file(fd, 4, header->prog_size);
	i = 0;
	while (header->comment[i])
	{
		print_to_file(fd, 1, header->comment[i]);
		i++;
	}
	add_zero(COMMENT_LENGTH - header->comment_len + 4, fd);
	write_command_to_file(header, fd);
	ft_printf("Writing output program to %s\n", header->file_name);
	ft_free(&header);
}
