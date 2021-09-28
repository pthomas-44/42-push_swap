/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:22:14 by pthomas           #+#    #+#             */
/*   Updated: 2021/09/28 16:47:48 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_op(t_stack *a, t_stack *b, char *action)
{
	if (!action)
		return ;
	if (action[0] == 's')
		swap(a, b, action);
	else if (action[0] == 'p')
	{
		if (action[1] == 'a')
			push(b, a);
		else if (action[1] == 'b')
			push(a, b);
	}
	else if (action[0] == 'r' && ft_strlen(action) == 3)
		rotate(a, b, action);
	else if (action[0] == 'r' && ft_strlen(action) == 4)
		reverse_rotate(a, b, action);
	write(1, action, ft_strlen(action));
}

void	swap(t_stack *a, t_stack *b, char *action)
{
	if (!ft_strcmp(action, "sa\n") || !ft_strcmp(action, "ss\n"))
		ft_swap(&a->stk[0], &a->stk[1]);
	if (!ft_strcmp(action, "sb\n") || !ft_strcmp(action, "ss\n"))
		ft_swap(&b->stk[0], &b->stk[1]);
}

void	push(t_stack *from, t_stack *to)
{
	unsigned int	i;

	i = to->size;
	to->size++;
	while (i)
	{
		ft_swap(&to->stk[i], &to->stk[i - 1]);
		i--;
	}
	ft_swap(&from->stk[0], &to->stk[0]);
	while (i < from->size)
	{
		ft_swap(&from->stk[i], &from->stk[i + 1]);
		i++;
	}
	from->size--;
}

void	rotate(t_stack *a, t_stack *b, char *action)
{
	unsigned int	i;

	if (a && (!ft_strcmp(action, "ra\n") || !ft_strcmp(action, "rr\n")))
	{
		i = 1;
		while (i < a->size)
		{
			ft_swap(&a->stk[i - 1], &a->stk[i]);
			i++;
		}
	}
	if (b && (!ft_strcmp(action, "rb\n") || !ft_strcmp(action, "rr\n")))
	{
		i = 1;
		while (i < b->size)
		{
			ft_swap(&b->stk[i - 1], &b->stk[i]);
			i++;
		}
	}
}

void	reverse_rotate(t_stack *a, t_stack *b, char *action)
{
	unsigned int	i;

	if (a && (!ft_strcmp(action, "rra\n") || !ft_strcmp(action, "rrr\n")))
	{
		i = a->size;
		while (i)
		{
			ft_swap(&a->stk[i], &a->stk[i - 1]);
			i--;
		}
		ft_swap(&a->stk[0], &a->stk[a->size]);
	}
	if (b && (!ft_strcmp(action, "rrb\n") || !ft_strcmp(action, "rrr\n")))
	{
		i = b->size;
		while (i)
		{
			ft_swap(&b->stk[i], &b->stk[i - 1]);
			i--;
		}
		ft_swap(&b->stk[0], &b->stk[b->size]);
	}
}
