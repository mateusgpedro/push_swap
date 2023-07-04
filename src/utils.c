/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:47:23 by maguimar          #+#    #+#             */
/*   Updated: 2023/04/06 13:50:33 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	initialize_ordered_stack(t_stack *stack_a,
			t_ordered_stack *ordered_stack)
{
	t_item	*item;
	int		i;

	i = 0;
	item = stack_a->head;
	ordered_stack->order = NULL;
	ordered_stack->order = malloc(sizeof(int) * stack_a->size);

	ordered_stack->size = 0;
	while (item)
	{
		ordered_stack->order[i] = item->value;
		ordered_stack->size++;
		i++;
		item = item->next;
	}
}

void	ft_sort_int_tab(t_ordered_stack *ordered_stack)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < ordered_stack->size)
	{
		j = 0;
		while (j < ordered_stack->size - 1)
		{
			if (ordered_stack->order[j] > ordered_stack->order[j + 1])
			{
				temp = ordered_stack->order[j];
				ordered_stack->order[j] = ordered_stack->order[j + 1];
				ordered_stack->order[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	check_duplicates(int *values)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (values[i])
	{
		tmp = values[i];
		j = i + 1;
		while (values[j])
		{
			if (tmp == values[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
