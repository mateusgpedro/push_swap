/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:43:46 by maguimar          #+#    #+#             */
/*   Updated: 2023/02/23 12:06:26 by maguimar         ###   ########.fr       */
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
	char **splitted;
	int *values;
	int i;
	int res;
	t_stack *stackA;

	i = 0;
	if (argc == 2)
		init_with_split(stackA, argv[1]);
	else if (argc >= 3)
	{
		while (i < argc - 1)
		{
			res = ft_atol(&values, argv[i + 1]);
			if (res == 0)
				free_stack();
			i++;
		}
		init_stack(values, stackA, i);
	}
	else
	{
		ft_printf("ERROR");
	}
}
