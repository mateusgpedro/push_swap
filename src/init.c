/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:48:38 by maguimar          #+#    #+#             */
/*   Updated: 2023/04/06 13:57:54 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_with_split(t_stack *stack, char *str)
{
	char	**splitted;
	int		*values;
	int		i;

	splitted = ft_split(str, ' ');
	i = 0;
	while (splitted[i] != NULL)
		i++;
	values = malloc(sizeof(int) * i);
	i = 0;
	while (splitted[i] != NULL)
	{
		if (ft_atol(splitted[i + 1], &values[i]) == 0)
			exit_algo(values, stack);
		i++;
	}
	if (check_duplicates(values) == 0)
		exit_algo(values, stack);
	init_stack(values, stack, i);
	free_strs(splitted);
}

void	init_with_args(t_stack *stack, char **strs, int size)
{
	int	*values;
	int	i;

	i = 0;
	values = malloc(sizeof(int) * size);
	while (strs[i + 1] != NULL)
	{
		if (ft_atol(strs[i + 1], &values[i]) == 0)
			exit_algo(values, stack);
		i++;
	}
	if (check_duplicates(values) == 0)
		exit_algo(values, stack);
	init_stack(values, stack, i);
}

void	init_stack(int *values, t_stack *stack, int size)
{
	t_item	*item;

	while (0 < size)
	{
		item = create_new_item(values[size - 1]);
		push(stack, item, 1);
		size--;
	}
	free(values);
}

void	push(t_stack *stack, t_item *item, int increaseSize)
{
	if (stack->size == 0)
	{
		stack->head = item;
		item->next = NULL;
	}
	else
	{
		item->next = stack->head;
		stack->head = item;
	}
	if (increaseSize == 1)
		stack->size++;
}

t_item	*create_new_item(int val)
{
	t_item	*item;

	item = malloc(sizeof(t_item));
	item->next = NULL;
	item->value = val;
	return (item);
}
