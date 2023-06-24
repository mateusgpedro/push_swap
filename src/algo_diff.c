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

int	define_hold_position(t_stack *stack, t_ordered_stack *orderedStack, int chunk, int chunks)
{
	if (chunk == chunks)
	{
		orderedStack->hold_first =
				find_first(stack, orderedStack, orderedStack->last_chunk_size, chunk);
		orderedStack->hold_second =
				find_last(stack, orderedStack, orderedStack->last_chunk_size, chunk);
	}
	else
	{
		orderedStack->hold_first =
				find_first(stack, orderedStack, orderedStack->chunk_size, chunk);
		orderedStack->hold_second =
				find_last(stack, orderedStack, orderedStack->chunk_size, chunk);
	}
	if (orderedStack->hold_first == -1 && orderedStack->hold_second == -1)
		return (-1);
	if (orderedStack->hold_first <= (stack->size - orderedStack->hold_second)
        && orderedStack->hold_first != -1) // if return 0 it means hold first is closer to the top than the second
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
    while (item && i < stack->size / 2)
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
    tmp = 0;
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
	if (tmp > 0)
		return (tmp);
	else
		return (-1);
}

void	push_to_other_stack(t_stack *stackA, t_stack *stackB, t_ordered_stack *orderedStack, int chunks)
{
    int	i;

    i = 0;
    //ft_printf("%d\n", chunks);
    while (stackA->size > 0)
    {
        if (i < chunks)
            put_hold_top(stackA, stackB, orderedStack, orderedStack->chunk_size, chunks);
        else if (i == chunks)
            put_hold_top(stackA, stackB, orderedStack, orderedStack->last_chunk_size, chunks);
        i++;
    }
}