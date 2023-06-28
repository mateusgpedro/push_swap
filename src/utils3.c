#include "../includes/push_swap.h"

t_item *find_max(t_stack *stack)
{
	t_item *tmp;
	t_item *value;

	tmp = stack->head;
	value = tmp;
	while (tmp->next)
	{
		if (tmp->next->value > value->value)
			value = tmp->next;
		tmp = tmp->next;
	}
	return (value);
}

t_item *find_min(t_stack *stack)
{
	t_item *tmp;
	t_item *value;

	tmp = stack->head;
	value = stack->head;
	while (tmp->next)
	{
		if (tmp->next->value < value->value && tmp->next != NULL)
			value = tmp->next;
		tmp = tmp->next;
	}
	return (value);
}