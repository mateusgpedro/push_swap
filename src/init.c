/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:48:38 by maguimar          #+#    #+#             */
/*   Updated: 2023/02/23 14:46:42 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_with_split(t_stack *stack, char *str)
{
	char **splitted;
	int *values;
	int i;
	int res;

	i = 0;
	splitted = ft_split(str, ' ');
	while(splitted[i] != NULL)
	{
		res = ft_atol(&values[i], splitted[i]);
		if (res == 0)
		{
			free_strs(splitted);
			return ;
		}
		i++;
	}
	int j = 0;
	while(values[j])
	{
		ft_printf("%d\n", values[j]);
	}
	init_stack(values, stack, i);
}

void	init_with_args(t_stack *stack, char **strs, int size)
{
	int	i;
	int	res;
	int *values;

	i = 0;
	values = malloc(sizeof(int) * size);
	while (i < size)
	{
		res = ft_atol(&values[i], strs[i + 1]);
				ft_printf("res=%d\n", res);
		if (res == 0)
			free_strs(strs);
		i++;
	}
	int j = 0;
	while(j < size)
	{
		ft_printf("%d\n", values[j]);
		j++;
	}
	init_stack(values, stack, i);
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
		i++;
	}
}
