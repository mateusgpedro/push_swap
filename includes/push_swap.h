/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:04:59 by maguimar          #+#    #+#             */
/*   Updated: 2023/02/23 11:29:04 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include "stdlib.h"
#include "../libft/libft.h"
#include "ft_printf.h"

// int i = argc - 1;
// while (i > 1) {						// 3
// 	item = create_new_item(ft_atoi(argv[i]));
// 	/*
// 		item {
// 			val = 3;
// 			next = NULL;
// 		}
// 	*/
// 	push(A, item);
// }

// void pb(t_stack *a, t_stack *b) {
// 	t_item *item;

// 	if (a->size == 0)
// 		return ;
// 	item = a->head;
// 	a->head = a->head->next; // a->head = item->next;
// 	push(b, item);
// }

// void sa()

// push(t_stack *stack, t_item *item)
// {
// 	// if (stack->head==NULL)
// 	if (stack->size == 0)
// 	{
// 		stack->head = item;
// 		item->next = NULL;
// 		stack->size++;
// 		return;
// 	}
// 	item->next = stack->head;
// 	stack->head = item;
// 	stack->size++;
// }

// create_new_item(int val) {
// 	t_item *item;

// 	item = malloc(sizeof(t_item));
// 	item->next = NULL;
// 	item->value = val;
// }

// t_stack *A, *B;

typedef struct s_item
{
	int value;
	struct s_item *next;
}	t_item;

typedef struct s_stack
{
	int size;
	t_item *head;
}				t_stack;

void	init_with_split(t_stack *stack, char *str);
void	init_with_args(t_stack *stack, char **strs);
void	push(t_stack *stack, t_item *item);
void	swap(int *a, int *b);
void	init_stack(int *values, t_stack *stack, int size);
t_item	*create_new_item(int val);
void	free_strs(char **strs);

#endif
