/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:43:46 by maguimar          #+#    #+#             */
/*   Updated: 2023/04/06 13:56:58 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	stack_a = ft_calloc(1, sizeof(t_stack));
	stack_a->size = 0;
	if (argc == 2)
		init_with_split(stack_a, argv[1]);
	else if (argc >= 3)
		init_with_args(stack_a, argv, argc - 1);
	else
		ft_printf("ERROR\n");
	start_algorithm(stack_a);
	free_stack(stack_a);
	return (0);
}
