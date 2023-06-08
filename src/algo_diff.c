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

void	push_from_a(t_stack *stackA, t_stack stackB, t_ordered_stack *orderedStack, int chunks)
{
	int	i;
	int is_hold_top;

	i = 0;
	while (stackA->size > 0)
	{
		while (i < chunks)
		{
			is_hold_top = define_hold_position(stackA, orderedStack, i, chunks);
			if (is_hold_top == 1 )
				rotate(stackA);
			else if (is_hold_top == 0)
				reverse_rotate(stackA);
			else if (is_hold_top == -1)
				exit(EXIT_FAILURE);

			i++;
		}
	}
}

int	define_hold_position(t_stack *stack, t_ordered_stack *orderedStack, int chunk, int chunks)
{
	if (chunk == chunks)
	{
		orderedStack->hold_first =
				find_first(stack, orderedStack, orderedStack->last_chunk_size, chunk);
		orderedStack->hold_last =
				find_last(stack, orderedStack, orderedStack->last_chunk_size, chunk);
	}
	else
	{
		orderedStack->hold_first =
				find_first(stack, orderedStack, orderedStack->chunk_size, chunk);
		orderedStack->hold_last =
				find_last(stack, orderedStack, orderedStack->chunk_size, chunk);
	}
	if (orderedStack->hold_first == -1 && orderedStack->hold_last == -1)
		return (-1);
	if (orderedStack->hold_first <= (100 - orderedStack->hold_last))
		return (1);
	return (0);
}

int	find_first(t_stack *stack, t_ordered_stack *ordered_stack, int chunk_size, int chunk)
{
	t_item	*item;
	int		i;
	int 	j;

	item = stack->head;
	i = 0;
	while (item->next && i < stack->size / 2)
	{
		j = 0;
		while (j < chunk_size)
		{
			if (item->value == ordered_stack->order[j + (chunk_size * chunk)])
				return i;
			j++;
		}
		i++;
		item = item->next;
	}
	return (-1);
}

int	find_last(t_stack *stack, t_ordered_stack *ordered_stack, int chunk_size, int chunk)
{
	t_item	*item;
	int		tmp;
	int		i;
	int		j;

	item = stack->head;
	i = 0;
	while (item->next)
	{
		j = 0;
		while (j < chunk_size)
		{
			if (i > stack->size/2 && item->value == ordered_stack->order[j + (chunk_size * chunk)])
				tmp = i;
			j++;
		}
		i++;
		item = item->next;
	}
	if (i > 0)
		return (i);
	else
		return (-1);
}