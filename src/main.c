/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:29:29 by pthomas           #+#    #+#             */
/*   Updated: 2021/11/16 00:12:06 by dev              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(t_structs *s, char *errormsg, int status)
{
	free(s->a.stk);
	free(s->b.stk);
	write(1, errormsg, ft_strlen(errormsg));
	exit(status);
}

void	sort(t_structs *s)
{
	if (s->size <= 3)
		sort_three(s);
	else if (s->size <= 5)
		sort_five(s);
	else if (s->size <= 100)
		sort_hundred(s, (float)s->size / 4.2);
	else
		sort_thousands(s);
}

int	main(int ac, char **av)
{
	t_structs	s;

	init_stacks(&s, ac - 1);
	arg_checker(&s, ac, av);
	if (is_sort(s.a))
		ft_exit(&s, "", 0);
	sort(&s);
	ft_exit(&s, "", 0);
	return (0);
}
