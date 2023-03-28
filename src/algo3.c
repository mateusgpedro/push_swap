/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:31:30 by maguimar          #+#    #+#             */
/*   Updated: 2023/03/28 14:43:59 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_elemtens(t_stack *stackA, t_stack *stackB)
{
	t_item *item;

	item = stackA->head;
	if (first(stackA, 0)->value > first(stackA, 1)->value
		&& first(stackA, 0)->value < first(stackA, 2)->value)
		swap_item(stackA);
	else if (first(stackA, 0)->value > first(stackA, 1)->value
		&& first(stackA, 0)->value > first(stackA, 2)->value)
		rotate(stackA);
	else if (first(stackA, 0)->value < first(stackA, 1)->value
		&& first(stackA, 0)->value > first(stackA, 2)->value)
		reverse_rotate(stackA);
	else if (first(stackA, 0)->value > first(stackA, 1)->value
		&& first(stackA, 1)->value > first(stackA, 2)->value)
	{
		swap_item(stackA);
		reverse_rotate(stackA);
	}
	else
	{
		swap_item(stackA);
		rotate(stackA);
	}
}
