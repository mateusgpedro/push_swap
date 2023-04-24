/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:23:37 by maguimar          #+#    #+#             */
/*   Updated: 2023/03/28 16:28:39 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_item	*first(t_stack *stack, int index)
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
	return (item);
}

void print_stack(t_stack *stack)
{
	t_item * item;
	int i;

	i = 0;
	item = stack->head;
	while (i < stack->size && item)
	{
		ft_printf("%d\n", item->value);
		item = item->next;
	}
}

int find_max(t_stack *stack)
{
	t_item *tmp;
	t_item *value;

	tmp = stack->head;
	value = tmp;
	while (tmp->next)
	{
		if (tmp->next->value > value->value)
			value = tmp->next;
		tmp = tmp->next;
	}
	return value->value;
}

int find_min(t_stack *stack)
{
	t_item *tmp;
	t_item *value;

	tmp = stack->head;
	value = stack->head;
	while (tmp->next)
	{
		if (tmp->next->value < value->value && tmp->next != NULL)
			value = tmp->next;
		tmp = tmp->next;
	}
	return value->value;
}

int find_index(t_stack *stack, t_item *item)
{
	t_item *tmp;
	int	i;

	tmp = stack->head;
	i = 0;
	while (tmp->next)
	{
		if (tmp->next == item)
			break;
		i++;
		tmp = tmp->next;
	}
	return i;
}
