/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:30:45 by pthomas           #+#    #+#             */
/*   Updated: 2021/09/16 19:27:09 by pthomas          ###   ########lyon.fr   */
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
void				print_stacks(t_structs *s);
// ~~ init.c
void				init_stacks(t_structs *s, int size);
void				arg_checker(t_structs *s, int ac, char **av);
void				indexer(t_structs *s, t_stack *a);
int					is_sort(t_stack a);
// ~~ operations.c
void				swap(t_stack *a, t_stack *b, char *action);
void				push(t_stack *from, t_stack *to, char *action);
void				rotate(t_stack *a, t_stack *b, char *action);
void				reverse_rotate(t_stack *a, t_stack *b, char *action);
// ~~ sort.c
void				sort(t_structs *s);
void				sort_three(t_stack *a);
void				sort_five(t_structs *s);
void				sort_hundred(t_structs *s);

// ~~ utils.c
void				get_to_top(t_stack *a, unsigned int index, char stack);
int					get_highest(t_stack *a);
int					get_lowest(t_stack *a);
int					get_previous(t_stack *b, int nb);
int					get_closest(t_stack *a, int maxchunk);

#endif