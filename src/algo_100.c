/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:35:01 by maguimar          #+#    #+#             */
/*   Updated: 2023/07/04 11:35:04 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
