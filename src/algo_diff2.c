/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_diff2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:34:51 by maguimar          #+#    #+#             */
/*   Updated: 2023/07/04 11:45:17 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_hold_top(t_stack *stack_a, t_stack *stack_b,
t_ordered_stack *ordered_stack, int isLast)
{
	int	is_hold_top;
	int	i;
	int	chunk_size;

	i = 0;
	if (isLast)
		chunk_size = ordered_stack->last_chunk_size;
	else
		chunk_size = ordered_stack->chunk_size;
	while (i < chunk_size)
	{
		is_hold_top = define_hold_position(stack_a, ordered_stack);
		if (is_hold_top == 1 && stack_a->size != 1)
			rotate(stack_a, ordered_stack->hold_first, STACK_A);
		else if (is_hold_top == 0 && stack_a->size != 1)
			reverse_rotate(stack_a,
				stack_a->size - ordered_stack->hold_second, STACK_A);
		pb(stack_a, stack_b);
		if (is_in_subchunk(stack_b->head, ordered_stack) && stack_b->size > 1)
			rotate(stack_b, 1, STACK_B);
		i++;
	}
}

void	push_back_all(t_stack *stack_a, t_stack *stack_b)
{
	int	pos;

	while (stack_b->size > 0)
	{
		pos = find_index(stack_b, find_max(stack_b));
		if (stack_b->size == 1)
		{
			pa(stack_a, stack_b);
			continue ;
		}
		else if (pos < stack_b->size / 2)
			rotate(stack_b, pos, STACK_B);
		else
			reverse_rotate(stack_b, stack_b->size - pos, STACK_B);
		pa(stack_a, stack_b);
	}
}

int	is_in_chunk(t_item *item, t_ordered_stack *ordered_stack)
{
	int	i;
	int	chunk_size;

	i = 0;
	if (ordered_stack->current_chunk == ordered_stack->chunks)
		chunk_size = ordered_stack->last_chunk_size;
	else
		chunk_size = ordered_stack->chunk_size;
	while (i < chunk_size)
	{
		if (item->value == ordered_stack->order[i
				+ (ordered_stack->chunk_size
					* ordered_stack->current_chunk - 1)])
			return (1);
		i++;
	}
	return (0);
}

int	is_in_subchunk(t_item *item, t_ordered_stack *ordered_stack)
{
	int	i;
	int	chunk_size;

	i = 0;
	if (ordered_stack->current_chunk == ordered_stack->chunks)
		chunk_size = ordered_stack->last_chunk_size;
	else
		chunk_size = ordered_stack->chunk_size;
	while (i < chunk_size / 2)
	{
		if (item->value == ordered_stack->order[i
				+ (ordered_stack->chunk_size
					* ordered_stack->current_chunk - 1)])
			return (1);
		i++;
	}
	return (0);
}
