/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:35:01 by maguimar          #+#    #+#             */
/*   Updated: 2023/07/04 12:16:06 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_hundred_plus_elements(t_stack *stack_a, t_stack *stack_b, int chunks)
{
	t_ordered_stack	*ordered_stack;

	ordered_stack = ft_calloc(1, sizeof(t_ordered_stack));
	initialize_ordered_stack(stack_a, ordered_stack);
	ft_sort_int_tab(ordered_stack);
	ordered_stack->chunk_size = stack_a->size / chunks;
	ordered_stack->last_chunk_size = stack_a->size % chunks;
	if (stack_a->size % ordered_stack->chunk_size != 0)
		chunks++;
	ordered_stack->chunks = chunks;
	ordered_stack->current_chunk = 0;
	push_to_other_stack(stack_a, stack_b, ordered_stack);
	push_back_all(stack_a, stack_b);
	free_ordered(ordered_stack);
}

void	initialize_ordered_stack(t_stack *stack_a,
			t_ordered_stack *ordered_stack)
{
	t_item	*item;
	int		i;

	i = 0;
	item = stack_a->head;
	ordered_stack->order = malloc(sizeof(int) * stack_a->size);
	ordered_stack->size = 0;
	while (item)
	{
		ordered_stack->order[i] = item->value;
		ordered_stack->size++;
		i++;
		item = item->next;
	}
}

void	ft_sort_int_tab(t_ordered_stack *ordered_stack)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < ordered_stack->size)
	{
		j = 0;
		while (j < ordered_stack->size - 1)
		{
			if (ordered_stack->order[j] > ordered_stack->order[j + 1])
			{
				temp = ordered_stack->order[j];
				ordered_stack->order[j] = ordered_stack->order[j + 1];
				ordered_stack->order[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	push_to_other_stack(t_stack *stack_a,
			t_stack *stack_b, t_ordered_stack *ordered_stack)
{
	while (stack_a->size > 0)
	{
		if (ordered_stack->current_chunk < ordered_stack->chunks)
			put_hold_top(stack_a, stack_b, ordered_stack, 0);
		else if (ordered_stack->current_chunk == ordered_stack->chunks)
			put_hold_top(stack_a, stack_b, ordered_stack, 1);
		ordered_stack->current_chunk++;
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
