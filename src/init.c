/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:48:38 by maguimar          #+#    #+#             */
/*   Updated: 2023/03/02 18:10:34 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	verify_input(char **strs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(strs[i] != NULL)
	{

	}
}

void	init_with_split(t_stack *stack, char *str)
{
	// TODO: Initialize stack with splitted string
	char **splitted;

	splitted = ft_split(str, ' ');
	verify_input(splitted);
	//init_stack(values, stack, i);
}

void	init_with_args(t_stack *stack, char **strs, int size)
{
	// TODO: Initialize stack with argv strings
	//init_stack(values, stack, i);
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
