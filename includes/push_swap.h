/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:04:59 by maguimar          #+#    #+#             */
/*   Updated: 2023/07/04 12:16:06 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "ft_printf.h"

# define STACK_A 0
# define STACK_B 1

typedef struct s_item
{
	int				value;
	struct s_item	*next;
}	t_item;

typedef struct s_stack
{
	int		size;
	t_item	*head;
}	t_stack;

typedef struct s_ordered_stack
{
	int	size;
	int	*order;
	int	last_chunk_size;
	int	chunk_size;
	int	hold_first;
	int	hold_second;
	int	chunks;
	int	current_chunk;
}	t_ordered_stack;

/* Stack Initialization (src/stack/stack_init.c) */
void	init_with_split(t_stack *stack, char *str);
void	init_with_args(t_stack *stack, char **strs, int size);
void	init_stack(int *values, t_stack *stack, int size);
void	push(t_stack *stack, t_item *item, int increase_size);
t_item	*create_new_item(int val);

/* Stack Operations (src/stack/stack_operations.c) */
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	swap_item(t_stack *stack, int what_stack);
void	rotate(t_stack *stack, int times, int what_stack);
void	reverse_rotate(t_stack *stack, int times, int what_stack);

/* Stack Utilities (src/stack/stack_utils.c) */
int		first_val(t_stack *stack, int index);
int		find_max_val(t_stack *stack);
int		find_min_val(t_stack *stack);
t_item	*find_max(t_stack *stack);
t_item	*find_min(t_stack *stack);
int		find_index(t_stack *stack, t_item *item);
int		is_sorted(t_stack *stack);

/* Memory & Error Management (src/stack/stack_free.c) */
void	free_strs(char **strs);
void	free_stack(t_stack *stack);
void	free_ordered(t_ordered_stack *ordered);
void	exit_algo(int *values, t_stack *stack);

/* Sorting Algorithms (src/sorting/) */
void	start_algorithm(t_stack *stack_a);
void	two_elements(t_stack *stack_a);
void	three_elements(t_stack *stack_a);
void	five_elements(t_stack *stack_a, t_stack *stack_b);
void	a_hundred_plus_elements(t_stack *stack_a, t_stack *stack_b, int chunks);

/* Chunk Sorting Helpers (src/sorting/) */
void	initialize_ordered_stack(t_stack *stack_a,
			t_ordered_stack *ordered_stack);
void	ft_sort_int_tab(t_ordered_stack *ordered_stack);
int		find_first(t_stack *stack, t_ordered_stack *ordered_stack);
int		find_last(t_stack *stack, t_ordered_stack *ordered_stack);
int		define_hold_position(t_stack *stack,
			t_ordered_stack *ordered_stack);
void	put_hold_top(t_stack *stack_a, t_stack *stack_b,
			t_ordered_stack *ordered_stack, int is_last);
void	push_to_other_stack(t_stack *stack_a, t_stack *stack_b,
			t_ordered_stack *ordered_stack);
void	push_back_all(t_stack *stack_a, t_stack *stack_b);
int		is_in_chunk(t_item *item, t_ordered_stack *ordered_stack);
int		is_in_subchunk(t_item *item, t_ordered_stack *ordered_stack);

/* Parsing & General Utilities (src/utils/parse_utils.c) */
void	swap(int *a, int *b);
int		ft_atol(const char *str, int *value);
int		check_duplicates(int *values, int size);

#endif
