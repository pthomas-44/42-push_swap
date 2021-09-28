/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:55:54 by pthomas           #+#    #+#             */
/*   Updated: 2021/09/28 17:41:56 by pthomas          ###   ########lyon.fr   */
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

int	do_command(t_stack *a, t_stack *b, char *action)
{
	if (!action)
		return (0);
	else if (!ft_strcmp(action, "sa\n") || !ft_strcmp(action, "sb\n"))
		swap(a, b, action);
	else if (!ft_strcmp(action, "pa\n"))
		push(b, a);
	else if (!ft_strcmp(action, "pb\n"))
		push(a, b);
	else if (!ft_strcmp(action, "ra\n") || !ft_strcmp(action, "rb\n")
		|| !ft_strcmp(action, "rr\n"))
		rotate(a, b, action);
	else if (!ft_strcmp(action, "rra\n") || !ft_strcmp(action, "rrb\n")
		|| !ft_strcmp(action, "rrr\n"))
		reverse_rotate(a, b, action);
	else
		return (-1);
	return (0);
}

void	checker(t_structs *s)
{
	char	*action;
	int		ret;

	action = NULL;
	ret = 1;
	while (ret)
	{
		ret = get_next_line(0, &action);
		if (ret == -1)
			ft_exit(s, "error: malloc error\n", 0);
		if (!ret)
			break ;
		action = ft_strjoin_f1(action, "\n");
		if (do_command(&s->a, &s->b, action) == -1)
			ft_exit(s, "error: wrong instruction\n", 0);
		free(action);
	}
}

int	main(int ac, char **av)
{
	t_structs	s;

	init_stacks(&s, ac - 1);
	arg_checker(&s, ac, av);
	checker(&s);
	if (is_sort(s.a) && !s.b.size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_exit(&s, "", 0);
	return (0);
}
