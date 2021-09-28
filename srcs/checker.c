/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:55:54 by pthomas           #+#    #+#             */
/*   Updated: 2021/09/28 16:33:28 by pthomas          ###   ########lyon.fr   */
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

void	do_command(t_stack *a, t_stack *b, char *action)
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
}

void    print_stacks(t_structs *s)
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
	int			ret;
	char		*action;

	action = NULL;
	ret = 1;
	init_stacks(&s, ac - 1);
	arg_checker(&s, ac, av);
	print_stacks(&s);
	while (ret)
	{
		ret = get_next_line(0, &action);
		if (ret == -1)
			ft_exit(&s, "error: malloc error\n", 0);
		action = ft_strjoin_f1(action, "\n");
		do_command(&s.a, &s.b, action);
		free(action);
	}
	print_stacks(&s);
	if (is_sort(s.a) && !s.b.size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_exit(&s, "", 0);
	return (0);
}
