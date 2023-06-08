#include "../includes/push_swap.h"

void a_hundred_elements(t_stack *stackA, t_stack *stackB, t_ordered_stack orderedStack, int chunks)
{
	int	chunk_size;
	int last_chunk_size;

	chunk_size = stackA->size / chunks;
	last_chunk_size = stackA->size % chunks;
	if (stackA->size % chunk_size != 0)
		chunks++;

}