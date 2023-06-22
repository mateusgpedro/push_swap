/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:31:30 by maguimar          #+#    #+#             */
/*   Updated: 2023/04/06 15:05:53 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_elemtens(t_stack *stackA)
{
	int el_1;
	int el_2;
	int el_3;

	el_1 = first(stackA, 0)->value;
	el_2 = first(stackA, 1)->value;
	el_3 = first(stackA, 2)->value;
	if (el_1 > el_2 && el_2 < el_3 && el_3 > el_1)
		swap_item(stackA);
	else if (el_1 > el_2 && el_2 < el_3 && el_3 < el_1)
		rotate(stackA, 1);
	else if (el_1 < el_2 && el_2 > el_3 && el_3 < el_1)
		reverse_rotate(stackA, 1);
	else if (el_1 > el_2 && el_2 > el_3 && el_3 < el_1)
	{
		swap_item(stackA);
		reverse_rotate(stackA, 1);
	}
	else if (el_1 < el_2 && el_2 > el_3 && el_3 < el_1)
	{
		swap_item(stackA);
		rotate(stackA, 1);
	}
}
