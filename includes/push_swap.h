/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:04:59 by maguimar          #+#    #+#             */
/*   Updated: 2023/04/06 15:18:50 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "ft_printf.h"

typedef struct s_item
{
	int value;
	struct s_item *next;
}	t_item;

typedef struct s_stack
{
	int size;
	t_item *head;
}				t_stack;

typedef struct s_ordered_stack
{
	int	size;
	int	*order;
    int last_chunk_size;
    int chunk_size;
	int hold_first;
	int hold_second;

}				t_ordered_stack;

//PROGRAM
void	init_with_split(t_stack *stack, char *str);
void	init_with_args(t_stack *stack, char **strs, int size);
void	push(t_stack *stack, t_item *item);
void	swap(int *a, int *b);
void	init_stack(int *values, t_stack *stack, int size);
t_item	*create_new_item(int val);
void	free_strs(char **strs);
int		ft_atol(const char *str, int *value);
void	rotate(t_stack *stack, int times);
void	reverse_rotate(t_stack *stack, int times);
void	pa(t_stack *stackA, t_stack *stackB);
void	pb(t_stack *stackA, t_stack *stackB);
void	swap_item(t_stack *stack);
void	start_algorithm(t_stack *stackA);
void	two_elements(t_stack *stackA);
void	three_elemtens(t_stack *stackA);
void	five_elements(t_stack *stackA, t_stack * stackB);
t_item	*first(t_stack *stack, int index);
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);
void    initialize_ordered_stack(t_stack *stackA, t_ordered_stack *orderedStack);
void	ft_sort_int_tab(t_ordered_stack *orderedStack);
int	    find_first(t_stack *stack, t_ordered_stack *ordered_stack, int chunk_size, int chunk);
int     find_last(t_stack *stack, t_ordered_stack *ordered_stack, int chunk_size, int chunk);
int     define_hold_position(t_stack *stack, t_ordered_stack *orderedStack, int chunk, int chunks);
void    put_hold_top(t_stack *stackA, t_stack *stackB, t_ordered_stack *orderedStack, int chunk_size, int chunks);
void	push_to_other_stack(t_stack *stackA, t_stack *stackB, t_ordered_stack *orderedStack, int chunks);
void    push_back_all(t_stack *stackA, t_stack *stackB);
void    a_hundred_plus_elements(t_stack *stackA, t_stack *stackB, int chunks);

// TESTING
void print_stack(t_stack *stack);

#endif
