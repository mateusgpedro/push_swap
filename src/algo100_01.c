/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo100_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:31:07 by maguimar          #+#    #+#             */
/*   Updated: 2023/03/27 18:00:16 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void find_lowest(t_stack *stackA, t_stack *stackB, int size)
{
	int *first;
	int *last;

	first = subdivide_first_elements(stackA);
	last = subdivide_last_elements(stackA);
	if (*first > *last)
		rotate_to_lowest(stackA, stackB, 1, *first);
	else
		rotate_to_lowest(stackA, stackB, -1, *last);
}

void rotate_to_lowest(t_stack *stackA, t_stack *stackB, int dir, int value) {
	t_item *item = stackA->head;
	if (dir = 1)
	{
		while (item->value != value)
			rotate(stackA);
	}
	else
	{
		while (item->value != value)
			reverse_rotate(stackA);
	}
	pb(stackA, stackB);
}

int subdivide_first_elements(t_stack *stack)
{
	t_item *item;
	int *tmp;
	int i;

	item = stack->head;
	*tmp = item->value;
	i = 0;
	while (i < 20)
	{
		item = item->next;
		if (item->value > tmp)
			*tmp = item->value;
		i++;
	}
	free(i);
	return (*tmp);
}

int subdivide_last_elements(t_stack *stack)
{
	t_item *item;
	int *tmp;
	int i;

	i = stack->size - 20;
	while (i < stack->size)
	{
		item = item->next;
		if (item->value > tmp)
			*tmp = item->value;
		i++;
	}
	free(i);
	return(*tmp);
}


// ALGORITHM for 5 elements +
// subdivide the stack A by 20
// verify what is the lower element of the first or last 20 elements
// rra or ra until the first element is the lowest one found
// pb to send the element
// after pb all the elements subdivide al the elements again by 30 and apply the same logic but this time apply pa rule
// to push the elements from stack B to stack A
