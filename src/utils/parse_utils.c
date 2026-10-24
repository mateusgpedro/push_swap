/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:47:23 by maguimar          #+#    #+#             */
/*   Updated: 2023/07/04 12:16:06 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_atol(const char *str, int *value)
{
	int			sign;
	long long	l_str;

	sign = 1;
	l_str = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			l_str = (l_str * 10) + (*str - '0');
		else
			return (0);
		str++;
	}
	l_str *= sign;
	if (l_str > INT_MAX || l_str < INT_MIN)
		return (0);
	*value = l_str;
	return (1);
}

int	check_duplicates(int *values, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] == values[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_in_subchunk(t_item *item, t_ordered_stack *ordered_stack)
{
	int	i;
	int	chunk_size;

	i = 0;
	if (ordered_stack->current_chunk == ordered_stack->chunks)
		chunk_size = ordered_stack->last_chunk_size;
	else
		chunk_size = ordered_stack->chunk_size;
	while (i < chunk_size / 2)
	{
		if (item->value == ordered_stack->order[i
				+ (ordered_stack->chunk_size
					* ordered_stack->current_chunk - 1)])
			return (1);
		i++;
	}
	return (0);
}
