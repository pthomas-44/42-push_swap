/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:30:45 by pthomas           #+#    #+#             */
/*   Updated: 2021/09/10 14:02:33 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*** ~~ LIBS ~~ ***/

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/includes/libft.h"
# include <stdio.h>

/*** ~~ STRUCTURES ~~ ***/

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}					t_stack;

typedef struct s_structs
{
	t_stack			*a;
	t_stack			*b;
	unsigned int	size;
}					t_structs;

/*** ~~ PROTOTYPES ~~ ***/

void				print_stacks(t_structs *s);
int					is_sort(t_stack *stack);
// ~~ ft_exit.c
void				stk_clear(t_structs *s);
void				ft_exit(t_structs *s, char *errormsg, int status);
// ~~ init.c
void				init_stacks(t_structs *s, int size);
t_stack				*stk_get_last(t_stack *a);
void				stk_add_new(t_structs *s, int nb);
void				arg_checker(t_structs *s, int ac, char **av);
// ~~ operations.c
void				swap(t_stack **stack);
void				push(t_stack **from, t_stack **to);
void				rotate(t_stack **a, t_stack **b);
void				reverse_rotate(t_stack **a, t_stack **b);

#endif