/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:48:06 by oskulska          #+#    #+#             */
/*   Updated: 2018/01/10 19:48:13 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BRK(ch) if (ch) break ;

static t_list	*create_list(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = ft_lstnew("", 1);
	if (tmp == NULL)
		return (NULL);
	tmp->content_size = fd;
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

static t_list	*find_correct_list(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if (((int)tmp->content_size) == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = create_list(file, fd);
	return (tmp);
}

static char		*ft_pointer(char **line, char *str)
{
	size_t	i;
	char	*str1;
	char	*temp;

	i = -1;
	if (str == NULL)
		return (NULL);
	str1 = ft_strdup(str);
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			str1[i] = '\0';
			*line = ft_strdup(str1);
			temp = str;
			str = ft_strsub(str, i + 1, ft_strlen(str));
			ft_strdel(&str1);
			ft_strdel(&temp);
			return (str);
		}
	}
	ft_strdel(&str1);
	if (i == ft_strlen(str))
		*line = str;
	return (ft_strdup("\0"));
}

static char		*ft_read(char *str, char *read_buf, int ret)
{
	char *temp;

	read_buf[ret] = '\0';
	(str == NULL) ? str = ft_strdup("") : str;
	temp = str;
	if (!(str = ft_strjoin(str, read_buf)))
		return (NULL);
	ft_strdel(&temp);
	return (str);
}

int				get_next_line(int fd, char **line)
{
	char			*read_buf;
	int				ret;
	static t_list	*file;
	t_list			*curr;

	if ((read_buf = ft_strnew(BUFF_SIZE)) == NULL || fd < 0 || !line)
		return (-1);
	curr = find_correct_list(&file, fd);
	if (curr->content != NULL && !ft_strlen(curr->content))
		ft_memdel(&curr->content);
	while ((ret = read((int)curr->content_size, read_buf, BUFF_SIZE)) > 0)
	{
		if (!(curr->content = ft_read(curr->content, read_buf, ret)))
			return (-1);
		BRK((ft_strchr(curr->content, 10)));
	}
	if (ret < 0)
	{
		free(read_buf);
		return (-1);
	}
	free(read_buf);
	if ((curr->content = ft_pointer(line, curr->content)))
		return (1);
	return (0);
}
