#include "../includes/push_swap.h"

void put_hold_top(t_stack *stackA, t_stack *stackB, t_ordered_stack *orderedStack, int isLast)
{
    int is_hold_top;
    int i;
    int chunk_size;

    i = 0;
    if (isLast)
        chunk_size = orderedStack->last_chunk_size;
    else
        chunk_size = orderedStack->chunk_size;
    while (i < chunk_size)
    {
        is_hold_top = define_hold_position(stackA, orderedStack);
        if (is_hold_top == 1 && stackA->size != 1)
		{
            rotate(stackA, orderedStack->hold_first, STACK_A);
//			if (stackB->size >= 2)
//				rotate(stackB, orderedStack->hold_first, STACK_A);
		}
        else if (is_hold_top == 0 && stackA->size != 1)
		{
			reverse_rotate(stackA, stackA->size - orderedStack->hold_second, STACK_A);
//			if (stackB->size >= 2)
//				reverse_rotate(stackB, stackA->size - orderedStack->hold_second, STACK_A);
		}
        pb(stackA, stackB);
        i++;
    }
}

void push_back_all(t_stack *stackA, t_stack *stackB)
{
	int pos;

	while (stackB->size > 0)
	{
		pos = find_index(stackB, find_max(stackB));
		if (stackB->size == 1)
		{
			pa(stackA, stackB);
			continue;
		}
		else if (pos < stackB->size/2)
			rotate(stackB, pos, STACK_B);
		else
			reverse_rotate(stackB, stackB->size - pos, STACK_B);
		pa(stackA, stackB);
	}
}

int is_in_chunk(t_item *item, t_ordered_stack *orderedStack)
{
    int i;

    i = 0;
    if (orderedStack->current_chunk == orderedStack->chunks)
    {
        while (i < orderedStack->last_chunk_size)
        {
            if (item->value == orderedStack->order[i + (orderedStack->chunk_size * orderedStack->current_chunk - 1)])
                return (1);
            i++;
        }
    }
    else
    {
        while (i < orderedStack->chunk_size)
        {
            if (item->value == orderedStack->order[i + (orderedStack->chunk_size * orderedStack->current_chunk)])
                return (1);
            i++;
        }
    }
    return (0);
}