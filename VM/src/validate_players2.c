/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_players2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:47:04 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/20 20:47:06 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		bot_comment(t_cor *cor, int fd, int i)
{
	int	ret;

	ret = read(fd, &cor->player[i].comment, COMMENT_LENGTH);
	if (ret < COMMENT_LENGTH)
	{
		ft_putstr("Error in comment in file: ");
		ft_error(cor, cor->player[i].file_path);
	}
}

void		bot_code(t_cor *cor, int fd, int i)
{
	unsigned int	ret;
	unsigned int	ret_p;
	unsigned char	buff[42];

	ret = 0;
	cor->player[i].code = ft_memalloc(sizeof(unsigned char)
	* cor->player[i].prog_size);
	ret = read(fd, cor->player[i].code, cor->player[i].prog_size);
	ret_p = read(fd, &buff, 2);
	if (ret < cor->player[i].prog_size || ret_p > 0)
	{
		ft_putstr("Error in lenth executable code in file: ");
		ft_error(cor, cor->player[i].file_path);
	}
}
