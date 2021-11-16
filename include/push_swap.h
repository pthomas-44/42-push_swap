/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:30:45 by pthomas           #+#    #+#             */
/*   Updated: 2021/11/16 15:04:00 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*** ~~ LIBS ~~ ***/

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

/*** ~~ STRUCTURES ~~ ***/

// ~~ CHUNK

typedef struct s_chunk
{
	unsigned int	min;
	unsigned int	max;
	int				mid;
}					t_chunk;

// ~~ STACKS

typedef struct s_stack
{
	int				*stk;
	unsigned int	size;
}					t_stack;

// ~~ CONTROL STRUCT

typedef struct s_structs
{
	t_stack			a;
	t_stack			b;
	unsigned int	size;
}					t_structs;

/*** ~~ PROTOTYPES ~~ ***/

// ~~ main.c
void				sort(t_structs *s);
void				ft_exit(t_structs *s, char *errormsg, int status);
// ~~ init.c
void				arg_checker(t_structs *s, int ac, char **av);
void				init_stacks(t_structs *s, int size);
int					is_overflow(const char *str);
int					is_sort(t_stack a);
void				indexer(t_structs *s, t_stack *a);
// ~~ operations.c
void				do_op(t_stack *a, t_stack *b, char *action);
void				swap(t_stack *a, t_stack *b, char *action);
void				push(t_stack *from, t_stack *to);
void				rotate(t_stack *a, t_stack *b, char *action);
void				reverse_rotate(t_stack *a, t_stack *b, char *action);
// ~~ sort.c
void				sort_three(t_structs *s);
void				sort_five(t_structs *s);
void				sort_hundred(t_structs *s, int chunk_size);
void				sort_thousands(t_structs *s);
// ~~ hundred.c
void				gtt_closest_hundred(t_structs *s, int maxchunk);
int					get_previous(t_stack *b, int nb);
// ~~ thousand.c
t_chunk				init_chunk_one(t_structs *s, t_chunk chunk);
t_chunk				init_chunk_two(t_structs *s, t_chunk chunk);
t_chunk				init_chunk_three(t_structs *s, t_chunk chunk);
void				push_chunk(t_structs *s, t_chunk chunk, char stack);
// ~~ utils.c
int					get_highest(t_stack *a);
int					get_lowest(t_stack *a);
void				get_to_top(t_structs *s, unsigned int index,
						unsigned int size, char stack);
int					get_closest(t_stack *a, int maxchunk, int minchunk);
char				*get_action(t_stack *a, t_stack *b,
						unsigned int a_index, unsigned int b_index);

#endif
