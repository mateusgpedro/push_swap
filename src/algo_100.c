#include "../includes/push_swap.h"

void a_hundred_plus_elements(t_stack *stackA, t_stack *stackB, int chunks)
{
    t_ordered_stack *orderedStack;

    orderedStack = ft_calloc(1, sizeof(t_ordered_stack));
    initialize_ordered_stack(stackA, orderedStack);
    ft_sort_int_tab(orderedStack);
    orderedStack->chunk_size = stackA->size / chunks;
	orderedStack->last_chunk_size = stackA->size % chunks;
	if (stackA->size % orderedStack->chunk_size != 0)
		chunks++;
    push_to_other_stack(stackA, stackB, orderedStack, chunks);
    push_back_all(stackA, stackB);
}