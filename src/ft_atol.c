/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:01:00 by maguimar          #+#    #+#             */
/*   Updated: 2023/02/23 14:55:57 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atol(int *value, const char *str)
{
	long long	res;
	int	sign;

	// value = 0;
	sign = 1;
	while ((*str >= 8 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			res = res * 10 + (*str - '0');
		else
			return 0;
		str++;
	}
	*value = (int) res;
	if (res > INT_MAX || res < INT_MIN)
		return 0;

	return 1;
}
