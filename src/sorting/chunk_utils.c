/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:34:51 by maguimar          #+#    #+#             */
/*   Updated: 2023/07/04 12:16:06 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	define_hold_position(t_stack *stack, t_ordered_stack *ordered_stack)
{
	ordered_stack->hold_first = find_first(stack, ordered_stack);
	ordered_stack->hold_second = find_last(stack, ordered_stack);
	if (ordered_stack->hold_first == -1 && ordered_stack->hold_second == -1)
		return (-1);
	if (ordered_stack->hold_first <= (stack->size - ordered_stack->hold_second)
		&& ordered_stack->hold_first != -1)
		return (1);
	return (0);
}

int	find_first(t_stack *stack, t_ordered_stack *ordered_stack)
{
	t_item	*item;
	int		is_item_in_chunk;

	item = stack->head;
	while (item && find_index(stack, item) < stack->size / 2)
	{
		is_item_in_chunk = is_in_chunk(item, ordered_stack);
		if (is_item_in_chunk)
			return (find_index(stack, item));
		item = item->next;
	}
	return (-1);
}

int	find_last(t_stack *stack, t_ordered_stack *ordered_stack)
{
	t_item	*item;
	int		tmp;
	int		i;
	int		is_item_in_chunk;

	item = stack->head;
	tmp = 0;
	i = 0;
	while (item)
	{
		is_item_in_chunk = is_in_chunk(item, ordered_stack);
		if (is_item_in_chunk)
			tmp = i;
		i++;
		item = item->next;
	}
	if (tmp > 0)
		return (tmp);
	else
		return (-1);
}

void	put_hold_top(t_stack *stack_a, t_stack *stack_b,
			t_ordered_stack *ordered_stack, int is_last)
{
	int	is_hold_top;
	int	i;
	int	chunk_size;

	i = 0;
	if (is_last)
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
