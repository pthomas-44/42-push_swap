/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:22:14 by pthomas           #+#    #+#             */
/*   Updated: 2021/09/10 14:11:02 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*elem;

	if (*stack)
	{
		elem = (*stack)->next;
		(*stack)->next = elem->next;
		elem->next = (*stack);
		(*stack) = elem;
	}
}

void	push(t_stack **from, t_stack **to)
{
	t_stack	*elem;

	if (*from)
	{
		elem = (*from);
		(*from) = (*from)->next;
		elem->next = (*to);
		(*to) = elem;
	}
}

void	rotate(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (*a)
	{
		first = (*a);
		last = stk_get_last(*a);
		last->next = first;
		(*a) = first->next;
		first->next = NULL;
	}
	if (*b)
	{
		first = (*b);
		last = stk_get_last(*b);
		last->next = first;
		(*b) = first->next;
		first->next = NULL;
	}
}

void	reverse_rotate(t_stack **a, t_stack **b)
{
	t_stack	*last;
	t_stack	*tmp;

	if (*a)
	{
		last = stk_get_last(*a);
		tmp = (*a);
		while (tmp->next != last)
			tmp = tmp->next;
		tmp->next = NULL;
		last->next = (*a);
		(*a) = last;
	}
	if (*b)
	{
		last = stk_get_last(*b);
		tmp = (*b);
		while (tmp->next != last)
			tmp = tmp->next;
		tmp->next = NULL;
		last->next = (*b);
		(*b) = last;
	}
}
