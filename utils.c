/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:47:23 by maguimar          #+#    #+#             */
/*   Updated: 2023/02/09 14:43:35 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
