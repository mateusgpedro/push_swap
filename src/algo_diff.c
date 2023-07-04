/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_diff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:34:05 by maguimar          #+#    #+#             */
/*   Updated: 2023/07/04 12:04:40 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	define_hold_position(t_stack *stack, t_ordered_stack *orderedStack)
{
	orderedStack->hold_first = find_first(stack, orderedStack);
	orderedStack->hold_second = find_last(stack, orderedStack);
	if (orderedStack->hold_first == -1 && orderedStack->hold_second == -1)
		return (-1);
	if (orderedStack->hold_first <= (stack->size - orderedStack->hold_second)
		&& orderedStack->hold_first != -1)
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

void	push_to_other_stack(t_stack *stack_a,
			t_stack *stack_b, t_ordered_stack *orderedStack)
{
	while (stack_a->size > 0)
	{
		if (orderedStack->current_chunk < orderedStack->chunks)
			put_hold_top(stack_a, stack_b, orderedStack, 0);
		else if (orderedStack->current_chunk == orderedStack->chunks)
			put_hold_top(stack_a, stack_b, orderedStack, 1);
		orderedStack->current_chunk++;
	}
}
