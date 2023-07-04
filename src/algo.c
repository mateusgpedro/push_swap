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

void	start_algorithm(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = ft_calloc(1, sizeof(t_stack));
	if (stack_a->size == 2)
		two_elements(stack_a);
	else if (stack_a->size == 3)
		three_elements(stack_a);
	else if (stack_a->size == 5)
		five_elements(stack_a, stack_b);
	else if (stack_a->size >= 500)
		a_hundred_plus_elements(stack_a, stack_b, 11);
	else
		a_hundred_plus_elements(stack_a, stack_b, 5);
	free(stack_b);
}
