/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:48:38 by maguimar          #+#    #+#             */
/*   Updated: 2023/02/23 12:06:18 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void init_with_split(t_stack *stack, char *str)
{
	char **splitted;
	int *value;
	int i;
	int res;

	i = 0;
	splitted = ft_split(str, ' ');
	while(splitted[i] != NULL)
	{
		res = ft_atol(&value, splitted[i]);
		if (res == 0)
		{
			free_strs(splitted);
			return ;
		}
		i++;
	}
	init_stack(stackA);
}

void init_with_args(t_stack *stack, char **strs)
{

}

void init_stack(int *values, t_stack *stack, int size)
{
	int i;
	t_item *item;

	i = 0;
	while (i < size)
	{
		item = create_new_item(values[i]);
		push(stack, item);
	}
}
