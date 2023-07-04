/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:35:16 by maguimar          #+#    #+#             */
/*   Updated: 2023/07/04 11:35:17 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	exit_algo(int *values, t_stack *stack)
{
	ft_printf("ERROR");
	free(values);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
