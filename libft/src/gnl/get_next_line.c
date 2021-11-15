/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 08:51:40 by pthomas           #+#    #+#             */
/*   Updated: 2021/11/13 23:36:34 by dev              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	gnl_linelen(t_gnl_fds *actual)
{
	size_t	i;

	i = actual->i;
	while (actual->buf[i] && actual->buf[i] != '\n')
		i++;
	return (i - actual->i);
}

static t_gnl_fds	*gnl_get_actual(t_gnl_fds **start, int fd)
{
	t_gnl_fds	*current;

	current = *start;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	return (gnl_lstadd_front(start, fd));
}

static int	gnl_fill_buffer(t_gnl_fds *act)
{
	int	ret;

	ret = 0;
	ret = (read(act->fd, act->buf, BUFFER_SIZE));
	if (ret == -1)
		return (-1);
	act->buf[ret] = '\0';
	act->i = 0;
	return (ret);
}

static char	**gnl_get_line(t_gnl_fds *act, char **line)
{
	char	*linetmp;
	int		i;

	(*line) = ft_calloc(gnl_linelen(act) + 1, sizeof(char));
	if (!*line)
		return (NULL);
	i = 0;
	while (act->buf[act->i] && act->buf[act->i] != '\n')
	{
		(*line)[i] = act->buf[act->i];
		i++;
		(act->i)++;
	}
	(*line)[i] = '\0';
	if (act->buf[act->i] == '\0' && act->i < BUFFER_SIZE)
		return (line);
	else if (act->buf[act->i] != '\n')
	{
		if (gnl_fill_buffer(act) == -1)
			return (0);
		*line = ft_strjoin(*line, *(gnl_get_line(act, &linetmp)), 3);
		if (!*line)
			return (NULL);
	}
	return (line);
}

int	get_next_line(int fd, char **line)
{
	static t_gnl_fds	*start;
	t_gnl_fds			*act;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (-1);
	act = gnl_get_actual(&start, fd);
	if (!act)
		return (-1);
	if (act->buf[act->i] == 0 && fd == 0)
		if (gnl_fill_buffer(act) == -1)
			return (-1);
	line = gnl_get_line(act, line);
	if (!line)
		return (-1);
	if (act->i == BUFFER_SIZE)
		if (gnl_fill_buffer(act) == -1)
			return (-1);
	if (act->buf[act->i++] == '\0')
	{
		gnl_lstdelone(&start, act);
		return (0);
	}
	return (1);
}
