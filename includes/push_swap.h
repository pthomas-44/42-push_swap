/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:30:45 by pthomas           #+#    #+#             */
/*   Updated: 2021/09/28 16:51:28 by pthomas          ###   ########lyon.fr   */
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
	int				*stk;
	unsigned int	size;
}					t_stack;

typedef struct s_structs
{
	t_stack			a;
	t_stack			b;
	unsigned int	size;
}					t_structs;

/*** ~~ PROTOTYPES ~~ ***/

// ~~ main.c
void				ft_exit(t_structs *s, char *errormsg, int status);
void				sort(t_structs *s);
void				print_stacks(t_structs *s);
// ~~ init.c
void				init_stacks(t_structs *s, int size);
void				arg_checker(t_structs *s, int ac, char **av);
void				indexer(t_structs *s, t_stack *a);
int					is_sort(t_stack a);
// ~~ operations.c
void				do_op(t_stack *a, t_stack *b, char *action);
void				swap(t_stack *a, t_stack *b, char *action);
void				push(t_stack *from, t_stack *to);
void				rotate(t_stack *a, t_stack *b, char *action);
void				reverse_rotate(t_stack *a, t_stack *b, char *action);
// ~~ sort.c
char				*get_action(t_stack *a, t_stack *b, unsigned int a_index, unsigned int b_index);
void				sort_three(t_structs *a);
void				sort_five(t_structs *s);
void				sort_hundred(t_structs *s, int chunk_size);
// ~~ utils.c
void				get_to_top(t_structs *s, unsigned int index, unsigned int size, char stack);
int					get_highest(t_stack *a);
int					get_lowest(t_stack *a);
int					get_previous(t_stack *b, int nb);
int					get_closest(t_stack *a, int maxchunk);

#endif