/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:29:29 by pthomas           #+#    #+#             */
/*   Updated: 2021/09/10 14:13:22 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stacks(t_structs *s)
{
	t_stack	*tmpa;
	t_stack	*tmpb;

	tmpa = s->a;
	tmpb = s->b;
	printf("---|a|---\n");
	if (tmpa)
	{
		while (tmpa)
		{
			printf("%d\n", tmpa->nb);
			tmpa = tmpa->next;
		}
	}
	printf("---|b|---\n");
	if (tmpb)
	{
		while (tmpb)
		{
			printf("%d\n", tmpb->nb);
			tmpb = tmpb->next;
		}
	}
}

int	is_sort(t_stack *stack)
{
	t_stack	*tmpstack;
	int		tmp;

	tmpstack = stack->next;
	tmp = stack->nb;
	while (tmpstack)
	{
		if (tmp > tmpstack->nb)
			return (0);
		tmp = tmpstack->nb;
		tmpstack = tmpstack->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_structs	s;

	init_stacks(&s, ac - 1);
	arg_checker(&s, ac, av);
	push_swap(&s);
	ft_exit(&s, "", 0);
	return (0);
}
