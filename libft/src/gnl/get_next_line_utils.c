/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 08:51:39 by pthomas           #+#    #+#             */
/*   Updated: 2021/11/13 23:10:44 by dev              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_gnl_fds	*gnl_lstadd_front(t_gnl_fds **start, int fd)
{
	t_gnl_fds	*new;
	int			ret;

	new = ft_calloc(1, sizeof(t_gnl_fds));
	if (!new)
		return (NULL);
	ret = read(fd, new->buf, BUFFER_SIZE);
	if (ret == -1)
	{
		free(new);
		return (NULL);
	}
	new->buf[ret] = '\0';
	new->i = 0;
	new->fd = fd;
	new->next = *start;
	*start = new;
	return (new);
}

void	gnl_lstdelone(t_gnl_fds **start, t_gnl_fds *elem)
{
	t_gnl_fds	*current;

	if (elem == *start)
	{
		*start = elem->next;
		free(elem);
	}
	else
	{
		current = *start;
		while (current->next != elem)
			current = current->next;
		current->next = elem->next;
		free(elem);
	}
}
