/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:20:32 by maguimar          #+#    #+#             */
/*   Updated: 2023/04/13 15:22:37 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	two_elements(t_stack *stackA)
{
	t_item *item;

	item = stackA->head;
	if (item->value > item->next->value)
		swap_item(stackA);
}
