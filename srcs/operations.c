/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:22:14 by pthomas           #+#    #+#             */
/*   Updated: 2021/09/16 13:42:03 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap(t_stack *a, t_stack *b, char *action)
{
	if (a)
		ft_swap(&a->stk[0], &a->stk[1]);
	else if (b)
		ft_swap(&b->stk[0], &b->stk[1]);
	write(1, action, ft_strlen(action));
}

void	push(t_stack *from, t_stack *to, char *action)
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
	write(1, action, ft_strlen(action));
}

void	rotate(t_stack *a, t_stack *b, char *action)
{
	unsigned int	i;

	if (a)
	{
		i = 1;
		while (i < a->size)
		{
			ft_swap(&a->stk[i - 1], &a->stk[i]);
			i++;
		}
	}
	if (b)
	{
		i = 1;
		while (i < b->size)
		{
			ft_swap(&b->stk[i - 1], &b->stk[i]);
			i++;
		}
	}
	write(1, action, ft_strlen(action));
}

void	reverse_rotate(t_stack *a, t_stack *b, char *action)
{
	unsigned int	i;

	if (a)
	{
		i = a->size;
		while (i)
		{
			ft_swap(&a->stk[i], &a->stk[i - 1]);
			i--;
		}
		ft_swap(&a->stk[0], &a->stk[a->size]);
	}
	if (b)
	{
		i = b->size;
		while (i)
		{
			ft_swap(&b->stk[i], &b->stk[i - 1]);
			i--;
		}
		ft_swap(&b->stk[0], &b->stk[b->size]);
	}
	write(1, action, ft_strlen(action));
}
