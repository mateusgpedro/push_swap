/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:47:23 by maguimar          #+#    #+#             */
/*   Updated: 2023/03/13 14:06:25 by maguimar         ###   ########.fr       */
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
	if (*value > INT_MAX || *value < INT_MIN)
		return (0);
    *value = l_str;
	return (1);
}

int	check_duplicates(int *values, int value)
{
	int i = 0;
	while (values[i] != NULL)
	{
		if (values[i] == value)
			return (0);
		i++;
	}
	return (1);
}
