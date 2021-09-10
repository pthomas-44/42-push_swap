/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:43:16 by pthomas           #+#    #+#             */
/*   Updated: 2021/09/10 14:12:49 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stacks(t_structs *s, int size)
{
	s->size = size;
	s->a = NULL;
	s->b = NULL;
}

t_stack	*stk_get_last(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	stk_add_new(t_structs *s, int nb)
{
	t_stack	*elem;
	t_stack	*last;

	elem = malloc(sizeof(t_stack));
	if (!elem)
		ft_exit(s, "error: malloc error\n", -1);
	elem->nb = nb;
	elem->next = NULL;
	if (!s->a)
	{
		s->a = elem;
	}
	else
	{
		last = stk_get_last(s->a);
		last->next = elem;
	}
}

void	arg_checker(t_structs *s, int ac, char **av)
{
	unsigned int	i;
	unsigned int	j;

	if (ac < 2)
		ft_exit(s, "error: missing arguments\n", -1);
	i = 0;
	while (av[++i])
	{
		j = i;
		while (++j <= s->size)
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				ft_exit(s, "error: duplicate arguments\n", -1);
		if (!ft_isdigit(av[i][0]) && av[i][0] != '-')
			ft_exit(s, "error: argument is not an integer\n", -1);
		j = 0;
		while (av[i][++j])
			if (!ft_isdigit(av[i][j]))
				ft_exit(s, "error: argument is not an integer\n", -1);
		if (ft_atoi(av[i]) < INT_MIN || ft_atoi(av[i]) > INT_MAX)
			ft_exit(s, "error: argument is not an integer\n", -1);
		stk_add_new(s, ft_atoi(av[i]));
	}
	if (is_sort(s->a))
		ft_exit(s, "", 0);
}
