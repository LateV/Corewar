/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:45:35 by vibondar          #+#    #+#             */
/*   Updated: 2018/09/20 20:45:37 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline	static	int	flag_n(t_cor *cor, char **argv, int i)
{
	int				num;
	int				j;

	j = 0;
	if (argv[i + 1] == NULL)
		ft_error(cor, "Invalid format in flag -n");
	num = val_int(cor, argv[i], argv[i + 1]);
	if (num > 4 || num < 1)
		ft_error(cor, "Number of the player must be [1-4]");
	while (j < 4)
	{
		if (cor->player[j].num == num)
			return (i + 1);
		j++;
	}
	cor->flag_p_num = num;
	return (i + 1);
}

inline	static	int	flag_dump(t_cor *cor, char **argv, int i)
{
	int			num;

	if (argv[i + 1] == NULL)
		ft_error(cor, "Invalid format in flag -dump");
	num = val_int(cor, argv[i], argv[i + 1]);
	if (num == 0)
		num = 1;
	cor->dump = num;
	return (i + 1);
}

inline	static	int	flag_s(t_cor *cor, char **argv, int i)
{
	int				num;

	if (argv[i + 1] == NULL)
		ft_error(cor, "Invalid format in flag -s");
	num = val_int(cor, argv[i], argv[i + 1]);
	if (num == 0)
		ft_error(cor, "Invalid format in flag -s(must by > 0)");
	cor->s = num;
	return (i + 1);
}

inline	static	int	flag_mon(t_cor *cor, char **argv, int i)
{
	int				num;

	if (argv[i + 1] == NULL)
		ft_error(cor, "Invalid format in flag -mon");
	num = val_int(cor, argv[i], argv[i + 1]);
	if (num == 0)
		ft_error(cor, "Invalid format in flag -mon(must by > 0)");
	cor->mon = num;
	return (i + 1);
}

int					manage_flags(t_cor *cor, char **argv, int i)
{
	if (ft_strcmp(argv[i], "-n") == 0)
		return (flag_n(cor, argv, i));
	if (ft_strcmp(argv[i], "-v") == 0)
		return (simple_flag(i, &cor->visu));
	if (ft_strcmp(argv[i], "-a") == 0)
		return (simple_flag(i, &cor->a));
	if (ft_strcmp(argv[i], "-log") == 0)
		return (simple_flag(i, &cor->log));
	if (ft_strcmp(argv[i], "--stealth") == 0)
		return (simple_flag(i, &cor->stealth));
	if (ft_strcmp(argv[i], "-dump") == 0)
		return (flag_dump(cor, argv, i));
	if (ft_strcmp(argv[i], "-mon") == 0)
		return (flag_mon(cor, argv, i));
	if (ft_strcmp(argv[i], "-s") == 0)
		return (flag_s(cor, argv, i));
	if (ft_strcmp(argv[i], "-force") == 0)
		return (flag_force(cor, argv, i));
	return (-1);
}
