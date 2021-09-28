/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:55:06 by pthomas           #+#    #+#             */
/*   Updated: 2021/09/28 14:12:13 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	get_highest(t_stack *a)
{
	unsigned int	i;
	int				high_value;
	int				high_index;

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

int	get_closest(t_stack *a, int maxchunk)
{
	unsigned int	i;
	unsigned int	closest;

	i = 0;
	closest = 0;
	while (i < a->size)
	{
		if (a->stk[i] < maxchunk)
		{
			closest = i;
			break ;
		}
		i++;
	}
	i = a->size - 1;
	while (i > a->size - closest)
	{
		if (a->stk[i] < maxchunk)
		{
			closest = i;
			break ;
		}
		i--;
	}
	return (closest);
}
