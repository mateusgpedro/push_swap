/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:25:32 by maguimar          #+#    #+#             */
/*   Updated: 2023/07/04 12:16:06 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_val(t_stack *stack)
{
	return (find_max(stack)->value);
}

int	find_min_val(t_stack *stack)
{
	return (find_min(stack)->value);
}

void	start_algorithm(t_stack *stack_a)
{
	t_stack	*stack_b;

	if (stack_a->size <= 1 || is_sorted(stack_a))
		return ;
	stack_b = ft_calloc(1, sizeof(t_stack));
	if (stack_a->size == 2)
		two_elements(stack_a);
	else if (stack_a->size == 3)
		three_elements(stack_a);
	else if (stack_a->size == 5)
		five_elements(stack_a, stack_b);
	else if (stack_a->size >= 500)
		a_hundred_plus_elements(stack_a, stack_b, 11);
	else if (stack_a->size >= 5)
		a_hundred_plus_elements(stack_a, stack_b, 5);
	else
		a_hundred_plus_elements(stack_a, stack_b, 2);
	free(stack_b);
}
