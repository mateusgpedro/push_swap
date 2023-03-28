/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:23:37 by maguimar          #+#    #+#             */
/*   Updated: 2023/03/28 14:20:27 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_item	*first(t_stack *stack, int index)
{
	t_item	*item;
	int		i;

	item = stack->head;
	i = 0;
	while (i < index + 1)
	{
		item = item->next;
		i++;
	}
	return (item);
}
