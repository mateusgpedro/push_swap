/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:25:32 by maguimar          #+#    #+#             */
/*   Updated: 2023/03/28 13:03:19 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void start_algorithm(t_stack *stackA)
{
	t_stack *stackB;
	if (stackA->size == 2)
		two_elemtens(stackA);
	else if (stackA->size == 3)
		three_elemtens(stackA, stackB);
}
