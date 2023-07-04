/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:07:44 by maguimar          #+#    #+#             */
/*   Updated: 2023/02/23 13:04:22 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	free_stack(t_stack *stack)
{
	t_item	*item;

	while (stack->head)
	{
		item = stack->head;
		stack->head = stack->head->next;
		free(item);
		stack->size--;
	}
	free(stack);
}

void	free_ordered(t_ordered_stack *ordered)
{
	while (ordered->size > 0)
	{
		ordered->order[ordered->size - 1] = '\0';
		ordered->size--;
	}
	free(ordered->order);
	free(ordered);
}
