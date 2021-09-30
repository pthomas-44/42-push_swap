/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thousand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:14:05 by pthomas           #+#    #+#             */
/*   Updated: 2021/09/30 14:12:18 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_chunk	init_chunk_one(t_structs *s, t_chunk chunk)
{
	chunk.min = chunk.max;
	if (!chunk.max)
		chunk.max = s->size / 2;
	else if (chunk.max < s->size - s->size / 32)
		chunk.max += chunk.max / 2;
	else
		chunk.max = s->size;
	chunk.mid = chunk.min + (chunk.max - chunk.min) / 2;
	return (chunk);
}

t_chunk	init_chunk_two(t_structs *s, t_chunk chunk)
{
	chunk.max = chunk.min;
	if (!chunk.max)
		chunk.max = s->size;
	chunk.min -= s->size / 16;
	if (chunk.min < 0 || chunk.min > s->size)
		chunk.min = 0;
	chunk.mid = chunk.min + (chunk.max - chunk.min) / 2;
	return (chunk);
}

t_chunk	init_chunk_three(t_structs *s, t_chunk chunk)
{
	chunk.min = chunk.max;
	if (chunk.min == s->size / 64)
		chunk.min = 0;
	chunk.max += s->size / 64;
	chunk.mid = chunk.min + (chunk.max - chunk.min) / 2;
	return (chunk);
}

void	push_chunk(t_structs *s, t_chunk chunk, char stack)
{
	if (stack == 'b')
	{
		while (s->a.size && s->b.size < chunk.max)
		{
			get_to_top(s, get_closest(&s->a, chunk.max, chunk.min),
				s->a.size, 'a');
			do_op(&s->a, &s->b, "pb\n");
			// if (s->b.stk[0] < chunk.mid && get_closest(&s->a, chunk.max, chunk.min) <= (int)s->a.size / 2)
				// do_op(&s->a, &s->b, "rr\n");
			if (s->b.stk[0] < chunk.mid)
				do_op(&s->a, &s->b, "rb\n");
		}
	}
	if (stack == 'a')
	{
		while (s->b.size && s->a.size < s->size - chunk.min)
		{
			get_to_top(s, get_closest(&s->b, chunk.max, chunk.min),
				s->b.size, 'b');
			do_op(&s->a, &s->b, "pa\n");
			// if (s->a.stk[0] < chunk.mid && get_closest(&s->b, chunk.max, chunk.min) <= (int)s->a.size / 2)
				// do_op(&s->a, &s->b, "rr\n");
			if (s->a.stk[0] > chunk.mid)
				do_op(&s->a, &s->b, "ra\n");
		}
	}
}
