/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:43:46 by maguimar          #+#    #+#             */
/*   Updated: 2023/03/03 15:04:08 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack *stack, t_item *item)
{
	if (stack->size == 0)
	{
		stack->head = item;
		item->next = NULL;
		stack->size++;
	}
	else
	{
		item->next = stack->head;
		stack->head = item;
		stack->size++;
	}
}

t_item	*create_new_item(int val)
{
	t_item *item;

	item = malloc(sizeof(t_item));
	item->next = NULL;
	item->value = val;
	return (item);
}

int	main(int argc, char *argv[])
{
	t_stack *stackA;

	stackA = ft_calloc(1, sizeof(t_stack *));
	if (argc == 2)
		init_with_split(stackA, argv[1]);
	else if (argc >= 3)
		init_with_args(stackA, argv, argc - 1);
	else
		ft_printf("ERROR");
	// ft_printf("Ola")
}
