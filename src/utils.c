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

int	get_last_element(int *list)
{
	int i;
	int result;

	i = 0;
	while(list[i])
	{
		result = list[i];
		i++;
	}
	return result;
}

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_atol(const char *str, int *value)
{
	int	sign;
	long long l_str;

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
			l_str = l_str * 10 + (*str - '0');
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

int	check_duplicates(int *values, int value)
{
	int	i;

	i = 0;
	while (values[i] != '\0')
	{
		if (values[i] == value)
			return (0);
		i++;
	}
	return (1);
}

// void	ft_sort_int_tab(t_stack *stack)
// {
// 	int	i;
// 	int	j;
// 	int	temp;

// 	i = 0;
// 	while (i < size - 1)
// 	{
// 		j = 0;
// 		while (j < size - 1)
// 		{
// 			if (tab[j] > tab[j + 1])
// 			{
// 				temp = tab[j];
// 				tab[j] = tab[j + 1];
// 				tab[j + 1] = temp;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }
