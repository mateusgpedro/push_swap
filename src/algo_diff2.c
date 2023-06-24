#include "../includes/push_swap.h"

void put_hold_top(t_stack *stackA, t_stack *stackB, t_ordered_stack *orderedStack, int chunk_size, int chunks)
{
    int is_hold_top;
    int i;

    i = 0;
    while (i < chunk_size)
    {
        is_hold_top = define_hold_position(stackA, orderedStack, i, chunks);
        if (is_hold_top == 1 && stackA->size != 1)
            rotate(stackA, orderedStack->hold_first);
        else if (is_hold_top == 0 && stackA->size != 1)
            reverse_rotate(stackA, stackA->size - orderedStack->hold_second);
        /*else if (is_hold_top == -1)
        {
            ft_printf("Error on put_hold");
            return ;
        }*/
        pb(stackA, stackB);
        i++;
    }
}

void push_back_all(t_stack *stackA, t_stack *stackB)
{
    int pos;

    pos = find_max(stackB);
    while (stackB->size > 0)
    {
        rotate(stackB, pos);
        pa(stackA, stackB);
    }
}