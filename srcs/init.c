/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:43:16 by pthomas           #+#    #+#             */
/*   Updated: 2021/10/02 18:11:04 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stacks(t_structs *s, int size)
{
	s->size = size;
	s->a.size = size;
	s->b.size = 0;
	s->a.stk = ft_calloc(size, sizeof(int));
	s->b.stk = ft_calloc(size, sizeof(int));
	if (!s->a.stk || !s->b.stk)
		ft_exit(s, "error: malloc error\n", -1);
}

void	indexer(t_structs *s, t_stack *a)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	index;
	int				*itab;

	i = 0;
	itab = ft_calloc(a->size, sizeof(int));
	if (!itab)
		ft_exit(s, "error: malloc error\n", -1);
	while (i < a->size)
	{
		j = 0;
		index = 0;
		while (j < a->size)
		{
			if (a->stk[j] < a->stk[i])
				index++;
			j++;
		}
		itab[i] = index;
		i++;
	}
	free(a->stk);
	a->stk = itab;
}

int	is_sort(t_stack a)
{
	unsigned int	i;

	i = 1;
	while (i < a.size)
	{
		if (a.stk[i - 1] >= a.stk[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_overflow(const char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	sign = 1;
	nb = 0;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		nb = nb * 10 + (*str - 48) * sign;
		str++;
		if ((nb >= 0 && sign == -1) || (nb < 0 && sign == 1))
			return (1);
	}
	return (0);
}

void	arg_checker(t_structs *s, int ac, char **av)
{
	unsigned int	i;
	unsigned int	j;

	if (ac < 2)
		ft_exit(s, "", -1);
	i = 0;
	while (av[++i])
	{
		j = i;
		while (++j <= s->size)
			if (ft_atoi(av[i]) == ft_atoi(av[j]) && ft_isdigit(av[j][0]))
				ft_exit(s, "error: duplicate arguments\n", -1);
		if ((!ft_isdigit(av[i][0]) && (av[i][0] != '-' || av[i][1] == 0))
			|| is_overflow(av[i]))
			ft_exit(s, "error: argument is not an integer\n", -1);
		j = 0;
		while (av[i][++j])
			if (!ft_isdigit(av[i][j]))
				ft_exit(s, "error: argument is not an integer\n", -1);
		s->a.stk[i - 1] = ft_atoi(av[i]);
	}
	indexer(s, &s->a);
}
