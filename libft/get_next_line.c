/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:03:41 by vibondar          #+#    #+#             */
/*   Updated: 2018/02/13 13:03:43 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*create_new_fd_list(t_list **root, int fd)
{
	t_fd	fd_content;
	t_list	*new_lst;

	fd_content.remainder = ft_memalloc(BUFF_SIZE + 1);
	fd_content.fd = fd;
	new_lst = ft_lstnew(&fd_content, sizeof(t_fd));
	ft_lstadd_back(root, new_lst);
	return (*root);
}

static t_list	*find_fd_list(t_list *root, int fd)
{
	t_list	*tmp;

	tmp = root;
	while (tmp != NULL)
	{
		if (((t_fd*)tmp->content)->fd - fd == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static int		get_full_line(char **line, char *remainder, int fd)
{
	char	buffer[BUFF_SIZE + 1];
	int		readed;
	char	*tmp_line_pointer;
	char	*nl_check;

	while ((readed = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[readed] = '\0';
		if ((nl_check = ft_strchr(buffer, '\n')) != NULL)
		{
			ft_strcpy(remainder, nl_check + 1);
			*nl_check = '\0';
		}
		tmp_line_pointer = *line;
		if ((*line = ft_strjoin(*line, buffer)) == NULL)
			return (-1);
		free(tmp_line_pointer);
		if (nl_check != NULL)
			return (1);
	}
	if (readed < 0)
		return (-1);
	return (**line == '\0' ? 0 : 1);
}

static void		free_list(t_list **root, int fd)
{
	t_list	**tmp_root_ptr;
	t_list	*curr_fd_list_ptr;

	tmp_root_ptr = root;
	while (*tmp_root_ptr)
	{
		if (((t_fd*)(*tmp_root_ptr)->content)->fd - fd == 0)
		{
			curr_fd_list_ptr = *tmp_root_ptr;
			*tmp_root_ptr = (*tmp_root_ptr)->next;
			free(((t_fd*)curr_fd_list_ptr->content)->remainder);
			free((t_fd*)curr_fd_list_ptr->content);
			free(curr_fd_list_ptr);
		}
		else
		{
			tmp_root_ptr = &(*tmp_root_ptr)->next;
		}
	}
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*root;
	t_list			*fd_index_list;
	int				return_index;
	char			*tmp_remainder_ptr;
	char			*nl_check;

	if (line == NULL || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if ((fd_index_list = find_fd_list(root, fd)) == NULL)
		fd_index_list = create_new_fd_list(&root, fd);
	tmp_remainder_ptr = ((t_fd*)fd_index_list->content)->remainder;
	if ((*line = ft_strdup(tmp_remainder_ptr)) == NULL)
		return (-1);
	ft_memset(tmp_remainder_ptr, 0, BUFF_SIZE + 1);
	if ((nl_check = ft_strchr(*line, '\n')) != NULL)
	{
		ft_strcpy(tmp_remainder_ptr, nl_check + 1);
		*nl_check = '\0';
		return (1);
	}
	if ((return_index = get_full_line(line, tmp_remainder_ptr, fd)) <= 0)
		free_list(&root, fd);
	return (return_index);
}