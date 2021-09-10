/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:43:38 by pthomas           #+#    #+#             */
/*   Updated: 2021/09/10 14:02:46 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stk_clear(t_structs *s)
{
	t_stack	*tmp;

	while (s->a)
	{
		tmp = s->a;
		s->a = s->a->next;
		free(tmp);
	}
	while (s->b)
	{
		tmp = s->b;
		s->b = s->b->next;
		free(tmp);
	}
}

void	ft_exit(t_structs *s, char *errormsg, int status)
{
	stk_clear(s);
	write(1, errormsg, ft_strlen(errormsg));
	exit(status);
}
