/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:25:32 by maguimar          #+#    #+#             */
/*   Updated: 2023/04/06 15:19:30 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void start_algorithm(t_stack *stackA)
{
	t_stack *stackB;

	stackB = ft_calloc(1, sizeof(t_stack *));
	if (stackA->size == 2)
		two_elements(stackA); // Done
	else if (stackA->size == 3)
		three_elemtens(stackA); // Done
	else if (stackA->size == 5)
		five_elements(stackA, stackB);
    else if (stackA->size >= 500)
        a_hundred_plus_elements(stackA, stackB, 11);
    else
        a_hundred_plus_elements(stackA, stackB, 5);
}
