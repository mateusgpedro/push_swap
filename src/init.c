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
	int		res;
	int		*values;
	int		i;
	int		size;


	splitted = ft_split(str, ' ');
	size = 0;
	while(splitted[size] != NULL)
		size++;
	values = malloc(sizeof(int) * size);
	i = 0;
	while (splitted[i] != NULL)
	{
		res = 0;
		if (ft_atol(splitted[i], &values[i]) == 1 )
			res = 1;
		if (res == 0)
		{
			ft_printf("ERROR");
			free_strs(splitted);
			return ;
		}
		i++;
	}
	init_stack(values, stack, i);
	/* i = 0;
	while(values[i] != '\0')
	{
		ft_printf("%d\n", values[i]);
		i++;
	} */
}

void	init_with_args(t_stack *stack, char **strs, int size)
{
	int	res;
	int *values;
	int	i;

	i = 0;
	values = malloc(sizeof(int) * size);
	while (strs[i + 1] != NULL)
	{
		res = 0;
		if (ft_atol(strs[i + 1], &values[i]) == 1 )
			res = 1;
		if (res == 0)
		{
			ft_printf("ERROR");
			free(values);
			return ;
		}
		i++;
	}
	init_stack(values, stack, i);
	/* i = 0;
	 while(values[i] != '\0')
	{
		ft_printf("%d\n", values[i]);
		i++;
	} */
}

void	init_stack(int *values, t_stack *stack, int size)
{
	int		i;
	t_item	*item;

	i = 0;

	while (i < size)
	{
		item = create_new_item(values[i]);
		push(stack, item);
		i++;
	}
}



/*
	WHAT DEFINES AN INVALID INPUT?

	- DUPLICATES
	- NON NUMERIC INPUT
*/
