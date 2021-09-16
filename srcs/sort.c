/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 10:26:35 by pthomas           #+#    #+#             */
/*   Updated: 2021/09/16 19:24:50 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack *a)
{
	unsigned int	highest;
	unsigned int	lowest;

	while (!is_sort(*a))
	{
		highest = get_highest(a);
		lowest = get_lowest(a);
		if (highest == 0 && lowest == 1)
			rotate(a, NULL, "ra\n");
		else if (highest == 1 && lowest == 2)
			reverse_rotate(a, NULL, "rra\n");
		else
			swap(a, NULL, "sa\n");
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
			sort_three(&s->a);
			push(&s->b, &s->a, "pa\n");
			push(&s->b, &s->a, "pa\n");
		}
		else if (!lowest && s->b.size < 2)
			push(&s->a, &s->b, "pb\n");
		else if (s->b.size < 2 && lowest < 3 && lowest)
			rotate(&s->a, NULL, "ra\n");
		else if (s->b.size < 2 && lowest > 2 && lowest)
			reverse_rotate(&s->a, NULL, "rra\n");
	}
}

void	sort_hundred(t_structs *s)
{
	unsigned int	maxchunk;

	maxchunk = 0;
	while (s->a.size)
	{
		maxchunk += 20;
		while (s->a.size && s->b.size < maxchunk)
		{
			get_to_top(&s->a, get_closest(&s->a, maxchunk), 'a');
			get_to_top(&s->b, get_previous(&s->b, s->a.stk[0]), 'b');
			push(&s->a, &s->b, "pb\n");
		}
	}
	get_to_top(&s->b, get_highest(&s->b), 'b');
	while (s->b.size)
		push(&s->b, &s->a, "pa\n");
}

void	sort(t_structs *s)
{
	if (s->size <= 3)
		sort_three(&s->a);
	else if (s->size <= 5)
		sort_five(s);
	else if (s->size <= 100)
		sort_hundred(s);
}
