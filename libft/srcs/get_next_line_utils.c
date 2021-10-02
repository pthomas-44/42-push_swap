/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 08:51:39 by pthomas           #+#    #+#             */
/*   Updated: 2021/03/04 09:40:01 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	linelen(t_buffer *act)
{
	size_t	i;

	i = act->i;
	while (act->buf[i] && act->buf[i] != '\n')
		i++;
	return (i - act->i);
}

void	lstdelone(t_buffer **start, t_buffer *act)
{
	t_buffer	*tmp;

	tmp = *start;
	if (*start == act)
	{
		*start = act->next;
		free(act);
	}
	else
	{
		while (tmp->next != act)
			tmp = tmp->next;
		tmp->next = act->next;
		free(act);
	}
}

t_buffer	*lstadd_front(t_buffer **start, int fd)
{
	t_buffer	*new;
	int			ret;

	new = malloc(sizeof(t_buffer));
	if (!new)
		return (0);
	(ret = read(fd, new->buf, BUFFER_SIZE));
	if (ret == -1)
	{
		free(new);
		return (0);
	}
	new->buf[ret] = 0;
	new->i = 0;
	new->fd = fd;
	new->next = *start;
	*start = new;
	return (new);
}
