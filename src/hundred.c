/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:55:41 by pthomas           #+#    #+#             */
/*   Updated: 2021/11/16 15:04:21 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	gtt_closest_hundred(t_structs *s, int maxchunk)
{
	unsigned int	closest;
	char			*action;

	closest = get_closest(&s->a, maxchunk, 0);
	while (closest)
	{
		action = get_action(&s->a, &s->b,
				closest, get_previous(&s->b, s->a.stk[closest]));
		if (closest > s->b.size && !ft_strcmp(action, "ra\n")
			&& get_previous(&s->b, s->a.stk[closest]))
			do_op(&s->a, &s->b, "rr\n");
		else if (s->a.size - closest > s->b.size && !ft_strcmp(action, "rra\n")
			&& get_previous(&s->b, s->a.stk[closest]))
			do_op(&s->a, &s->b, "rrr\n");
		else
			do_op(&s->a, &s->b, action);
		closest = get_closest(&s->a, maxchunk, 0);
	}
}

int	get_previous(t_stack *b, int nb)
{
	unsigned int	i;
	int				prev_value;
	int				prev_index;
	int				is_prev;

	i = 0;
	prev_value = -1;
	prev_index = 0;
	is_prev = 0;
	while (b && i < b->size)
	{
		if (prev_value < b->stk[i] && b->stk[i] < nb)
		{
			prev_value = b->stk[i];
			prev_index = i;
			is_prev = 1;
		}
		i++;
	}
	if (!is_prev)
		return (get_highest(b));
	return (prev_index);
}
