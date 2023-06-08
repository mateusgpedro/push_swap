/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_diff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:34:05 by maguimar          #+#    #+#             */
/*   Updated: 2023/04/24 16:34:10 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//void	order_chunks(t_ordered_stack *orderedStack)
//{
//	int i;
//	int	j;
//	int	k;
//
//	i = 0;
//	k = 0;
//	while (orderedStack->order[k] != '\0')
//	{
//		j = 0;
//		while (j < 20 || orderedStack->order[k] != '\0')
//		{
//			orderedStack->chunks[i][j] = orderedStack->order[k];
//			j++;
//			k++;
//		}
//		i++;
//		orderedStack->chunks_len++;
//	}
//}

void	diff_elements(t_stack *stackA, t_stack stackB, t_ordered_stack *orderedStack, int chunks)
{
	int	i;
	int	chunk_size;
	int last_chunk_size;

	i = 0;
	chunk_size = stackA->size / chunks;
	last_chunk_size = stackA->size % chunks;
	if (stackA->size % chunk_size != 0)
		chunks++;
	while (stackA->size > 0)
	{

	}
}

int	find_first(t_stack *stack, t_ordered_stack *ordered_stack, int chunk_size, int chunk)
{
	t_item	*item;
	int		i;
	int 	j;

	item = stack->head;
	j = 0;
	while (item->next && j < stack->size / 2)
	{
		i = 0;
		while (i < chunk_size)
		{
			if (item->value == ordered_stack->order[i +(chunk_size * chunk)])
				return i;
			i++;
			j++;
		}
		item = item->next;
	}
	return (-1);
}

int	find_last(t_stack *stack, t_ordered_stack *ordered_stack, int chunk_size, int chunk)
{
	t_item	*item;
	int		i;
	int 	j;

	item = stack->head;
	i = 0;
	while (item->next && i > stack->size / 2)
	{
		j = 0;
		while (j < chunk_size)
		{
			if (item->value == ordered_stack->order[j * chunk])
				return j;
			j++;
			i--;
		}
		item = item->next;
	}
	return (-1);
}

// loop until the end