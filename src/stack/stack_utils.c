/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:23:37 by maguimar          #+#    #+#             */
/*   Updated: 2023/07/04 12:16:06 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_val(t_stack *stack, int index)
{
	t_item	*item;
	int		i;

	item = stack->head;
	i = 0;
	while (i < index)
	{
		item = item->next;
		i++;
	}
	return (item->value);
}

t_item	*find_max(t_stack *stack)
{
	t_item	*tmp;
	t_item	*value;

	tmp = stack->head;
	value = tmp;
	while (tmp->next)
	{
		if (tmp->next->value > value->value)
			value = tmp->next;
		tmp = tmp->next;
	}
	return (value);
}

t_item	*find_min(t_stack *stack)
{
	t_item	*tmp;
	t_item	*value;

	tmp = stack->head;
	value = stack->head;
	while (tmp->next)
	{
		if (tmp->next->value < value->value && tmp->next != NULL)
			value = tmp->next;
		tmp = tmp->next;
	}
	return (value);
}

int	find_index(t_stack *stack, t_item *item)
{
	t_item	*tmp;
	int		i;

	tmp = stack->head;
	i = 0;
	while (tmp->next)
	{
		if (tmp->value == item->value)
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	is_sorted(t_stack *stack)
{
	t_item	*tmp;

	if (!stack || !stack->head)
		return (1);
	tmp = stack->head;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
