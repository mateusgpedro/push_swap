/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:16:14 by maguimar          #+#    #+#             */
/*   Updated: 2023/04/06 17:13:36 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_stack *stack, int times, int what_stack)
{
	t_item	*tmp;
    int i;

    i = 0;
    while (i < times)
    {
        tmp = stack->head;
        while (tmp->next->next)
            tmp = tmp->next;
        push(stack, tmp->next, 0);
        tmp->next = NULL;
		if (what_stack == STACK_A)
			ft_printf("rra\n");
		else
			ft_printf("rrb\n");
        i++;
    }
}

void	rotate(t_stack *stack, int times, int what_stack)
{
	t_item	*tmp;
	t_item	*item;
    int i;

    i = 0;
    while (i < times)
    {
        tmp = stack->head;
        item = stack->head;
        stack->head = stack->head->next;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = item;
        item->next = NULL;
		if (what_stack == STACK_A)
			ft_printf("ra\n");
		else
			ft_printf("rb\n");
        i++;
    }

}

void pa(t_stack *stackA, t_stack *stackB)
{
	t_item *item;

	if (stackB->size <= 0)
		return;
	item = stackB->head;
	stackB->head = stackB->head->next;
	stackB->size--;
	push(stackA, item, 1);
	ft_printf("pa\n");
}

void pb(t_stack *stackA, t_stack *stackB)
{
	t_item *item;

		if (stackA->size <= 0)
			return;
		item = stackA->head;
		stackA->head = stackA->head->next;
		stackA->size--;
		push(stackB, item, 1);
		ft_printf("pb\n");
}

void swap_item(t_stack *stack, int what_stack)
{
	swap(&stack->head->value, &stack->head->next->value);
	if (what_stack == STACK_A)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}
