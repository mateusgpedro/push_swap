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

// returns 0 if min is cheapest or 1 if max i cheapest
void	operation_five(t_stack *stackA, t_stack *stackB)
{
	int	min;
	int	max;
	t_item *tmp;

	min = find_min_val(stackA);
	max = find_max_val(stackA);
	while (stackA->size != 3)
	{
		tmp = stackA->head;
		if (tmp->value == max || tmp->value == min)
			pb(stackA, stackB);
		else
			rotate(stackA, 1, STACK_A);
	}
}

void	five_elements(t_stack *stackA, t_stack * stackB)
{
	operation_five(stackA, stackB);
	three_elements(stackA);
	pa(stackA, stackB);
	pa(stackA, stackB);

	if (stackA->head->value == find_max_val(stackA))
		rotate(stackA, 1, STACK_A);
	else
	{
		swap_item(stackA, STACK_A);
		rotate(stackA, 1, STACK_A);
	}
}
