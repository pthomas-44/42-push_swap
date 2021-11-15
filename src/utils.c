/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:55:06 by pthomas           #+#    #+#             */
/*   Updated: 2021/11/16 00:12:06 by dev              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_highest(t_stack *a)
{
	unsigned int	i;
	int				high_value;
	int				high_index;

	if (!a->size)
		return (0);
	i = 1;
	high_value = a->stk[0];
	high_index = 0;
	while (i < a->size)
	{
		if (a->stk[i] > high_value)
		{
			high_value = a->stk[i];
			high_index = i;
		}
		i++;
	}
	return (high_index);
}

int	get_lowest(t_stack *a)
{
	unsigned int	i;
	int				low_value;
	int				low_index;

	i = 1;
	low_value = a->stk[0];
	low_index = 0;
	while (i < a->size)
	{
		if (a->stk[i] < low_value)
		{
			low_value = a->stk[i];
			low_index = i;
		}
		i++;
	}
	return (low_index);
}

void	get_to_top(t_structs *s,
	unsigned int index, unsigned int size, char stack)
{
	int	gap;

	if (index <= size / 2)
		gap = index;
	else
		gap = size - index;
	while (gap > 0)
	{
		if (stack == 'a')
			do_op(&s->a, &s->b, get_action(&s->a, NULL, index, 0));
		else if (stack == 'b')
			do_op(&s->a, &s->b, get_action(NULL, &s->b, 0, index));
		gap--;
	}
}

int	get_closest(t_stack *a, int maxchunk, int minchunk)
{
	unsigned int	i;
	unsigned int	closest;

	i = 0;
	closest = 0;
	while (i < a->size)
	{
		if (minchunk <= a->stk[i] && a->stk[i] < maxchunk)
		{
			closest = i;
			break ;
		}
		i++;
	}
	i = a->size - 1;
	while (i < a->size && i > a->size - closest)
	{
		if (minchunk <= a->stk[i] && a->stk[i] < maxchunk)
		{
			closest = i;
			break ;
		}
		i--;
	}
	return (closest);
}

char	*get_action(t_stack *a, t_stack *b,
	unsigned int a_index, unsigned int b_index)
{
	if (a && a_index && b && b_index)
	{
		if (a_index <= a->size / 2 && b_index <= b->size / 2)
			return ("rr\n");
		else if (a_index > a->size / 2 && b_index > b->size / 2)
			return ("rrr\n");
	}
	if (a && a_index)
	{
		if (a_index <= a->size / 2)
			return ("ra\n");
		else if (a_index > a->size / 2)
			return ("rra\n");
	}
	if (b && b_index)
	{
		if (b_index <= b->size / 2)
			return ("rb\n");
		else if (b_index > b->size / 2)
			return ("rrb\n");
	}
	return (NULL);
}
