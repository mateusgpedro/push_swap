/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:01:00 by maguimar          #+#    #+#             */
/*   Updated: 2023/02/23 14:55:20 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atol(int *status, const char *str)
{
	long long	res;
	int	sign;

	// *value = 0;
	sign = 1;
	// while ((*str >= 8 && *str <= 13) || *str == ' ')
	// 	str++;
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
		{
			return 0;
			break ;
		}
		str++;
	}
	// *value = (int) res;
	*status = 1;
	if (res > INT_MAX || res < INT_MIN)
		*status = 0;

	return (int)res;
}
