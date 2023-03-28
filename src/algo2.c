/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:25:02 by maguimar          #+#    #+#             */
/*   Updated: 2023/03/28 12:58:59 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	two_elemtens(t_stack *stackA)
{
	t_item *item;

	item = stackA->head;
	if (item->next->value > item->value)
		swap_item(stackA);
}
