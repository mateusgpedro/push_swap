/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:43:46 by maguimar          #+#    #+#             */
/*   Updated: 2023/02/07 15:35:27 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, t_item *item)
{
	if (stack->size == 0)
	{
		stack->head = item;
		item->next = NULL;
		stack->size++;
	}
	else
	{
		item->next = stack->head;
		stack->head = item;
		stack->size++;
	}
}

int	main(int argc, char *argv[])
{

}
