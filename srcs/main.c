/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:29:29 by pthomas           #+#    #+#             */
/*   Updated: 2021/09/16 17:44:42 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_exit(t_structs *s, char *errormsg, int status)
{
	free(s->a.stk);
	free(s->b.stk);
	write(1, errormsg, ft_strlen(errormsg));
	exit(status);
}

void	print_stacks(t_structs *s)
{
	unsigned int	i;

	i = 0;
	printf("---|a|---\n");
	if (s->a.stk)
	{
		while (i < s->a.size)
		{
			printf("%d\n", s->a.stk[i]);
			i++;
		}
	}
	i = 0;
	printf("---|b|---\n");
	if (s->b.stk)
	{
		while (i < s->b.size)
		{
			printf("%d\n", s->b.stk[i]);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	t_structs	s;

	init_stacks(&s, ac - 1);
	arg_checker(&s, ac, av);
	sort(&s);
	ft_exit(&s, "", 0);
	return (0);
}
