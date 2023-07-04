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

void	three_elements(t_stack *stack_a)
{
	int	el_1;
	int	el_2;
	int	el_3;

	el_1 = first_val(stack_a, 0);
	el_2 = first_val(stack_a, 1);
	el_3 = first_val(stack_a, 2);
	if (el_1 > el_2 && el_2 < el_3 && el_3 > el_1)
		swap_item(stack_a, STACK_A);
	else if (el_1 > el_2 && el_2 < el_3 && el_3 < el_1)
		rotate(stack_a, 1, STACK_A);
	else if (el_1 < el_2 && el_2 > el_3 && el_3 < el_1)
		reverse_rotate(stack_a, 1, STACK_A);
	else if (el_1 > el_2 && el_2 > el_3 && el_3 < el_1)
	{
		swap_item(stack_a, STACK_A);
		reverse_rotate(stack_a, 1, STACK_A);
	}
	else if (el_1 < el_2 && el_2 > el_3 && el_3 > el_1)
	{
		swap_item(stack_a, STACK_A);
		rotate(stack_a, 1, STACK_A);
	}
}
