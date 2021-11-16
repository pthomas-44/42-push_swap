/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 10:26:35 by pthomas           #+#    #+#             */
/*   Updated: 2021/11/16 15:04:23 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_structs *s)
{
	unsigned int	highest;
	unsigned int	lowest;

	while (!is_sort(s->a))
	{
		highest = get_highest(&s->a);
		lowest = get_lowest(&s->a);
		if (highest == 0 && lowest == 1)
			do_op(&s->a, &s->b, "ra\n");
		else if (highest == 1 && lowest == 2)
			do_op(&s->a, &s->b, "rra\n");
		else
			do_op(&s->a, &s->b, "sa\n");
	}
}

void	sort_five(t_structs *s)
{
	unsigned int	lowest;

	while (!is_sort(s->a) || s->b.size)
	{
		lowest = get_lowest(&s->a);
		if (s->b.size == 2)
		{
			sort_three(s);
			do_op(&s->a, &s->b, "pa\n");
			do_op(&s->a, &s->b, "pa\n");
		}
		else if (!lowest && s->b.size < 2)
			do_op(&s->a, &s->b, "pb\n");
		else if (s->b.size < 2 && lowest < 3 && lowest)
			do_op(&s->a, &s->b, "ra\n");
		else if (s->b.size < 2 && lowest > 2 && lowest)
			do_op(&s->a, &s->b, "rra\n");
	}
}

void	sort_hundred(t_structs *s, int chunk_size)
{
	unsigned int	maxchunk;

	maxchunk = 0;
	while (s->a.size)
	{
		maxchunk += chunk_size;
		if ((float)s->a.size / 4.2 > 5)
			chunk_size = s->a.size / 5;
		while (s->a.size && s->b.size < maxchunk)
		{
			gtt_closest_hundred(s, maxchunk);
			get_to_top(s, get_previous(&s->b, s->a.stk[0]), s->b.size, 'b');
			do_op(&s->a, &s->b, "pb\n");
		}
	}
	get_to_top(s, get_highest(&s->b), s->b.size, 'b');
	while (s->b.size)
		do_op(&s->a, &s->b, "pa\n");
}

void	sort_thousands(t_structs *s)
{
	t_chunk	chunk;

	chunk.max = 0;
	while (s->a.size)
	{
		chunk = init_chunk_one(s, chunk);
		push_chunk(s, chunk, 'b');
	}
	chunk.min = s->size;
	while (s->b.size)
	{
		chunk = init_chunk_two(s, chunk);
		push_chunk(s, chunk, 'a');
	}
	chunk.max = s->size / 64;
	while (s->a.size)
	{
		chunk = init_chunk_three(s, chunk);
		push_chunk(s, chunk, 'b');
	}
	while (s->b.size)
	{
		get_to_top(s, get_highest(&s->b), s->b.size, 'b');
		do_op(&s->a, &s->b, "pa\n");
	}
}
