/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:44:11 by maguimar          #+#    #+#             */
/*   Updated: 2023/04/13 15:49:44 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	operation_five(t_stack *stack_a, t_stack *stack_b)
{
	int		min;
	int		max;
	t_item	*tmp;

	min = find_min_val(stack_a);
	max = find_max_val(stack_a);
	while (stack_a->size != 3)
	{
		tmp = stack_a->head;
		if (tmp->value == max || tmp->value == min)
			pb(stack_a, stack_b);
		else
			rotate(stack_a, 1, STACK_A);
	}
}

void	five_elements(t_stack *stack_a, t_stack *stack_b)
{
	operation_five(stack_a, stack_b);
	three_elements(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	if (stack_a->head->value == find_max_val(stack_a))
		rotate(stack_a, 1, STACK_A);
	else
	{
		swap_item(stack_a, STACK_A);
		rotate(stack_a, 1, STACK_A);
	}
}
