/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 10:26:35 by pthomas           #+#    #+#             */
/*   Updated: 2021/09/28 16:11:53 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_to_top(t_structs *s,
	unsigned int index, unsigned int size, char stack)
{
	int	gap;

	if (index <= size / 2)
		gap = index;
	else
		gap = size - index;
	while (gap)
	{
		if (stack == 'a')
			do_op(&s->a, &s->b, get_action(&s->a, NULL, index, 0));
		else if (stack == 'b')
			do_op(&s->a, &s->b, get_action(NULL, &s->b, 0, index));
		gap--;
	}
}

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

void	get_closest_to_top(t_structs *s, int maxchunk)
{
	unsigned int	closest;
	char			*action;

	closest = get_closest(&s->a, maxchunk);
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
		closest = get_closest(&s->a, maxchunk);
	}
}

void	sort_hundred(t_structs *s, int chunk_size)
{
	unsigned int	maxchunk;
	int tog = 1;

	maxchunk = 0;
	while (s->a.size)
	{
		maxchunk += chunk_size;
		if ((float)s->a.size / 4.2 > 5)
			chunk_size = s->a.size / 5;
		if (s->a.size <= 12)
			tog = 0;
		while (s->a.size && s->b.size < maxchunk)
		{
			if (tog)
			{
				get_closest_to_top(s, maxchunk);
				get_to_top(s, get_previous(&s->b, s->a.stk[0]), s->b.size, 'b');
			}
			else
			{
				get_to_top(s, get_highest(&s->b), s->b.size, 'b');
				get_to_top(s, get_lowest(&s->a), s->a.size, 'a');
			}
			do_op(&s->a, &s->b, "pb\n");
		}
	}
	get_to_top(s, get_highest(&s->b), s->b.size, 'b');
	while (s->b.size)
		do_op(&s->a, &s->b, "pa\n");
}
