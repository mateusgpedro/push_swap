/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:16:14 by maguimar          #+#    #+#             */
/*   Updated: 2023/02/09 17:06:31 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_item	*tmp;

	tmp = stack->head;
	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	push(stack, tmp->next);
	tmp->next = NULL;
}

void	rotate(t_stack *stack)
{
	t_item	*tmp;
	t_item	*item;

	tmp = stack->head;
	item = stack->head;
	stack->head = stack->head->next;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = item;
	item->next = NULL;
}

void pa(t_stack *stackA, t_stack *stackB)
{
	t_item *item;

	if (stackB->size <= 0)
		return;
	item = stackB->head;
	stackB->head = stackB->head->next;
	push(stackA, item);
}

void pb(t_stack *stackA, t_stack *stackB)
{
	t_item *item;

		if (stackA->size <= 0)
			return;
		item = stackA->head;
		stackA->head = stackA->head->next;
		push(stackB, item);
}

void swap_item(t_stack *stack)
{
	swap(&stack->head->value, &stack->head->next->value);
}
