/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:31:30 by maguimar          #+#    #+#             */
/*   Updated: 2023/07/04 12:16:06 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_elements(t_stack *stack_a)
{
	t_item	*item;

	item = stack_a->head;
	if (item->value > item->next->value)
		swap_item(stack_a, STACK_A);
}

void	three_elements(t_stack *stack_a)
{
	int	el_1;
	int	el_2;
	int	el_3;

	el_1 = first_val(stack_a, 0);
	el_2 = first_val(stack_a, 1);
	el_3 = first_val(stack_a, 2);
	if (el_1 > el_2 && el_2 < el_3 && el_3 > el_1)
		swap_item(stack_a, STACK_A);
	else if (el_1 > el_2 && el_2 < el_3 && el_3 < el_1)
		rotate(stack_a, 1, STACK_A);
	else if (el_1 < el_2 && el_2 > el_3 && el_3 < el_1)
		reverse_rotate(stack_a, 1, STACK_A);
	else if (el_1 > el_2 && el_2 > el_3 && el_3 < el_1)
	{
		swap_item(stack_a, STACK_A);
		reverse_rotate(stack_a, 1, STACK_A);
	}
	else if (el_1 < el_2 && el_2 > el_3 && el_3 > el_1)
	{
		swap_item(stack_a, STACK_A);
		rotate(stack_a, 1, STACK_A);
	}
}

static void	operation_five(t_stack *stack_a, t_stack *stack_b)
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
