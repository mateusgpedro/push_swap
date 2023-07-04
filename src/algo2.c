/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:20:32 by maguimar          #+#    #+#             */
/*   Updated: 2023/07/04 11:37:07 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	two_elements(t_stack *stack_a)
{
	t_item	*item;

	item = stack_a->head;
	if (item->value > item->next->value)
		swap_item(stack_a, STACK_A);
}
